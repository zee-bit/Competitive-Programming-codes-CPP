//Level Order Traversal is also called Breadth First Traversal
#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node *newNode(int data) {
	Node *temp=new Node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

void levelOrder(Node *root) {
	if(root==NULL)
		return;

	queue<Node *> q;
	q.push(root);

	while(!q.empty()) {
		Node *node=q.front();
		cout<<node->data<<" ";
		q.pop();

		if(node->left)
			q.push(node->left);
		if(node->right)
			q.push(node->right);
	}
}
int main() {
	Node *root=newNode(1);
	root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n"; 
    levelOrder(root); 
    return 0;
}