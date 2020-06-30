#include <iostream>
using namespace std;
void example() {
	unique_ptr<int> ptr(new int(340));
	cout << ptr.get() << endl;
	//Object stored in ptr will now be deleted
}

int main() {
	example();
	return 0;
}
