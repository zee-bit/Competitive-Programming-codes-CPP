/*
Implementation
Here, we'll keep a variable cnt which will keep a record of th number
of elements in the Queue.
*/

#include <iostream>
#include <stdio.h>
using namespace std;
int front = 0, rear = 0, cnt = 0; 

//Checks whether a queue is empty or not
bool isEmpty ( )
{
    if (cnt == 0)  //Queue is empty
        return true ;
    else
        return false;
}

//Adds an element at the rear end of the queue
void enqueue (int queue[ ], int n)
{
    int x;
    if(cnt == n)
        cout << "OverFlow\n";
    else
    {
        cout << "Enter value to be inserted : ";
        cin >> x;
        queue[rear] = x;
        rear = (rear + 1) % n;
        cnt++;
    }
}

//Removes the element at the front end of the queue
void dequeue ( int queue[], int n)
{

    if( isEmpty ( ) )
        cout << "Underflow.\n" ;
    else
    {
        queue[front] = 0;
        front = (front + 1) % n;
        cnt--;
    }
        
}

//Returns the front element of the queue
int Front(int queue[])
{
    return queue[front];
}

//Returns the number of elements in the queue
int size ( )
{
    return cnt;
}

//Displays the Queue
void display(int queue[], int n)
{
    int i;
    cout << "Queue : ";
    if(cnt != 0)
    {
        if(front < rear){
            for(i = front; i < rear; i++)
            {
                cout <<" " << queue[i];
            }
        }
        else{
            for(i = front; i < n; i++)
            {
                cout <<" " << queue[i];
            }
            for(i = 0; i < rear; i++)
            {
                cout <<" " << queue[i];
            }
        }
    }


    cout << endl;
}
int main( )
{
    int queue[5], n = 5;
    int ch;
    while(true){
        cout << "Enter 1.enqueue 2.dequeue 3.front 4.isEmpty 5.size 6.display 7.end : ";
        scanf("%d",&ch);
        if(ch==1){
            enqueue(queue, n);
        }
        else if(ch==2){
            dequeue(queue, n);
        }
        else if(ch==3){
            cout << "Front : "<< Front(queue) << endl;
        }
        else if(ch == 4){
            cout << "Queue is Empty: " << isEmpty() << endl;
        }
        else if(ch == 5){
            cout << "Current size of the Queue is : "  << size ( ) << endl;
        }
        else if(ch == 6){
            display(queue, n);
        }
        else if(ch == 7){
            break;
        }
        else{
            cout << "Wrong choice\n";
        }

    }


}
