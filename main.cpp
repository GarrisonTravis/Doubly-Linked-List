#include <iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

int main() {
	int arr[5] = { 5, 10, 15, 20, 25 };
	DoublyLinkedList<int> list1(arr, 5);

	list1.print();
	list1.printReverse();
}
