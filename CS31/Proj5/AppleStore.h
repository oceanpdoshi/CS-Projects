#ifndef AppleStore_h
#define AppleStore_h
#include "AppleProduct.h"
#include <string>

using namespace std;
namespace cs31 {

	class AppleStore {
	public:
		
		AppleStore();

		cs31::AppleProduct buyWatch1(string color);
		cs31::AppleProduct buyWatch3(string color);

		cs31::AppleProduct buyiPad(string color, int gigabytes);
		cs31::AppleProduct buyiPadPro(string color, int gigabytes);

		cs31::AppleProduct buyiPhoneX(string color, int gigabytes);
		cs31::AppleProduct buyiPhone8(string color, int gigabytes);
		cs31::AppleProduct buyiPhone8Plus(string color, int gigabytes);

	private:


	};
}
#endif
