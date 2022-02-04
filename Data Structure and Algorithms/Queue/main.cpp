#include <iostream>
using namespace std;
  class Node {
public:
int value;
Node* next;

Node(int el, Node* n = NULL)
{
value = el;
next = n;
}

};
  class Queue {
public:
Node* first;
Node* last;

public:
Queue();
~Queue();
void MakeEmpty();
bool IsEmpty();
void Enqueue(int);
void Dequeue();
      void display();
};
  void Queue::Enqueue(int item)
{
Node* newNode = new Node(item);

if (last == NULL)
first = newNode;
else last->next = newNode;

last = newNode;

}
  void Queue::Dequeue()
{
int pooValue = 0;

if (!IsEmpty()
)
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

void Queue::display()
{

Node*temp;
temp=first;
if (temp==NULL)
{
cout<<"Queue Empty."<<endl;

}
else{
while (temp!=NULL)
{
cout<<temp->value<<endl;
temp=temp->next;
}
}
}

Node*filter(Node*q1,Node*q2)
{
Queue q3;
Node* q;
Node* check;
q=q1;
bool tt=true;
while(q!=NULL)
{
if(check->value==q->value)
{
q3.Enqueue(check->value);
 break;
}
check=check->next;
}
q=q->next;
return q3.first;
}



int main()
{
Queue q1;
Queue q2;
Queue third;
char y;
int input,choice;
cout<<"Do you want to add to the queues?Press y to continue."<<endl;
cin>>y;
while(y=='y')
{
cout<<"Press 1 to add to Q1 and 2 to add to Q2"<<endl;
cin>>choice;
cout<<"Enter Number."<<endl;
cin>>input;
if(choice==1)
{
q1.Enqueue(input);
cout<<"Queue 1:"<<endl;
q1.display();
}
if(choice==2)
{
q2.Enqueue(input);
cout<<"Queue 2:"<<endl;
q2.display();
}
cout<<"Want to add a new Number?"<<endl;
cin>>y;
}

Node* temp=third.first;
while(temp!=NULL)
{
cout<<temp->value<<endl;
temp=temp->next;

}

q1.~Queue();
q2.~Queue();

 temp=third.first;
Node *temp2;
while(temp!=NULL)
{
    temp2=temp;
temp=temp->next;
delete temp2;
temp2=temp;

}
return 0;
}

