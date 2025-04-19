#include<iostream>
#include<string>
using namespace std;
class PatientNode
{
public:
	string name;
	PatientNode* next;
	//construtor//
	PatientNode(string n)//prametized construtor which give data avalue
	{
		name = n;
		next = nullptr;
	}
};
class list
{
private:
	PatientNode* head;
public:
	//construtor//it will intilize empty list//
	list()
	{
		head = nullptr;

	}
	// Add a patient to the end of the list
	void addpatient(string name) 
	{
		PatientNode* newNode = new PatientNode(name);

		if (head == nullptr) 
		{
			head = newNode;
		}
		else 
		{
			PatientNode* current = head;
			while (current->next != nullptr) 
			{
				current = current->next;
			}
			current->next = newNode;
		}

		cout << "patient '" << name << "' added to the list" << endl;
	}

	// Remove a patient from the list by name (if they cancel)
	void removepatient(string name) 
	{
		if (head == nullptr) 
		{
			cout << "List is empty" << endl;
			return;
		}

		PatientNode* current = head;
		PatientNode* previous = nullptr;

		while (current != nullptr && current->name != name)
		{
			previous = current;
			current = current->next;
		}

		if (current == nullptr)
		{
			cout << "patient '" << name << "' not found in the list"<<endl;
			return;
		}

		// Patient found at the head
		if (previous == nullptr) 
		{
			head = head->next;
		}
		else 
		{
			previous->next = current->next;
		}

		delete current;
		cout << "patient '" << name << "' removed from the list" << endl;
	}

	// Display all patients in the list
	void displaylist() 
	{
		if (head == nullptr) 
		{
			cout << "List is empty.\n";
			return;
		}

		cout << "Current patient list " << endl;
		PatientNode* current = head;
		int position = 1;

		while (current != nullptr)
		{
			cout << position << ". " << current->name <<endl;
			current = current->next;
			position++;
		}
	}

	// Count the number of patients in the list
	int countpatients()
	{
		int count = 0;
		PatientNode* current = head;
		while (current != nullptr)
		{
			count++;
			current = current->next;
		}
		return count;
	}
};

// Main function to demonstrate operations
int main() 
{
 list l1;
	int choice;
	string name;

	do {
		cout << "\n===== Hospital Patient List Menu =====\n";
		cout << "1. Add patient to the list\n";
		cout << "2. Remove patient (cancel appointment)\n";
		cout << "3. Display patient list\n";
		cout << "4. Count patients in list\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(); // Clear newline from input buffer

		switch (choice) 
		{
		case 1:
			cout << "enter  name to add: ";
			getline(cin, name);
			l1.addpatient(name);
			break;

		case 2:
			cout << "enter patient's name to remove: ";
			getline(cin, name);
			l1.removepatient(name);
			break;

		case 3:
			l1.displaylist();
			break;

		case 4:
			cout << "total patients in list: " << l1.countpatients() << "\n";
			break;

		case 0:
			cout << "Exiting "<<endl;
			break;

		default:
			cout << "invalid choice. ";
		}
	} while (choice != 6);
	system("pause");
	return 0;
}