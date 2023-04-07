#include <iostream> 
using namespace std; 

struct Character{ 
    char ch; 
    Character* next; 
}; 

class stack{ 
private: 
    int size=-1; 
    Character* top=NULL; 

public: 
    bool isEmpty(){ 
        return (top==NULL); 
    } 

    void push(char el){ 
        Character* ptr=new Character(); 

        ptr->ch=el; 
        ptr->next=top; 
        top=ptr; 
        size++; 
    } 

    char pop(){ 
        char el=top->ch; 
        if(isEmpty()){ 
            cout<<"Stack is empty "<<endl; 
        }else{ 
            Character* ptr=top; 
            top=ptr->next; 
            delete ptr; 
            size--; 
        } 
        return el; 
    } 

    void show(){ 
        if(!isEmpty()){ 
            Character* pt=top; 
            int num=size; 
            cout<<"Items in the stack are: "<<endl; 
            while(pt!=NULL){ 
                cout<<"Node number "<<num<<" is: "<<pt->ch<<endl; 
                pt=pt->next; 
                num--; 
            } 
        }else cout<<"Stack empty "; 
    } 

    void showTop(){ 
        if(!isEmpty()) 
            cout<<"the top element is: "<<top->ch<<endl; 
        else{ 
            cout<<"stack is empty "; 
        } 
    } 
}; 

int main(){ 
    stack s; 
    int ch=0; 
    char chr=' '; 
    do{ 
        cout<<"======Menu====="<<endl; 
        cout << endl << "1: Add Element to Stack"; 
        cout << endl << "2: delete Element from Stack"; 
        cout << endl << "3: view element on top "; 
        cout << endl << "4: exit "; 
        cout << endl << "enter choice: "; 
        cin >> ch; 
        cout<<endl; 
        switch(ch) { 
            case 1: 
                cout<<"Enter character: "; 
                cin>>chr; 
                s.push(chr); 
                s.show(); 
                break; 
            case 2: 
                cout << "data poped is "<<s.pop()<<endl; 
                s.show(); 
                cout<<endl; 
                break; 
            case 3: 
                s.showTop(); 
                break; 
            case 4: 
                exit(0); 
        } 
        cout<<endl; 
    }while(ch!=4); 
    return 0; 
} 
