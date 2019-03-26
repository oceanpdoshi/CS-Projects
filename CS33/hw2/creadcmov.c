
// If we use -O or -O1 when comipiling with GCC  then this will use a conditional data transfer
// However, if we use gcc -O2 -S creadmove.c, then this will NOT use a conditional data transfer (probably because not a high enough optimization level to impose on GCC).

// I hope that this soln. is sufficient as it does work if we use the -O1 or the -O flag
//  It should work as it should never dereference xp if xp == NULL
// (It can dereference a null pointer if  xp - 1 is null, which in that case is the caller's fault.)

long cread_alt(long * xp) {
  const long  rval = -1;
  return *(xp ? (xp -1) : &rval);
}
