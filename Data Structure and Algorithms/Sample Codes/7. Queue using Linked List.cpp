#include <iostream>
using namespace std;
  
class Node
{
public:
	int value;
	Node* next;

	Node(int el, Node* n = NULL)
	{
		value = el;
		next = n;
	}
};
  
class Queue
{
private:
	Node* first;
	Node* last;

public:
	Queue();
	~Queue();
	void MakeEmpty();
	bool IsEmpty();
	void Enqueue(int);
	int Dequeue();
};
  
void Queue::Enqueue(int item)
{
	Node* newNode = new Node(item);

	if (last == NULL)
		first = newNode;
	else
		last->next = newNode;

	last = newNode;
}
  
int Queue::Dequeue()
{
	int pooValue = 0;

	if (!IsEmpty())
	{
		Node* tempPtr;
		tempPtr = first;

		pooValue = first->value;
		first = first->next;

		if (first == NULL)
			last = NULL;

		delete tempPtr;
	}
	else
		cout << "Queue is Empty \n";

	return pooValue;
}

Queue::Queue()
{
	first = last = NULL;
}
  
void Queue::MakeEmpty()
{
	Node* tempPtr;

	while (first != NULL)
	{
		tempPtr = first;
		first = first->next;

		delete tempPtr;
	}
	last = NULL;
}

bool Queue::IsEmpty()
{
	return (first == NULL);
}
  
Queue::~Queue()
{
	MakeEmpty();
}
 
void main()
{
	Queue myQueue;

	myQueue.Enqueue(2);
	myQueue.Enqueue(3);
	myQueue.Enqueue(10);
	myQueue.Enqueue(1);
	myQueue.Enqueue(5);
	myQueue.Enqueue(2);
	myQueue.Enqueue(-1);

	cout << myQueue.Dequeue() << endl;
	cout << myQueue.Dequeue() << endl;


}
