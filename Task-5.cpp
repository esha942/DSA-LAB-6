#include<iostream>
#include<string>
using namespace std;
class ReservationNode
{
public:
	string name;
	int priority;
	ReservationNode* next;
	//construtor//
	ReservationNode(string name, int p) : name(name), priority(p), next(nullptr) {}

};
class ReservationQueue
{
private:
	ReservationNode* head;

	//  function to find and remove a student by name
	ReservationNode* findandremovestudent(string name) 
	{
		ReservationNode* current = head;
		ReservationNode* previous = nullptr;
		while (current != nullptr)
		{
			if (current->name == name)
			{
				if (previous != nullptr) 
				{
					previous->next = current->next;
				}
				else {
					head = current->next;
				}
				ReservationNode* temp = current;
				current = current->next;
				delete temp;
				return current;
			}
			previous = current;
			current = current->next;
		}
		return nullptr;
	}

public:
	ReservationQueue() : head(nullptr) {}

	// Add a student to the reservation queue with optional priority
	void addstudent(string name, int priority) 
	{
		ReservationNode* newnode = new ReservationNode(name, priority);
		if (head == nullptr || head->priority < priority)
		{
			newnode->next = head;
			head = newnode;
		}
		else {
			ReservationNode* current = head;
			while (current->next != nullptr && current->next->priority >= priority) 
			{
				current = current->next;
			}
			newnode->next = current->next;
			current->next = newnode;
		}
		cout << name << " added with priority " << priority << ".\n";
	}

	// Remove a student from the reservation list if they cancel the request
	void removestudent(string name) 
{
		ReservationNode* current = findandremovestudent(name);
		if (current) {
			cout << name << " removed from the reservation list"<<endl;
		}
		else {
			cout << name << " was not found in the reservation list" << endl;
		}
	}

	// Update 
	void updatepriority(string name, int newPriority)
	{
		// First, find and remove the student
		ReservationNode* current = findandremovestudent(name);
		if (current != nullptr) 
		{
			addstudent(name, newPriority);  // Re-add with updated priority
			delete current;
		}
		else {
			cout << name << " not found in the reservation list" << endl;
		}
	}

	// Display 
	void displayreservationlist()
	{
		if (head == nullptr)
		{
			cout << "No students in the reservation list" << endl;
		}
		else
		{
			ReservationNode* current = head;
			while (current != nullptr)
			{
				cout << current->name << " Priority: " << current->priority <<endl;
				current = current->next;
			}
		}
	}

	// Count the number of students 
	int countstudents()
	{
		int count = 0;
		ReservationNode* current = head;
		while (current != nullptr) 
		{
			count++;
			current = current->next;
		}
		return count;
	}

	// Automatically remove 
	void removeFrontStudent()
	{
		if (head == nullptr) 
		{
			cout << "No students to remove, reservation list is empty.\n";
			return;
		}
		ReservationNode* temp = head;
		head = head->next;
		cout << temp->name << " removed from the front of the queue as the book is returned.\n";
		delete temp;
	}

	~ReservationQueue() 
	{
		while (head != nullptr)
		{
			ReservationNode* temp = head;
			head = head->next;
			delete temp;
		}
	}
};

int main() 
{
	ReservationQueue book1, book2;

	// reservation list for book 1
	book1.addstudent("Ali", 3);
	book1.addstudent("Fatima", 2);
	book1.addstudent("Nimra", 4);

	//reservation list for book 2
	book2.addstudent(" Abdullah", 1);
	book2.addstudent("Ayesha", 5);
	book2.addstudent("Frahan", 3);

	// Displaying reservation lists
	cout << "Reservation list for Book 1" << endl;
	book1.displayreservationlist();

	cout << "reservation list for Book 2" << endl;
	book2.displayreservationlist();

	// Removing a student from the reservation list
	book1.removestudent("Fatima");
	cout << "updated reservation list for Book 1"<<endl;
	book1.displayreservationlist();

	// Update a student's priority
	book1.updatepriority("Alice", 5);
	cout << "updated reservation list for Book 1:\n";
	book1.displayreservationlist();
	cout << "number of students in the reservation list for Book 2: " << book2.countstudents() << endl;

	// Removing the front student (book returned)
	book1.removeFrontStudent();
	book2.removeFrontStudent();
	cout << "reservation list for Book 1 after removing front student" << endl;
	book1.displayreservationlist();

	cout << "reservation list for Book 2 after removing front student" << endl;
	book2.displayreservationlist();
	system("pause");
	return 0;
}

