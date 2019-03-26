#include "AppleProduct.h"
#include <string>

using namespace std;

namespace cs31 {
	AppleProduct::AppleProduct()
	{
		mKind = NOTSPECIFIED;
		mVersion = "";
		mColor = "";
		mCost = 0.0;
	}

	AppleProduct::AppleProduct(Kind kind, string version, string color, double cost)
	{
		mKind = kind;
		mVersion = version;
		mColor = color;
		mCost = cost;
	}

	string AppleProduct::getVersion() const
	{
		return mVersion;
	}

	string AppleProduct::getColor() const
	{
		return mColor;
	}

	AppleProduct::Kind AppleProduct::getKind() const
	{
		return mKind;
	}

	double AppleProduct::getCost() const
	{
		return mCost;
	}
}