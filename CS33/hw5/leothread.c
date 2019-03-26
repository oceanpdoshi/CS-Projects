// Sagar Doshi
// UID : 604901376
// HW5 - leothread.c

// When compiling, use gcc -pthread -o leothread leothread.c

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread(void *vargp);
int calc_leo(int N);

// Used formula from the wikipedia page linked in the specs to recursively calculated L(N)
int calc_leo(int N) {
  if (N <= 1) {
    return 1;
  }
  return 1 + calc_leo(N-1) + calc_leo(N-2);
}

// Struct to pass arguments using pthread API
struct arg_struct {
  int label;
  int N;
};

int main(int argc, char ** argv) {
  
  // No argument supplied or too many arguments supplied
  if (argc != 2) {
    printf("You didn't supply the correct number of arguments.\n");
    exit(1);
  }
  
  // Use command line argument to get N (STL conversion from string to int), note that argv[0] is the program name, not the argument
  int N = atoi(argv[1]);
  
  // N must be positive
  if (N < 1) {
    printf("N must be positive!\n");
    exit(1);
  }

  // Case where the main (root) thread is in fact a leaf node
  if (N == 1) {
    printf("%d)\n",0);
    exit(0);
  }
 
  // The main thread is considered to be a label of 0

  // Create left and right arguments for threads
  // The left subtree is of order N-1, right subtree is of order N-2
  // The left label is simply T + 1, and the right label is T + 1 + L(k-1) where k is the current level you're at (in this case N)
  struct arg_struct args_left;
  struct arg_struct args_right;

  args_left.N = N-1;
  args_left.label = 1;

  args_right.N = N-2;
  args_right.label = 1 + calc_leo(N-1);

  pthread_t tid_left;
  pthread_t tid_right;

  // Print main label
  printf("[%d]\n", 0);

  /* AMBIGUITY IN SPEC
    Note that the specifications are ambiguous here. It does NOT specify if we have to 
    make the left and right thread and then wait OR
    make the left and wait, make the right and wait. 
    Not doing both threads at the same time kind of defeats the purpose of the parallelism of the threads BUT 
    the actual ordering of the printed statements is more comprehensible as per the spec's pre-order traversal requirement if we do left wait, do right wait.	
  */
  
    //make left thread and wait
    pthread_create(&tid_left, NULL, thread, &args_left);
    pthread_join(tid_left, NULL);

    // make right thread and wait
    pthread_create(&tid_right, NULL, thread, &args_right);
    pthread_join(tid_right,NULL);

  // Print exiting main label  
  printf("%d)\n",0);  

  exit(0);

}

// Thread routine
void *thread(void *vargp) {
  
  // cast void * as arg_sturct * to obtain the arguments 
  struct  arg_struct args;
  args = *(struct arg_struct *) vargp;
  
  int N = args.N;
  int label = args.label;

  // Base case we are at a leaf node because
  // N == 0 || N == 1
  if (N <= 1) {
    printf("%d)\n", label);
    pthread_exit(0);
  }
  
  // create left args
  struct arg_struct args_left;
  args_left.N = N-1;
  args_left.label = label + 1;
  
  // create right args
  struct arg_struct args_right;
  args_right.N = N-2;
  args_right.label = label + 1 + calc_leo(N-1); 

  // Create new thread IDs
  pthread_t tid_left;
  pthread_t tid_right;

  // The process is :
  // Print my own label
  // Make my children threads and wait for them to finish
  // Print my own label as I'm exiting denoted by ')'
  printf("[%d]\n", label);

  pthread_create(&tid_left, NULL, thread, & args_left);
  pthread_join(tid_left, NULL);
 
  pthread_create(&tid_right, NULL, thread, & args_right);
  pthread_join(tid_right, NULL);
 
  printf("%d)\n", label);
  // Exit at the end as we are done.
  pthread_exit(0);
}
