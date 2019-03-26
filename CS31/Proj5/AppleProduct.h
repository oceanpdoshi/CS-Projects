#ifndef AppleProduct_h
#define AppleProduct_h

#include <string>
using namespace std;

namespace cs31 {
	class AppleProduct {

	public:
		enum Kind { NOTSPECIFIED, IPHONE, IPAD, WATCH };

		AppleProduct();

		AppleProduct(Kind kind, string version, string color, double cost);

		string getVersion() const;

		string getColor() const;

		Kind getKind() const;

		double getCost() const;


	private:
		string mVersion;
		string mColor;
		Kind mKind;
		double mCost;

	};
}
#endif
