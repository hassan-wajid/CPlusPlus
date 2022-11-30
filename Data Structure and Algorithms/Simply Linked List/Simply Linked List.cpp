 #include <iostream> 
 
 using namespace std; 
  struct Node 
 { 
 int value; 
 Node* next; 
 };

  int main() 
 { 
 
 //Question 1 
 Node* HEAD = new Node; 
 char option = ' '; 
 int tempValue = 0; 
 Node* tail = HEAD; 
 cout<<"Question 01"<<endl; 
 cout << "Enter Item Value: " << endl; 
 
 cin >> tempValue; 
 tail->value = tempValue; 
 tail->next=NULL; 
 cout << "Add another (y/n)?"; 
 cin >> option; 
 while (option != 'n') 
 { 
 cout << "Enter Item Value: " << endl; 
 cin >> tempValue; 

 Node* newLink = new Node; 
 tail->next = newLink; 
 newLink->value = tempValue; 
 newLink->next=NULL; 
 
 tail = newLink; 
cout << "Add another (y/n)?"; 
 cin >> option; 
 } 
 
 Node* Temp = HEAD; 
 
 cout<<endl<<endl; 
 cout<<"Printing Values... "<<endl; 
 while (Temp != NULL) // Display the List 
 { 
 cout << "Item's Value is: " << Temp->value << endl; 
 Temp = Temp->next; 
 } 
 
 cout<<endl<<endl<<"Question 02"<<endl; 
 //Question 2 
 cout<<endl<<endl; 
 if (HEAD==tail){ 
 HEAD=tail=NULL; 
 cout<<"No Nodes Left As The Node was only one "<<endl; 
 } 
 else{ 
 
 Temp = HEAD; 
 Node* tail2=NULL; 
 while (Temp-
>next != NULL) // finding the second last node then assigning its next to null 
 { tail2=Temp; // finally then deleting the last node 
 Temp = Temp->next; 
 
 } 
 delete Temp; // deleting the last node 
 tail2->next=NULL; 
 Temp=HEAD; 
 cout<<"Deleting Value From Tail... "<<endl; 
 while (Temp != NULL) // Display the List 
 { 
 cout << "Item's Value is: " << Temp->value << endl; 
 Temp = Temp->next; 
 } 
 } 
 // at last free the memory 
 
 Temp = HEAD; 
 while(Temp != NULL) // Free the memory 
 { 
 HEAD = Temp->next; 
 delete Temp; 
 Temp = HEAD; 
 } 
 return 0; 
 } 
