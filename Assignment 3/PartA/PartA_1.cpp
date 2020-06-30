#include <iostream>
using namespace std;

int main() {
	int x;
	int* ptr1 = new int(340);
	int* ptr2 = ptr1;
	delete ptr1;
	delete ptr2;
}
