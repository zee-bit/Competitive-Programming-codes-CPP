#include <iostream>
using namespace std;

#define size 1000

int front = -1;
int rear = -1;
int queue[size];

bool isEmpty()
{
	if(front == -1 && rear == -1)
		return true;
	else 
		return false;
}
void enqueue(int element)
{
	if(rear == size - 1)
		cout<<"Queue Overflow\n";
	else
	{
		if(front == -1)
			front = 0;
		rear++;
		queue[rear] = element;
	}
}
void dequeue()
{
	if(front == -1 && rear == -1)
		cout<<"Queue Underflow\n";
	else if(front == rear)
	{
		cout<<"Queue Underflow\n";
		front = rear = -1;
	}
	else
		front++;
}
void displayQueue()
{
	if(front == -1 && rear == -1)
		cout<<"Queue Underflow\n";
	else
	{
		for(int i = front; i <= rear; i++)
			cout<<queue[i]<<" ";
		cout<<"\n";
	}
}
int main()
{
	enqueue(12);
	enqueue(23);
	enqueue(5);
	enqueue(34);
	dequeue();
	dequeue();
	if(isEmpty())
		cout<<"Empty!!\n";
	else {
		cout<<"Not Empty!!\n";
		displayQueue();
	}
}