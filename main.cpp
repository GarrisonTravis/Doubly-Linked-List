#include <iostream>
#include <exception>
#include "DoublyLinkedList.cpp"

using namespace std;

int main() {
	int arr[5] = { 5, 10, 15, 20, 25 };

	cout << "Testing Doubly Linked List Initialized With An Array:" << endl;
	cout << "-----------------------------------------------------" << endl;
	DoublyLinkedList<int> list1(arr, 5);
	list1.print();
	list1.printReverse();

	cout << "\nTesting Doubly Linked List Initialized With One Value:" << endl;
	cout << "------------------------------------------------------" << endl;
	DoublyLinkedList<int> list4(3);
	list4.print();
	cout << "InsertFront: 2, 1" << endl;
	list4.insertFront(2);
	list4.insertFront(1);
	list4.print();
	cout << "InsertBack: 4, 5" << endl;
	list4.insertBack(4);
	list4.insertBack(5);
	list4.print();

	cout << "\nTesting Doubly Linked List Initialized With Default Constructor (Empty List):" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	DoublyLinkedList<int> list2;
	list2.print();
	cout << "InsertFront: 55, 50, 45, 40, 35" << endl;
	list2.insertFront(55);
	list2.insertFront(50);
	list2.insertFront(45);
	list2.insertFront(40);
	list2.insertFront(35);
	list2.print();
	cout << "Clear The List:" << endl;
	list2.clear();
	list2.print();
	
	cout << "\nTesting Doubly Linked List of Characters:" << endl;
	cout << "-----------------------------------------" << endl;
	DoublyLinkedList<char> list3;
	cout << "InsertBack: B, C, D, E" << endl;
	list3.insertBack('B');
	list3.insertBack('C');
	list3.insertBack('D');
	list3.insertBack('E');
	list3.print();
	cout << "InsertFront: A" << endl;
	list3.insertFront('A');
	list3.print();

	cout << "\nTesting DeleteValue Function:" << endl;
	cout << "-----------------------------" << endl;
	DoublyLinkedList<int> delList;
	delList.insertBack(4);
	delList.insertBack(2);
	delList.insertBack(3);
	delList.insertBack(4);
	delList.insertBack(5);
	delList.print();
	cout << "Delete: 4" << endl;
	delList.deleteValue(4);
	delList.print();
	cout << "Delete: 3" << endl;
	delList.deleteValue(3);
	delList.print();
	delList.printReverse();

	cout << "\nTesting replace function:" << endl;
	cout << "---------------------------" << endl;
	list4.print();
	cout << "Replace index 2 with: 8" << endl;
	list4.replace(8, 2);
	list4.print();
	cout << "Replace index 0 with: 6" << endl;
	list4.replace(6, 0);
	list4.print();
	cout << "Replace index 4 with: 10" << endl;
	list4.replace(10, 4);
	list4.print();
	cout << "Replace index 7 with: 99:" << endl;
	try {
		list4.replace(99, 7);
	}
	catch (exception & e) {
		cout << "Exception Caught! " << e.what() << endl;
	}

	cout << "\nTesting insertAt function:" << endl;
	cout << "----------------------------" << endl;
	list1.print();
	cout << "InsertAt index 0: 3" << endl;
	list1.insertAt(3, 0);
	list1.print();
	cout << "InsertAt index 2: 13" << endl;
	list1.insertAt(13, 3);
	list1.print();
	cout << "InsertAt index 6: 23" << endl;
	list1.insertAt(23, 6);
	list1.print();
}
