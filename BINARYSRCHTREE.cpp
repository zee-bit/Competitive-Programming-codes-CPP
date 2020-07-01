#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};
Node* getNewNode(int data) {
	Node *newNode = new Node;
	newNode->data=data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* insert(Node *root, int data) {
	if(root == NULL) {
		root = getNewNode(data);
		return root;
	}
	else if(data <= root->data) {
		root->left = insert(root->left, data);
		return root;
	}
	else {
		root->right = insert(root->right, data);
		return root;
	}
}
bool searchTree(Node *root, int val) {
	if(root == NULL)
		return false;
	if(root->data == val) 
		return true;
	else if(root->data >= val) 
		return searchTree(root->left, val);
	else 
		return searchTree(root->right, val);
}
Node* FindMin(Node *root) {
	if(root->left == NULL)
		return root;
	else
		return FindMin(root->left);
}
Node* deleteNode(Node *root, int data) {
	if(root == NULL) 
		return root;
	else if(data < root->data)
		root->left = deleteNode(root->left, data);
	else if(data > root->data) 
		root->right = deleteNode(root->right, data);
	else {
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if(root->left == NULL) {
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		else {
			Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, data);
		}
		return root;
	}
}
int size(Node *root) {
	if(root==NULL)
		return 0;
	int leftSize=size(root->left);
	int rightSize=size(root->right);
	return leftSize + rightSize + 1;
}
void preOrder(Node *root) {
    if(root==NULL)
        return;
    std::cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root) {
    if(root==NULL)
        return;
    inOrder(root->left);
    std::cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(Node *root) {
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout<<root->data<<" ";
}
// If we are considering height using edges.
int height_edge(Node* root) {
    Node *node=root;
    if (node == NULL)  
        return -1;  
    else
    {  
        int lheight = height_edge(node->left);  
        int rheight = height_edge(node->right);  

        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}
// If considering nodes for height of tree
int height_node(Node *root) {
	if(root==NULL)
		return 0;
	int leftHeight=height_node(root->left);
	int rightHeight=height_node(root->right);
	return leftHeight+rightHeight+1;
}
int findSum(Node *root) {
	if(root==NULL)
		return 0;
	int lsum=root->data+findSum(root->left);
	int rsum=root->data+findSum(root->right);
	return lsum+rsum-root->data;
}
void levelOrder(Node * root) {
    if(root==NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        Node *newNode=q.front();
        q.pop();
        cout<<newNode->data<<" ";
        if(newNode->left)
            q.push(newNode->left);
        if(newNode->right)
            q.push(newNode->right);
    }
}
bool sameTree(Node *root1, Node *root2) {
	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || root2==NULL)
		return false;
	return (root1->data==root2->data 
		&& sameTree(root1->left, root2->left) 
		&& sameTree(root1->right, root2->right));
}
int main() {
	Node *root=NULL;
	root=insert(root, 15);
	root=insert(root, 10);
	root=insert(root, 20);
	root=insert(root, 17);
	root=insert(root, 27);
	root=insert(root, 12);
	root=insert(root, 36);
	if(searchTree(root, 17)==true)
		cout<<"Number found!!"<<"\n";
	else
		cout<<"Number not found!!"<<"\n";
	root=deleteNode(root, 17);
	if(searchTree(root, 17)==true)
		cout<<"Number found!!"<<"\n";
	else
		cout<<"Number not found!!"<<"\n";
	cout<<findSum(root);
}