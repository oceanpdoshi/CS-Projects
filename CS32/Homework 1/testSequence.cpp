//For testing sequence


//ALL TESTS PASSED FOR STRINGS!!!! :D
//ALL TESTS PASSED FOR UNSIGNED LONG!!! :D
//int main() {
	////////////////////STRING TESTING////////////////////////////////
	////Initializes a filled up Sequence object for later testing
	//Sequence full; 
	//for (int i = 0; i < DEFAULT_MAX_ITEMS; i++) {
	//	full.insert(i, "full");
	//}

	////Checking insert(pos, value);
	//Sequence a;
	//assert(a.empty() == true);
	//a.insert(0, "A");
	//assert(a.empty() == false);
	//a.insert(1, "B");
	//a.insert(2, "C");
	//a.insert(3, "D");
	//a.insert(0, "A");
	//a.insert(0, "Fencepost Error Check");
	//a.insert(4, "Insert logic Check");
	//assert(a.insert(-1, "Should be False") == false);
	//assert(a.insert(200, "Should be False") == false);
	//assert(a.insert(20, "should be false") == false);
	//Sequence almost_full;
	//for (int i = 0; i < DEFAULT_MAX_ITEMS - 1; i++) {
	//	almost_full.insert(i, "full");
	//}
	//assert(almost_full.insert(199, "should be true") == true);
	//assert(full.insert(5, "should be false") == false);

	////Checking insert(value);
	//Sequence b;
	//assert(b.insert("A") == true);
	//assert(full.insert("Should be false") == -1);
	//b.insert("B");
	//b.insert("C");
	//b.insert(3, "E");
	//b.insert("D");
	//b.insert("A");
	//b.insert("B");
	////b.dump();

	////Checking erase(pos);
	//Sequence c;
	//c.insert("A");
	//c.insert("B");
	//c.insert("C");
	//c.insert("D");
	////c.dump();

	//assert(c.erase(0) == true);
	//assert(c.erase(10) == false);
	////c.dump();
	//assert(c.erase(1) == true);
	////c.dump();
	//assert(c.erase(1) == true);
	////c.dump();

	////Checking remove
	//Sequence d;
	//d.insert("A");
	//d.insert("B");
	//d.insert("C");
	//d.insert("C");
	//d.insert("D");
	////d.dump();

	//assert(d.remove("C") == 2);
	////d.dump();

	//Sequence e;
	//e.insert("A");
	//e.insert("B");
	//e.insert("C");
	//e.insert("D");
	//e.insert("D");
	//e.insert("D");
	//assert(e.remove("D") == 3);
	////e.dump();

	//Sequence f;
	//f.insert("A");
	//f.insert("A");
	//f.insert("A");
	//f.insert("B");
	//f.insert("C");
	//assert(f.remove("A") == 3);
	////f.dump();

	////Testing of get()

	//Sequence g; 
	//g.insert("A");
	//g.insert("B");
	//g.insert("C");
	////g.dump();


	//assert(g.get(0, str) == true && str == "A");
	//assert(g.get(1, str) == true && str == "B");
	//assert(g.get(2, str) == true && str == "C");
	//assert(g.get(4, str) == false); 
	//
	////Testing of set()

	//Sequence h;
	//h.insert("A");
	//h.insert("B");
	//h.insert("C");

	//assert(h.set(0, "C") == true);
	//assert(h.set(1, "A") == true);
	//assert(h.set(2, "B") == true);
	////h.dump();
	//assert(h.set(5, "ayy") == false);

	////Testing of find()

	//Sequence i;
	//i.insert("A");
	//i.insert("A");
	//i.insert("B");
	//i.insert("C");

	//assert(i.find("A") == 0);
	//assert(i.find("B") == 2);
	//assert(i.find("C") == 3);
	//assert(i.find("invalid") == -1);

	////Testing of swap() 

	//Sequence lower_case;
	//lower_case.insert("a");
	//lower_case.insert("b");
	//lower_case.insert("c");
	//lower_case.insert("d");
	//lower_case.insert("e");

	//Sequence upper_case;
	//upper_case.insert("A");
	//upper_case.insert("B");
	//upper_case.insert("C");
	//upper_case.insert("D");
	//upper_case.insert("E");

	//lower_case.swap(upper_case);
	//
	//std::cerr << "lower_case" << std::endl;
	//lower_case.dump();

	//std::cerr << "upper_case" << std::endl;
	//upper_case.dump();

