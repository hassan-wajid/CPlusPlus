#include <iostream>
using namespace std;

class IntNode
{
public:
	int Info;
	IntNode* next;
	
	IntNode(int el, IntNode *ptr = NULL)
	{
		Info = el;
		next = ptr;
	}
};

class IntSLList
{
private:
	IntNode *head, *tail;
	int Size;

public:
	IntSLList()
	{
		head = tail = NULL;
		Size = 0;
	}

	~IntSLList();

	int isEmpty()
	{
		return (head == NULL);		
	}

	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int);
	bool isInList(int);

	void showList();

	int LSize()
	{
		return Size;
	}
};



IntSLList::~IntSLList()
{
	//Destructor is very important when deallocating the dynamic memory
	while(!isEmpty())
	{
		IntNode *p = head->next;
		delete head;
		head = p;
	}
}


void IntSLList::addToTail(int el)
{
	if(tail != NULL)					//if list is not empty
	{
		tail->next = new IntNode(el);
		tail = tail->next;
	}

	else head = tail = new IntNode(el); //if list is empty

	Size++;
}


int IntSLList::deleteFromHead()
{
	int el = head->Info;
	IntNode *temp = head;

	if(head == tail)					//if there is only one node in the list
		head = tail = NULL;
	else
		head = head->next;

	delete temp;

	Size--;

	return el;
}

int IntSLList::deleteFromTail()
{
	int el = tail->Info;

	if(head == tail)					//if only one node in the list
	{
		delete head;
		head = tail = NULL;
	}
	else
	{
		IntNode *temp = head;
		
		while(temp->next != tail)		//reach the second last node
			temp = temp->next;
		
		delete tail;
		tail = temp;
		tail->next = NULL;	
	}

	Size--;

	return el;
}


void IntSLList::deleteNode(int el)
{
	if(head != NULL)					//if the list is not empty
	{
		if((head == tail) && (el == head->Info))	//if only one in the list
		{
			delete head;
			head = tail = NULL;
		}
		
		else if(el == head->Info)					//if more than one node in the list			
		{											//and the node to be deleted is head
			IntNode *temp = head;
			head = head->next;
			delete temp;
		}

		else										//if more than one node in the list						
		{											//and the node to be deleted is not head
			IntNode *prev, *temp;
			prev = head;
			temp = head->next;

			while((temp != NULL) && (temp->Info != el))
			{
				prev = prev->next;
				temp = temp->next;
			}

			if(temp != NULL)						//i.e., the node to be deleted is found
			{
				prev->next = temp->next;

				if(temp == tail)					//i.e., the node to be deleted is the tail
					tail = prev;
				
				delete temp;
			}
		}

		Size--;
	}
}


bool IntSLList::isInList(int el)
{
	IntNode *temp = head;

	while((temp != NULL) && (temp->Info != el))
		temp = temp->next;

	return temp != NULL;
}

void IntSLList::showList()
{
	IntNode *temp = head;
	int Number = Size;

	while(temp!= NULL)
	{
		cout<<"Node number : "<<Number<<" is: "<<temp->Info<<endl;
		temp = temp->next;
		Number--;
	}
}


int main()
{
	IntSLList List;

	List.addToHead(7);
	List.addToTail(3);
	List.addToTail(4);
	List.addToHead(9);

	List.showList();

	List.deleteNode(7);

	List.showList();


	
	List.addToHead(45);
	List.addToTail(24);
	List.showList();

	cout<<"List size is : "<<List.LSize()<<endl;

	List.deleteFromHead();
	List.addToTail(12);
	List.addToHead(66);
	List.addToTail(-9);
	List.addToHead(85);
	List.addToTail(356);

	cout<<"List size is : "<<List.LSize()<<endl;
	List.showList();

	List.deleteFromTail();
	cout<<"List size is : "<<List.LSize()<<endl;
	List.showList();

	List.deleteNode(-9);
	cout<<"List size is : "<<List.LSize()<<endl;
	List.showList();
	
}
