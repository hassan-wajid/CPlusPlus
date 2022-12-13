#include<iostream>
using namespace std;

const int stackSize = 10;

class ArrayStack
{
private:
	int top;
	int stack[stackSize];

public:
	ArrayStack()
	{
		top = -1;
	}

	void push(int data)
	{
		if (top + 1 == stackSize)
		{
			cout << "\nStack overflow\nCannot enter new data" << endl;
			return;
		}
		top++;
		stack[top] = data;
	}

	int pop()
	{
		int tempVar;
		if (top == -1)
		{
			cout << "\nStack is underflow (Empty)" << endl;
			return -1;
		}
		tempVar = stack[top];

		top--;
		return tempVar;
	}

	void listStack()
	{
		cout << endl << "Stack items are: " << endl;
		for (int i = top; i >= 0; i--)
			cout << stack[i] << endl;
	}

};


int main()
{
	ArrayStack myStack;
	int ch;
	int val;
	do {
		cout << endl << "1. Push to Stack";
		cout << endl << "2: Pop from Stacks";
		cout << endl << "3: Exit";
		cout << endl << "\nEnter Choice: ";
		cin >> ch;

		switch (ch) {
		case 1:
			cout << "\nEnter stack item: ";
			cin >> val;
			myStack.push(val);
			myStack.listStack();
			break;
		case 2:
			cout << "\nData Popped = " << myStack.pop();
			myStack.listStack();
			break;
		case 3:
			exit(0);
		}
	} while (1);
}

