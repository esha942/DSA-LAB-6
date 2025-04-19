#include<iostream>
using namespace std;
class Node
{
public:
	int data;//data of list
	Node* next;
	Node(int value)
	{
		data = value;
		next = NULL;//construtor
	}
};

class List
{
private:
	Node* head;
public:
	List()
	{
		head = NULL;
	}

	void createnode(int value)
	{
		Node* newnode = new Node(value);
		if (head == NULL)//if array empty head = newnode
		{
			head = newnode;
			return;
		}

		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}

	void display()
	{
		if (head == NULL)
		{
			cout << "The List is Empty" << endl;
			return;
		}

		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main()
{
	List l1;
	l1.createnode(1);
	l1.createnode(2);
	l1.createnode(3);

	l1.display();
	system("pause");
	return 0;
}