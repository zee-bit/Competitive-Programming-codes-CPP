#include <iostream>
using namespace std;
#define size 1000

int top = -1;
int stack[size];

void push(int element)
{
	if(top == size - 1)
		cout<<"Stack Overflow";
	else 
	{
		top++;
		stack[top] = element;
	}
}
void pop()
{
	if(top == -1)
		cout<<"Stack Underflow";
	else
		top--;
}
bool isEmpty()
{
	if(top == -1)
		return true;
	else
		return false;
}
void displayStack()
{
	if(top == -1)
	{
		cout<<"Stack Underflow";
	}
	else
	{
		for(int i = 0; i <= top; i++)
			cout<<stack[i]<<" ";
	}
}
int main()
{
	push(12);
	push(1);
	push(37);
	push(7);
	pop();
	displayStack();
	return 0;
}