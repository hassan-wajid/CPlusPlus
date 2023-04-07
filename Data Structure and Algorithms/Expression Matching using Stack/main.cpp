#include<iostream> 
#include<string> 
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
}; 

bool checkExpression(string exp){ 
    bool valid=true; 
    stack s; 
    for(int i=0;i<exp.size();i++){ 
        char c=exp[i]; 
        if (c=='('||c=='['||c=='{'){ 
            s.push(c); 
        } 
        if(c==')'||c==']'||c=='}'){ 
            if(s.isEmpty()){ 
                valid=false; 
            } 
            else{ 
                char I=s.pop(); 
                if(I=='('&&c!=')'){ 
                    valid=false; 
                } 
                if(I=='['&&c!=']') 
                    valid=false; 

                if(I=='{'&&c!='}') 
                    valid=false; 
            } 
        } 
    } 
    if(!s.isEmpty()){ 
        valid=false; 
    } 
    return valid; 
} 

int main(){ 
    string exp=" "; 
    char op=' '; 
    while(op!='n'){ 
        cout<<"Enter Expression "<<endl; 
        cin>>exp; 
        if(checkExpression(exp)) 
            cout<<"Expression is Balanced "<<endl; 
        else 
            cout<<"Expression is not Balanced "<<endl; 

        cout<<"Do you Want to Enter Expression (y/n): "; 
        cin>>op; 
    } 
    return 0; 
} 
