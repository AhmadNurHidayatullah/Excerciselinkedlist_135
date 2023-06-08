#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** Nurhidayatullah, Node** Ahmad);
	bool listEmpty();
	bool deleteNode(int rollno);
	void traverse();
	void searchData();
};

void CircularLinkedList::addNode() { //write your answer here
	int Name;
	string nm;
	cout << "\nEnter the rool number of the student: ";
	cin >> Name;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();
	newNode->rollNumber = Name;
	newNode->name = nm;

	if (LAST == NULL || Name <= LAST->rollNumber) {
		if (LAST != NULL && Name == LAST->rollNumber) {
			cout << "\nDuplicate number not alowed" << endl;
			return;
		}
		newNode->next = LAST;
		if (LAST != NULL)
			LAST->next = newNode;
		newNode->next = NULL;
		LAST = newNode;
		return;
	}

	Node* Ahmad = LAST;
	Node* Nurhidayatullah = NULL;
	while (Ahmad->next != NULL && Ahmad->next->rollNumber < Name)
	{
		Nurhidayatullah = Ahmad;
		Ahmad = Nurhidayatullah->next;
	}

	if (Ahmad->next != NULL && Name == Ahmad->next->rollNumber) {
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}

	newNode->next = Ahmad->next;
	newNode->next = Ahmad;
	if (Ahmad->next != NULL)
		Ahmad->next = newNode;
	Ahmad->next = newNode;
}
bool CircularLinkedList::search(int rollno, Node** Nurhidayatullah, Node** Ahmad) {
	*Nurhidayatullah = LAST->next;
	*Ahmad = LAST->next;
	while (*Nurhidayatullah != NULL && rollno != (*Ahmad)->rollNumber) {
		if (rollno == (*Ahmad)->rollNumber) {
			return true;
		}
		*Nurhidayatullah = *Ahmad;
		*Ahmad = (*Ahmad)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::deleteNode(int rollno) { //write your answer here
	Node* Nurhidayatullah, * Ahmad;
	Nurhidayatullah = Ahmad = NULL;
	if (search(rollno, &Nurhidayatullah, &Ahmad) == false)
		return false;
	if (Ahmad->next != NULL)
		Ahmad->next = Nurhidayatullah;
	if (Nurhidayatullah != NULL)
		Nurhidayatullah->next = Ahmad->next;
	else
		LAST = Ahmad->next;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* AhmadNode = LAST->next;
		while (AhmadNode != NULL) {
			cout << AhmadNode->rollNumber << " " << AhmadNode->name << endl;
			AhmadNode = AhmadNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
void CircularLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nList is empty" << endl;


	}
	Node* next, * Ahmad;
	next = Ahmad = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (CircularLinkedList::search(num, &next, &Ahmad) == false)
		cout << "\nrecord not faund" << endl;
	else {
		cout << "\nrecord found" << endl;
		cout << "\nRoll number: " << Ahmad->rollNumber << endl;
		cout << "\nName: " << Ahmad->name << endl;
	}

}


int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': 
				obj.addNode();
				break;
			
			case '2': 
				obj.traverse();
			
			case '3': 
				obj.listEmpty();
				break;
			
			case '4': 
				obj.searchData();
				break;
				return 0;
			
			default: 
				cout << "Invalid option" << endl;
				break;
			
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}

