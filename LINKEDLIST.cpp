#include <iostream>
#include <cstdlib>
using namespace std;

struct Node  //wrapping the node inside a structure
{
	int data;  //this will store the data of node
	Node* link;  //this will store the address/link to the next node
};

Node* head = NULL;  //creating head node and specifying the address as NULL

void insertBeg(int d) //inserts node at begining
{
	Node* ptr = new Node(); //creating new node
	ptr->data=d;
	ptr->link=head;
	head=ptr;      //linking ptr to head
}

void insertEnd(int d)
{
	Node* ptr = new Node();
	ptr->data=d;
	ptr->link=NULL;
	if(head==NULL)
		head=ptr;
	else 
	{
		Node* temp=head;
		while(temp->link != NULL)
			temp=temp->link;
		temp->link=ptr;
	}
}

void insertAtN(int d, int n)
{
	Node* ptr = new Node();
	ptr->data=d;
	ptr->link=NULL;
	if(n==1)
	{
		ptr->link=head;
		head=ptr;
		return;
	}
	Node* temp = head;
	for(int i=0;i < n-2; i++) {
		temp = temp->link;
	}
	ptr->link=temp->link;
	temp->link=ptr;
}

void deleteBeg()
{
	if(head == NULL)
		cout<<"List is Empty!!";
	else
	{
		Node *ptr=head;
		head=head->link;
		free(ptr);
	}
}

void deleteEnd()
{
	Node *ptr=head,*prev;
	if(head==NULL)
		cout<<"List is Empty!!";
	else if(head->link==NULL)
	{
		head=NULL;
		free(ptr);
	}
	else 
	{
		while(ptr->link != NULL)
		{
			prev=ptr;
			ptr=ptr->link;
		}
		prev->link=NULL;
		free(ptr);
	}
}

void printMidNode()
{
	Node *slow=head,*fast=head;
	if(head == NULL)
		cout<<"List is Empty!!";
	else
	{
		while(fast != NULL && fast->link != NULL)
		{
			slow=slow->link;
			fast=fast->link->link;
		}
		cout<<"Middle element of node is : "<<slow->data<<"\n";
	}
}

void print()
{
	Node* temp=head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<"\n";		
}

void reverseList()
{
	Node *prev=NULL,*cur=head,*next;
	while(cur != NULL)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
	head=prev;
	print();
}

bool isLoop()    //checking loop exists in the list or not!
{
	bool flag = false;
	Node *slow=head,*fast=head;
	while(fast != NULL && fast->link != NULL)
	{
		fast=fast->link->link;
		slow=slow->link;
		if(slow == fast)
			flag=true;
	}
	return flag;
}

void deleteNodeAt(Node *ptr)  //cant delete the last node using this method
{
	Node *temp=ptr->link;	
	ptr->data=temp->data;
	ptr->link=temp->link;
	free(temp);
}

int main()
{
	insertEnd(7);
	insertEnd(1);
	insertAtN(5,2);
	insertAtN(9,3);
	insertAtN(4,4);
	insertAtN(8,2);
	print();
	Node *ptr=head->link->link->link;
	deleteNodeAt(ptr);
	print();
	printMidNode();
	reverseList();
	return 0;
}

