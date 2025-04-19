#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	//construtor//
	Node(int value)//prametized construtor which give data avalue
	{
		data = value;
		next = nullptr;
	}
};
class list
{
private:
	Node* head;
public:
	//construtor//it will intilize empty list//
	list()
	{
		head = nullptr;

	}
	//insertion at specific place//
	void insertatspecific(int value, int position)
	{
		Node* newnode = new Node(value);
		if (position <= 0)//if  given position is negetive
		{
			cout << "cannot be inserrt " << endl;
			return;
		}
		//insert at begining
		if (position == 1)
		{
			newnode->next = head;
			head = newnode;
			cout << "insert at begining " << endl;
			return;
		}
		//traversing the list before given position//
		Node* current = head;
		for (int i = 0; i < position - 1 && current != nullptr; i++)
		{
			current = current->next;
		}
		//if position is not in bound
		
		if (current == nullptr) 
		{
			cout << "Position out of bounds.\n";
			delete newnode;
			return;
		}

		// Insert newNode after current node
		newnode->next = current->next;
		current->next = newnode;
		cout << "Inserted at position " << position << ".\n";
	}

	// Delete a node from a specific position (1-based index)
	void deleteatposition(int position)
	{
		if (head == nullptr)
		{
			cout << "List is empty.\n";
			return;
		}

		if (position <= 0) 
		{
			cout << "Position must be >= 1\n";
			return;
		}

		Node* temp;

		// Delete the first node
		if (position == 1) 
		{
			temp = head;
			head = head->next;
			delete temp;
			cout << "Deleted node at position 1.\n";
			return;
		}

		// Traverse to the node before the one to delete
		Node* current = head;
		for (int i = 1; i < position - 1 && current->next != nullptr; i++) 
		{
			current = current->next;
		}

		// If position is invalid
		if (current->next == nullptr) 
		{
			cout << "Position out of bounds.\n";
			return;
		}

		// Delete the node
		temp = current->next;
		current->next = temp->next;
		delete temp;
		cout << "deleted node at position " << position << ".\n";
	}

	// Search for a value in the list
	void searchelement(int value)
	{
		Node* current = head;
		int position = 1;

		// Traverse the list to find the value
		while (current != nullptr)
		{
			if (current->data == value) 
			{
				cout << "element " << value << " found at position " << position <<endl;
				return;
			}
			current = current->next;
			position++;
		}

		// If not found
		cout << "element " << value << "not found" << endl;
	}

	// Count total number of nodes in the list
	int countnodes()
	{
		int count = 0;
		Node* current = head;

		while (current != nullptr) 
		{
			count++;
			current = current->next;
		}

		return count;
	}

	// Display the entire list
	void displaylist() 
	{
		Node* current = head;

		cout << "list: ";
		if (head == nullptr)
		{
			cout << "empty";
			return;
		}

		while (current != nullptr) 
		{
			cout << current->data << " -> ";
			current = current->next;
		}

		cout << "NULL" << endl;
	}
};

// Main function with a menu-driven interface
int main() 
{
    list l1;
	int choice, value, position;

	do 
	{
	
		cout << "\n------ Singly Linked List Menu ------\n";
		cout << "1. Insert node at position\n";
		cout << "2. Delete node at position\n";
		cout << "3. Search for an element\n";
		cout << "4. Count total nodes\n";
		cout << "5. Display list\n";
		cout << "0. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		// Perform action based on user choice
		switch (choice) 
		{
		case 1:
			cout << "enter value and position to insert: ";
			cin >> value >> position;
			l1.insertatspecific(value, position);
			break;

		case 2:
			cout << "enter position to delete: ";
			cin >> position;
			l1.deleteatposition(position);
			break;

		case 3:
			cout << "enter value to search: ";
			cin >> value;
			l1.searchelement(value);
			break;

		case 4:
			cout << "total nodes in list: " << l1.countnodes() << endl;
			break;

		case 5:
			l1.displaylist();
			break;

		case 0:
			cout << "exiting";
			break;

		default:
			cout << "Invalid choice." << endl;
		}

	} while (choice != 6);  // Repeat until user chooses to exit
	system("pause");
	return 0;
}

	