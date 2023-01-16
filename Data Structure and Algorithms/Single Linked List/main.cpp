#include<iostream> 
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

void Add(int); 
void showList(); 
~IntSLList(); 

int isEmpty() 
{ 
return (head == NULL); 
} 
int LSize() 
{ 
return Size; 
} 
}; 

void IntSLList::showList() 
{ 
IntNode *temp = head; 
while(temp!= NULL) 
{ 
cout<<temp->Info<<endl; 
temp = temp->next; 
} 
} 

void IntSLList::Add(int el){ 

if(head!=NULL){ 
IntNode* newy=new IntNode(el); 

if((head==tail)&&(newy->Info >= head->Info)){ 
head->next=newy; 
tail=newy; 
tail->next=NULL; 
} 
else if((head==tail)&&(newy->Info < head->Info)){ 
newy->next=head; 
head=newy; 
tail->next=NULL; 
} 
else { 
if(newy->Info < head->Info) 
{ 
newy->next=head; 
head=newy; 
} 
IntNode *prev, *temp; 
prev = head; 
temp = head->next; 
while((temp != NULL) && (temp->Info < newy->Info)) 
{ 
prev=prev->next; 
temp=temp->temp; 
} 
prev->next=newy; 
newy->next=temp; 
if(tail->Info<newy->Info){ 
tail->next=newy; 
tail=newy; 
tail->next=NULL; 
} 
} 
}else 
head = tail = new IntNode(el); 

Size++; 

} 
IntSLList::~IntSLList() 
{ 
while(!isEmpty()) 
{ 
IntNode *p = head->next; 
delete head; 
head = p; 
} 
} 

int main(){ 
cout<<"Bob "<<endl<<"CMSID: 45177"<<endl<<endl<<"Question 01"<<endl;
IntSLList List; 

 int value=0; 
 char op=' '; 
 cout<<"Enter the item value: "; 
 cin>>value; 
 List.Add(value); 
 
 cout<<"do you want to add node: "; 
 cin>>op; 
 while(op!='n'){ 
 cout<<"Enter the item value: "; 
 cin>>value; 
 List.Add(value); 
 cout<<endl; 
 List.showList(); 
 cout<<endl; 
 cout<<"do you want to add node: "; 
 cin>>op; 
 } 
 cout<<endl<<endl; 
 List.showList(); 
 List.~IntSLList(); 
 
 return 0; 
 } 

