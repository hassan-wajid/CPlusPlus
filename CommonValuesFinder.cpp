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
public:
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
        return pooValue;
	}
	else
		cout << "Queue is Empty \n";


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
	if(first==NULL&&last==NULL){
       return true;

	}else
	return false;
}

Queue::~Queue()
{
	MakeEmpty();
}
 static Node* filter(Node *Q1,Node *Q2){

 Queue Q3;
 if(Q1!=NULL&&Q2!=NULL)
    {



while(Q1!=NULL){

    Node *Iterator=Q2;
    while(Iterator!=NULL){
        if(Q1->value==Iterator->value){
        Q3.Enqueue(Q1->value);

        }
        Iterator=Iterator->next;


    }

    Q1=Q1->next;


}

return Q3.first;
 }else{
 cout<<endl<<"One of the passing Queue is empty"<<endl;
 return NULL;

 }




}

int main()
{
	Queue myQueue;
     Queue myQueue2;
char m='p';
while(m!='n'){
    cout<<"Enter Value for Queue1 :";
    int a;
    cin>>a;
    myQueue.Enqueue(a);
    cout<<"want to enter value for Queue1? y/n  :";
    cin>>m;

}
m='p';
while(m!='n'){
    cout<<"Enter Value for Queue2 :";
    int a;
    cin>>a;
    myQueue2.Enqueue(a);
    cout<<"want to enter value for Queue2? y/n  :";
    cin>>m;

}

  Node *head= filter(myQueue.first,myQueue2.first);


  cout<<"Common values between Q1 ad Q2 are :"<<endl;
Node *temp;
while(head!=NULL){
    cout<<head->value<<endl;
    temp=head;
    head=head->next;
    delete temp;
}
myQueue2.MakeEmpty();
myQueue.MakeEmpty();


}
