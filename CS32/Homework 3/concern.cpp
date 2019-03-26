//Abstract Class
class Concern {
public:
	Concern(std::string name);

	virtual ~Concern();
	//Subclases will use this, but an object of just Concern will never be initalized so this will be empty

	virtual std::string description() const = 0;
	//Doesn't make sense to have a description for just a concern, need a subclass to implement this
	//This also makes Concern an abstract class

	virtual bool possibleFelony() const;
	//Should only return true if it's an Investigation, otherwise return false.

	std::string person() const; 
	//Every concern has a name and thus this function can be the same for all concerns
	//Should not be able to be modified by subclasses

private:
	std::string m_name;
};

Concern::Concern(std::string name)
{
	m_name = name;
}

Concern::~Concern() {}

std::string Concern::person() const {
	return m_name;
}

bool Concern::possibleFelony() const {
	return false;
}


class EthicsMatter : public Concern {
public:
	EthicsMatter(std::string name);

	virtual ~EthicsMatter();

	virtual std::string description() const;

};

EthicsMatter::EthicsMatter(std::string name) :
	Concern(name)
{
}

EthicsMatter::~EthicsMatter() {
	std::cout << "Destroying " + person() + "'s ethics matter" << std::endl;
}

std::string EthicsMatter::description() const {
	return "An ethics matter";
}

class HushPayment : public Concern{
public: 
	HushPayment(std::string name, int money);

	virtual ~HushPayment();

	virtual std::string description() const;

private:
	int m_money;
};

HushPayment::HushPayment(std::string name, int money) :
	Concern(name), m_money(money)
{
}

HushPayment::~HushPayment() {
	std::cout << "Destroying " + person() + "'s hush payment" << std::endl;
}

std::string HushPayment::description() const {
	return "A $" + std::to_string(m_money) + " payment";
}


class Investigation : public Concern{
public:
	Investigation(std::string name);
	virtual ~Investigation();
	virtual bool possibleFelony() const;
	virtual std::string description() const;
};

Investigation::Investigation(std::string name) :
	Concern(name)
{
}

Investigation::~Investigation() {
	std::cout << "Destroying " + person() + "'s investigation" << std::endl;
}

bool Investigation::possibleFelony() const{
	return true;
}

std::string Investigation::description() const {
	return "An investigation";
}
