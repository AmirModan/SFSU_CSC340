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
	unique_ptr<Name> uniquePtr{ make_unique<Name>("Amir") };
	cout << "Unique Pointer: " << uniquePtr << endl;
	shared_ptr<Name> sharedPtr{ move(uniquePtr) };
	cout << "Pointer is now shared" << endl;
	cout << "Unique Pointer: " << uniquePtr << endl;
	cout << "Shared Pointer: " << sharedPtr << endl;
	
	return 0;
}