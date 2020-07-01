#include <iostream>
#include <stdio.h>
using namespace std;
int top = -1; 

//Insert an element at the top of the Stack
void push (int stack[ ] , int n)
{
    int x;
    if ( top == n-1 )         
    {
        cout << "Stack is full.Overflow condition!\n"  ;
    }
    else
    {
        cout << "Enter value to be inserted : ";
        scanf("%d", &x);
        top = top +1 ;           
        stack[ top ] = x ;       
    }
}

//Checks whether a stack is empty or not
bool isEmpty ( )
{
    if ( top == -1 )  //Stack is empty
        return true ;
    else
        return false;
}

//Delete an element from the top of the stack
void pop ( )
{

    if( isEmpty ( ) )
    {
        cout << "Stack is empty. Underflow condition! \n" ;
    }
    else
    {
            top = top - 1 ; 
    }
}

//Returns the size of the stack
int size ( )
{
    return top + 1;
}

//Returns the element at the top of the stack
int peek (int stack[])
{
    return stack[ top ];
}

//Display the Stack
void display(int stack[])
{
    int i;
    cout << "Stack : ";
    for(i = 0; i<=top; i++)
    {
        cout <<" " << stack[i];
    }
    cout << endl;
}


int main( )
{
    int stack[5], n = 5;
    int ch;
    while(true){
        cout << "Enter 1.push 2.pop 3.peek 4.isEmpty 5.size 6. display 7.end : ";
        scanf("%d",&ch);
        if(ch==1){
            push(stack, n);
        }
        else if(ch==2){
            pop();
        }
        else if(ch==3){
            cout << "Top : "<< peek(stack) << endl;
        }
        else if(ch == 4){
            cout << "Stack is Empty: " << isEmpty() << endl;
        }
        else if(ch == 5){
            cout << "Current size of stack is : "  << size ( ) << endl;
        }
        else if(ch == 6){
            display(stack);
        }
        else if(ch == 7){
            break;
        }
        else{
            cout << "Wrong choice\n";
        }

    }


}
