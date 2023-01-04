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

void addToHead(int);
void deleteFromHead();
void showList();
void delAll();
};

void DoublyLinkedList::addToHead(int el)
{
    if(head != NULL) //if list is not empty
{
    Node* temp=new Node(el);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

else //if list is empty
    head = tail = new Node(el);

Size++;
}

void DoublyLinkedList::deleteFromHead()
{
    if(head == tail) //if only one node in the list
{
    delete head;
    head = tail = NULL;
}
else if(head!=NULL) //if more than one node in the list
{
    Node* temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    delete temp;
}
else if (head==NULL){

    cout<<"there is no node left"<<endl;
}
else cout<<"error";
Size--;

void DoublyLinkedList::showList()
{
Node *temp = head;
int Number = 1;

while(temp!= NULL)
{
    cout<<"Node number : "<<Number<<" is: "<<temp->Info<<endl;
    temp = temp->next;
    Number++;
}
}
void DoublyLinkedList::delAll(){

    Node* Temp = head;
while(Temp != NULL) // Free the memory
{
    head = Temp->next;
    delete Temp;
    Temp = head;
}
}

int main()
{

    DoublyLinkedList obj;
int ele=0;
char op=' ';

cout<<"Enter Item Value: ";
cin>>ele;
cout<<endl;
obj.addToHead(ele);
cout<<"Add another Node (y/n): ";
cin>>op;
while(op!='n'){
    cout<<"Enter Item Value: ";
    cin>>ele;
    obj.addToHead(ele);
    cout<<endl;
    cout<<"Add another Node (y/n): ";
    cin>>op;
}
cout<<endl;
obj.showList();
cout<<"Size of the list is: "<<obj.Size<<endl;
cout<<"After Deletion "<<endl;
obj.deleteFromHead
