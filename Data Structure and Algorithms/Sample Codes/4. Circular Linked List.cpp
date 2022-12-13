#include <iostream>
using namespace std;

class Node
{
public:
	int Info;
	Node* next;
	Node(int el, Node *ptr = NULL)
	{
		Info = el;
		next = ptr;
	}
};

class IntCLList
{
private:
	Node *tail;
	int Size;

public:
	IntCLList()
	{
		tail = NULL;
		Size = 0;
	}

	~IntCLList();

	int isEmpty()
	{
		return (tail == NULL);		
	}

	void addToTail(int);
	int deleteNode(int);
	void showList();	
};



IntCLList::~IntCLList()
{
	//Destructor is very important when deallocating the dynamic memory
	while(!isEmpty())
	{
		if(tail == tail->next)	//Only one node in the list
		{
			delete tail;
			tail = NULL;
			Size--;
			continue;
		}

		Node *temp = tail->next;
		tail->next = temp->next;
		delete temp;

		Size--;
	}
}

void IntCLList::addToTail(int el)
{
	if(isEmpty())					//if list is empty
	{
		tail = new Node(el);
		tail->next = tail;
	}
	else
	{
		Node* temp = new Node(el, tail->next);
		tail->next = temp;
		tail = temp;
		
	}
	Size++;
}


int IntCLList::deleteNode(int el)
{
	Node* temp = tail;

	if(!isEmpty())
	{
		if((tail == tail->next) && (el == tail->Info))	//if only one node in the list
		{
			delete tail;
			tail = NULL;

			Size--;

			return el;
		}
		else if(tail->Info == el)						//the node to be deleted is tail
		{
			Node *temp = tail;

			while(temp->next != tail)
				temp = temp->next;

			temp->next = tail->next;
			delete tail;
			tail = temp;

			Size--;

			return el;
		}
		else
		{
			Node *prev, *temp;
			temp = tail->next;
			prev = tail;

			while((temp->next != tail) && (temp->Info != el))
			{
				prev = prev->next;
				temp = temp->next;
			}

			prev->next = temp->next;
			delete temp;
			
			Size--;

			return el;
		}
	}

	return -1;
}

void IntCLList::showList()
{
	Node *temp = tail->next;
	while(temp != tail)
	{
		cout<<temp->Info<<endl;
		temp = temp->next;		
	}
	cout<<"tail is :"<<temp->Info<<endl;	
}


void main()
{
	IntCLList List;

	List.addToTail(7);
	List.addToTail(3);
	List.addToTail(4);
	List.addToTail(9);
	
	List.showList();	

	cout<<"Deleted : "<<List.deleteNode(9)<<endl;
	List.showList();


	
}