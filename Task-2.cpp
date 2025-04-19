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

	//insertatbegining//
	void insertatbegining(int value)
	{
		Node* newnode = new Node(value);//CRETING ANEW NODE
		newnode->next = head;//point thecurrent head
		head = newnode;//updating the head

	}
	//insertat end//
	void insertatend(int value)
	{
		Node *newnode = new Node(value);
		if (head == NULL)//hect if list is empty
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
	////deleteee///
	void deletebyvalue(int value)
	{
		if (head == NULL)
		{
			cout << "list is empty " << endl;
			return;
		}

		if (head->data == value)//if node is delete is head
		{
			Node*temp = head;
			head = head->next;
			delete temp; 
			return;
		}

		Node* temp = head;
		while (temp->next != NULL&&temp->next->data != value)
		{
			temp = temp->next;
		}
		if (temp->next == NULL)
		{
			cout << "value " << value << "not found " << endl;
		}
		else
		{
			Node* nodetodelete = temp->next;
			temp ->next = temp -> next->next;
			delete nodetodelete;
		}
	}
	
	///display//
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
	l1.insertatbegining(4);
	l1.insertatbegining(40);
	l1.insertatend(6);
	l1.insertatend(60);
	cout << "value display " << endl;
	l1.display();
	l1.deletebyvalue(4);
	cout << "list after delete " << endl;
	l1.display();
	system("pause");
	return 0;
}