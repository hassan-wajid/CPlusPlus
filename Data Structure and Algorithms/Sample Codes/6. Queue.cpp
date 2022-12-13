#include <iostream>

using namespace std;

const int queueSize = 100;

class ArrayQueue
{
private:
	int first, last;	//first and last indexes
	int storage[queueSize];	//a queue of 100 elements

public:
	ArrayQueue()
	{
		first = -1;
		last = -1;
	}

	void enqueue(int);
	int dequeue();
	bool isFull()
	{
		return ((first == 0) && (last == queueSize - 1)	//all the spaces are occupied
			|| (first == last + 1));
	}

	bool isEmpty()
	{
		return (first == -1);
	}
};

void ArrayQueue::enqueue(int el)
{
	if (!isFull())
	{
		if ((last == queueSize - 1) || (last == -1))
		{
			storage[0] = el;
			last = 0;

			if (first == -1)
				first = 0;
		}
		else
			storage[++last] = el;
	}
	else
		cout << "Full Queue. \n";
}

int ArrayQueue::dequeue()
{
	int temp = storage[first];
	if (first == last)
		last = first = -1;
	else if (first == queueSize - 1)
		first = 0;
	else first++;

	return temp;
}

int main()
{
	ArrayQueue queue;

	cout << queue.dequeue() << endl;
	queue.enqueue(5);
	queue.enqueue(4);
	queue.enqueue(3);
	queue.enqueue(6);
	queue.enqueue(8);
	queue.enqueue(9);

	cout << queue.dequeue() << endl;
	queue.enqueue(10);
	queue.enqueue(11);
	queue.enqueue(12);
	queue.enqueue(13);


	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;


}
