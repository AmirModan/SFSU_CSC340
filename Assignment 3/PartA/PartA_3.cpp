#include <iostream>
using namespace std;
class Name {
public:
	Name();
	Name(const string&);
	string getName() const;
	void setName(const string&);
private:
	string name{ "" };
};
Name::Name(){}
Name::Name(const string& name) : name(name){}
string Name::getName() const {
	return this->name;
}
void Name::setName(const string& name) {
	this->name = name;
}

int main() {
	unique_ptr<Name> ptr{ make_unique<Name>("Amir") };
	cout << ptr->getName() << endl;
	ptr->setName("CSC340");
	ptr.reset();
	//cout << ptr->getName() << endl; Generates Error
	return 0;
}