//#include "Sequence.h"
//#include <iostream>
//#include <cassert>
//int main() {
//	//Initializes a filled up Sequence object for later testing
//Sequence full;
//for (int i = 0; i < DEFAULT_MAX_ITEMS; i++) {
//	full.insert(i, 1);
//}
//
////Checking insert(pos, value);
//Sequence a;
//assert(a.empty() == true);
//a.insert(0, 1);
//assert(a.empty() == false);
//a.insert(1, 2);
//a.insert(2, 3);
//a.insert(3, 4);
//a.insert(0, 1);
//a.insert(0, 1);
//a.insert(4, 1);
//assert(a.insert(-1, 1) == false);
//assert(a.insert(200, 1) == false);
//assert(a.insert(20, 1) == false);
//
//Sequence almost_full;
//for (int i = 0; i < DEFAULT_MAX_ITEMS - 1; i++) {
//	almost_full.insert(i, 1);
//}
//assert(almost_full.insert(199, 1) == true);
//assert(full.insert(5, 1) == false);
//
////Checking insert(value);
//Sequence b;
//assert(b.insert(1) == true);
//assert(full.insert(1) == -1);
//b.insert(2);
//b.insert(3);
//b.insert(3, 4);
//b.insert(5);
//b.insert(1);
//b.insert(2);
////b.dump();
//
////Checking erase(pos);
//Sequence c;
//c.insert(1);
//c.insert(2);
//c.insert(3);
//c.insert(4);
////c.dump();
//
//assert(c.erase(0) == true);
//assert(c.erase(10) == false);
////c.dump();
//assert(c.erase(1) == true);
////c.dump();
//assert(c.erase(1) == true);
////c.dump();
//
////Checking remove
//Sequence d;
//d.insert(1);
//d.insert(2);
//d.insert(3);
//d.insert(3);
//d.insert(5);
////d.dump();
//
//assert(d.remove(3) == 2);
////d.dump();
//
//Sequence e;
//e.insert(1);
//e.insert(2);
//e.insert(3);
//e.insert(4);
//e.insert(4);
//e.insert(4);
//assert(e.remove(4) == 3);
////e.dump();
//
//Sequence f;
//f.insert(1);
//f.insert(1);
//f.insert(1);
//f.insert(2);
//f.insert(3);
//assert(f.remove(1) == 3);
////f.dump();
//
////Testing of get()
//
//Sequence g;
//g.insert(1);
//g.insert(2);
//g.insert(3);
////g.dump();
//
//
////assert(g.get(0, str) == true && str == 1);
////assert(g.get(1, str) == true && str == "B");
////assert(g.get(2, str) == true && str == "C");
////assert(g.get(4, 4) == false);
//
////Testing of set()
//
//Sequence h;
//h.insert(1);
//h.insert(2);
//h.insert(3);
//
//assert(h.set(0, 3) == true);
//assert(h.set(1, 1) == true);
//assert(h.set(2, 2) == true);
////h.dump();
//assert(h.set(5, 0) == false);
//
////Testing of find()
//
//Sequence i;
//i.insert(1);
//i.insert(1);
//i.insert(2);
//i.insert(3);
//
//assert(i.find(1) == 0);
//assert(i.find(2) == 2);
//assert(i.find(3) == 3);
//assert(i.find(69) == -1);
//
////Testing of swap() 
//
//Sequence lower_case;
//lower_case.insert(1);
//lower_case.insert(2);
//lower_case.insert(3);
//lower_case.insert(4);
//lower_case.insert(5);
//
//Sequence upper_case;
//upper_case.insert(6);
//upper_case.insert(7);
//upper_case.insert(8);
//upper_case.insert(9);
//upper_case.insert(10);
//
//lower_case.swap(upper_case);
//
///*std::cerr << "lower_case" << std::endl;
//lower_case.dump();
//
//std::cerr << "upper_case" << std::endl;
//upper_case.dump();*/
//
//}

//#include "Sequence.h"
//#include <string>
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//	Sequence s;
//	assert(s.insert(0, "lavash"));
//	assert(s.insert(0, "tortilla"));
//	assert(s.size() == 2);
//	ItemType x = "injera";
//	assert(s.get(0, x) && x == "tortilla");
//	assert(s.get(1, x) && x == "lavash");
//}
//
//int main()
//{
//	test();
//	cout << "Passed all tests" << endl;
//}

//#include "Sequence.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//	Sequence s;
//	assert(s.insert(0, 10));
//	assert(s.insert(0, 20));
//	assert(s.size() == 2);
//	ItemType x = 999;
//	assert(s.get(0, x) && x == 20);
//	assert(s.get(1, x) && x == 10);
//}
//
//int main()
//{
//	test();
//	cout << "Passed all tests" << endl;
//}

int main() {}

