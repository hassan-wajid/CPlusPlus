#include <iostream>
using namespace std;

class Node
{
public:
	int Info;
	Node *next, *prev;
	Node(int el, Node *n = NULL, Node *p = NULL)
	{
		Info = el;
		next = n;
		prev = p;
	}
};

class DoublyLinkedList
{
private:
	Node *head, *tail;
	int Size;

public:
	DoublyLinkedList()
	{
		head = tail = NULL;
		Size = 0;
	}

	~DoublyLinkedList();
		
	void addToTail(int);
	int deleteFromTail();
	void deleteNode(int);	
};



void DoublyLinkedList::addToTail(int el)
{
	if(tail != NULL)					//if list is not empty
	{
		tail = new Node(el, NULL, tail);
		tail->prev->next = tail;
	}

	else								//if list is empty
		head = tail = new Node(el);
	
	Size++;
}

int DoublyLinkedList::deleteFromTail()
{
	int el = tail->Info;

	if(head == tail)					//if only one node in the list
	{
		delete head;
		head = tail = NULL;
	}
	else								//if more than one node in the list
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;	
	}

	Size--;

	return el;
}


void DoublyLinkedList::deleteNode(int el)
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
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}

		else										//if more than one node in the list						
		{											//and the node to be deleted is not head
			Node *temp = head;
			
			while((temp != NULL) && (temp->Info != el))
				temp = temp->next;

			if(temp != NULL)						//i.e., the node to be deleted is found
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				
				if(temp == tail)					//i.e., the node to be deleted is the tail
					tail = temp->prev;
				
				delete temp;
			}
		}

		Size--;
	}
}

