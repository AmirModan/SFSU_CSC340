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

string isDangling(bool exp) {
	if (!exp) {
		return " not ";
	}
	return " ";
}

int main() {
	shared_ptr<Name> sharedPtr{ make_shared<Name>("Amir") };
	weak_ptr<Name> weakPtr{ sharedPtr };
	cout << "Weak pointer is" << isDangling(weakPtr.expired()) << "expired" << endl;
	sharedPtr.reset();
	cout << "Shared pointer is reset" << endl;
	cout << "Weak pointer is" << isDangling(weakPtr.expired()) << "expired" << endl;
	return 0;
}