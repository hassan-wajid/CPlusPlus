#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;
};

int main()
{
	Node* HEAD = NULL;
	char option = 'y';
	int tempValue = 0;
	
	while(option != 'n')
	{
		cout << "Enter Item Value: " <<  endl;
		cin >> tempValue;
		
		Node* newLink = new Node;
		newLink->value = tempValue;
		newLink->next = HEAD;
		
		HEAD = newLink;
		cout << "Add another (y/n)?";
		cin >> option;
	}
	
	Node* Temp = HEAD;
	while(Temp != NULL)  // Display the List
	{
		cout << "Item's Value is: " << Temp->value << endl;
		Temp = Temp->next;
	}
	
	Temp = HEAD;
	while(Temp != NULL)  // Free the memory
	{
		HEAD = Temp->next;
		delete Temp;
		Temp = HEAD;
	}
	
	return 0;
}
