#include<iostream>
#include<cassert>
#include<string>
#include "AppleProduct.h"
#include "AppleStore.h"

using namespace std;
using namespace cs31;

//This is for testing the .h and .cpp files for AppleProduct and AppleStore
int main() {
	
	//Tests to see if empty constructor for AppleProduct is working
	AppleProduct p;
	assert(p.getCost() == 0.0);
	assert(p.getKind() == AppleProduct::Kind::NOTSPECIFIED);
	assert(p.getColor() == "");
	assert(p.getVersion() == "");

	//Tests to see if non-empty constructor for AppleProduct is working
	AppleProduct p1(cs31::AppleProduct::Kind::IPHONE, "8", "Space Grey", 699.00);
	assert(std::to_string(p1.getCost()) == "699.000000");
	assert(p1.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(p1.getColor() == "Space Grey");
	assert(p1.getVersion() == "8");

	AppleStore store;

	//Tests to see if buying an iphone 8 with valid arguments works
	AppleProduct iphone8_64 = store.buyiPhone8("Space Grey", 64);
	assert(std::to_string(iphone8_64.getCost()) == "699.000000");
	assert(iphone8_64.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphone8_64.getColor() == "Space Grey");
	assert(iphone8_64.getVersion() == "8");

	AppleProduct iphone8_256 = store.buyiPhone8("Space Grey", 256);
	assert(std::to_string(iphone8_256.getCost()) == "849.000000");
	assert(iphone8_64.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphone8_64.getColor() == "Space Grey");
	assert(iphone8_64.getVersion() == "8");

	//Tests to see if buying an iPhone 8Plus with valid arguments works
	AppleProduct iphone8Plus_64 = store.buyiPhone8Plus("Space Grey", 64);
	assert(std::to_string(iphone8Plus_64.getCost()) == "799.000000");
	assert(iphone8Plus_64.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphone8Plus_64.getColor() == "Space Grey");
	assert(iphone8Plus_64.getVersion() == "8Plus");

	AppleProduct iphone8Plus_256 = store.buyiPhone8Plus("Space Grey", 256);
	assert(std::to_string(iphone8Plus_256.getCost()) == "949.000000");
	assert(iphone8Plus_256.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphone8Plus_256.getColor() == "Space Grey");
	assert(iphone8Plus_256.getVersion() == "8Plus");

	//Tests to see if buying an iPhone X with valid arguments works
	AppleProduct iphoneX_64 = store.buyiPhoneX("Space Grey", 64);
	assert(std::to_string(iphoneX_64.getCost()) == "999.000000");
	assert(iphoneX_64.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphoneX_64.getColor() == "Space Grey");
	assert(iphoneX_64.getVersion() == "X");

	AppleProduct iphoneX_256 = store.buyiPhoneX("Space Grey", 256);
	assert(std::to_string(iphoneX_256.getCost()) == "1149.000000");
	assert(iphoneX_256.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphoneX_256.getColor() == "Space Grey");
	assert(iphoneX_256.getVersion() == "X");

	//Tests to see if buying an iPad with valid arguments works
	AppleProduct iPad_32 = store.buyiPad("Space Grey", 32);
	assert(std::to_string(iPad_32.getCost()) == "329.000000");
	assert(iPad_32.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(iPad_32.getColor() == "Space Grey");
	assert(iPad_32.getVersion() == "");

	AppleProduct iPad_128 = store.buyiPad("Space Grey", 128);
	assert(std::to_string(iPad_128.getCost()) == "429.000000");
	assert(iPad_128.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(iPad_128.getColor() == "Space Grey");
	assert(iPad_128.getVersion() == "");

	//Tests to see if buying an iPad Pro with valid arguments works
	AppleProduct iPadPro_64 = store.buyiPadPro("Space Grey", 64);
	assert(std::to_string(iPadPro_64.getCost()) == "649.000000");
	assert(iPadPro_64.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(iPadPro_64.getColor() == "Space Grey");
	assert(iPadPro_64.getVersion() == "Pro");

	AppleProduct iPadPro_256 = store.buyiPadPro("Space Grey", 256);
	assert(std::to_string(iPadPro_256.getCost()) == "799.000000");
	assert(iPadPro_256.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(iPadPro_256.getColor() == "Space Grey");
	assert(iPadPro_256.getVersion() == "Pro");

	AppleProduct iPadPro_512 = store.buyiPadPro("Space Grey", 512);
	assert(std::to_string(iPadPro_512.getCost()) == "999.000000");
	assert(iPadPro_512.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(iPadPro_512.getColor() == "Space Grey");
	assert(iPadPro_512.getVersion() == "Pro");
	
	//Tests to see if buying an iWatch1 or iWatch3 with valid arguments works.

	AppleProduct iWatch1 = store.buyWatch1("Space Grey");
	assert(std::to_string(iWatch1.getCost()) == "249.000000");
	assert(iWatch1.getKind() == cs31::AppleProduct::Kind::WATCH);
	assert(iWatch1.getColor() == "Space Grey");
	assert(iWatch1.getVersion() == "1");

	AppleProduct iWatch3 = store.buyWatch3("Space Grey");
	assert(std::to_string(iWatch3.getCost()) == "329.000000");
	assert(iWatch3.getKind() == cs31::AppleProduct::Kind::WATCH);
	assert(iWatch3.getColor() == "Space Grey");
	assert(iWatch3.getVersion() == "3");

	//Statements to test logic_error throwing/catching

	//iPadPro
	try {
		AppleProduct bad_iPadPro = store.buyiPadPro("blue", 88);
	}
	catch (logic_error) {
		cerr << "Invalid gigabytes for an iPadPro." << endl;
	}

	//iPad
	try {
		AppleProduct badiPad = store.buyiPad("blue", 88);
	}
	catch (logic_error) {
		cerr << "Invalid gigabytes for an iPad." << endl;
	}

	//iPhone8
	try {
		AppleProduct badiPhone8 = store.buyiPhone8("blue", 88);
	}
	catch (logic_error) {
		cerr << "Invalid gigabytes for an iPhone8." << endl;
	}

	//iPhone8Plus
	try {
		AppleProduct badiPhone8Plus = store.buyiPhone8Plus("blue", 88);
	}
	catch (logic_error) {
		cerr << "Invalid gigabytes for an iPhone8Plus." << endl;
	}

	//iPhoneX
	try {
		AppleProduct badiPhone8Plus = store.buyiPhoneX("blue", 88);
	}
	catch (logic_error) {
		cerr << "Invalid gigabytes for an iPhoneX." << endl;
	}

}