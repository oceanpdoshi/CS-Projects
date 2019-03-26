#include "AppleStore.h"
#include <string>
#include<stdexcept>

using namespace std;

namespace cs31 {
	cs31::AppleStore::AppleStore()
	{
	}

	cs31::AppleProduct cs31::AppleStore::buyWatch1(string color)
	{
		return cs31::AppleProduct(AppleProduct::WATCH, "1", color, 249.00);
	}

	cs31::AppleProduct cs31::AppleStore::buyWatch3(string color)
	{
		return cs31::AppleProduct(AppleProduct::WATCH, "3", color, 329.00);
	}

	cs31::AppleProduct cs31::AppleStore::buyiPad(string color, int gigabytes)
	{
		if (gigabytes == 32) {
			return cs31::AppleProduct(AppleProduct::IPAD, "", color, 329.00);
		}
		else if (gigabytes == 128) {
			return cs31::AppleProduct(AppleProduct::IPAD, "", color, 429.00);
		}
		else {
			throw (logic_error("Invalid gigabytes value."));
		}
	}

	cs31::AppleProduct cs31::AppleStore::buyiPadPro(string color, int gigabytes)
	{
		if (gigabytes == 64) {
			return cs31::AppleProduct(AppleProduct::IPAD, "Pro", color, 649.00);
		}
		else if (gigabytes == 256) {
			return cs31::AppleProduct(AppleProduct::IPAD, "Pro", color, 799.00);
		}
		else if (gigabytes == 512) {
			return cs31::AppleProduct(AppleProduct::IPAD, "Pro", color, 999.00);
		}
		else {
			throw(logic_error("Invalid gigabytes value."));
		}
	}

	cs31::AppleProduct cs31::AppleStore::buyiPhoneX(string color, int gigabytes)
	{
		if (gigabytes == 64) {
			return cs31::AppleProduct(AppleProduct::IPHONE, "X", color, 999.00);
		}
		else if (gigabytes == 256) {
			return cs31::AppleProduct(AppleProduct::IPHONE, "X", color, 1149.00);
		}
		else {
			throw(logic_error("Invalid gigabytes value."));
		}
	}

	cs31::AppleProduct cs31::AppleStore::buyiPhone8(string color, int gigabytes)
	{
		if (gigabytes == 64) {
			return cs31::AppleProduct(AppleProduct::IPHONE, "8", color, 699.00);
		}
		else if (gigabytes == 256) {
			return cs31::AppleProduct(AppleProduct::IPHONE, "8", color, 849.00);
		}
		else {
			throw(logic_error("Invalid gigabytes value."));
		}
	}

	cs31::AppleProduct cs31::AppleStore::buyiPhone8Plus(string color, int gigabytes)
	{
		if (gigabytes == 64) {
			return cs31::AppleProduct(AppleProduct::IPHONE, "8Plus", color, 799.00);
		}
		else if (gigabytes == 256) {
			return cs31::AppleProduct(AppleProduct::IPHONE, "8Plus", color, 949.00);
		}
		else {
			throw(logic_error("Invalid gigabytes value."));
		}
	}
}