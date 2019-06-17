#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int data){
		val = data;
		left = NULL;
		right = NULL;
	}
};
void createBT(Node** root,int arr[],int len,int index = 0)
{
	if(index>len-1 || arr[index] == -1)
		return ;
	(*root) = new Node(arr[index]);
	createBT(&((*root)->left),arr,len,2*index+1);
	createBT(&((*root)->right),arr,len,2*index+2);
}
void preOrderRecur(Node* head)
{
	if (head == NULL)
		return ;
	cout<<head->val<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
	
 }
void inOrderRecur(Node* head)
{
	if (head == NULL)
		return ;

	inOrderRecur(head->left);
	cout<<head->val<<" ";
	inOrderRecur(head->right);
	
 }
 void posOrderRecur(Node* head)
{
	if (head == NULL)
		return ;
	posOrderRecur(head->left);
	posOrderRecur(head->right);
	cout<<head->val<<" ";
 }
 void morrisPre(Node* root)
 {
 	if(root == NULL)
 		return ;
 	Node* cur = root;
	Node* mostRight = NULL;
	while(cur != NULL)
	{
		mostRight =cur->left;
		if(mostRight != NULL)
		{
			while(mostRight->right != NULL && mostRight->right != cur)
				mostRight = mostRight->right;
			if(mostRight->right == NULL)
			{
				mostRight->right = cur;
				cout<<cur->val<<" ";//可以到达两次的节点第一次到达打印 
				cur = cur->left;
				continue;
			}
			else 
			{
				mostRight->right = NULL;				
			}
	   }
	   else 
	   	cout<<cur->val<<" ";//无左子树的节点第一次到达时打印 
	   cur = cur->right;
	 } 
 } 
 void morrisIn(Node* root)
 {
 	if(root == NULL)
 		return ;
 	Node* cur = root;
	Node* mostRight = NULL;
	while(cur != NULL)
	{
		mostRight =cur->left;
		if(mostRight != NULL)
		{
			while(mostRight->right != NULL && mostRight->right != cur)
				mostRight = mostRight->right;
			if(mostRight->right == NULL)
			{
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else
			{
				cout<<cur->val<<" ";
				mostRight->right = NULL;
				
			}
	 	} 
		 else
		 	cout<<cur->val<<" ";
	 	cur = cur->right;
	}
 }
 Node* reverseEdge(Node* head)
 {
 	Node* pre = NULL;
 	Node* next = NULL;
 	while(head != NULL)
	 {
	 	next = head->right;
	 	head->right = pre;
	 	pre = head;
	 	head = next;
	  } 
	  return pre;
 }
 void printEdge(Node* head)
 {
 	Node* tail = reverseEdge(head);
 	Node* cur = tail;
 	while(cur!= NULL)
 	{
 		cout<<cur->val<<" ";
 		cur = cur->right;
	 }
	 reverseEdge(tail);
 }
 void morrisPos(Node* root)
 {
 	if(root == NULL)
 		return ;
 	Node* cur = root;
 	Node* mostRight = NULL;
 	while(cur != NULL)
 	{
 		mostRight = cur->left;
 		if(mostRight != NULL)
 		{
 			while(mostRight->right != NULL && mostRight->right != cur)
 				mostRight = mostRight->right;
 			if(mostRight->right == NULL)
 			{
 				mostRight->right = cur;
 				cur = cur->left;
 				continue;
			 }
			 else
			 {
			 	mostRight->right = NULL;
			 	printEdge(cur->left);
			 }		
		}
		cur = cur->right;	
		
	 }
 	printEdge(root);
 }
int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	Node* root = NULL;
	createBT(&root,arr,7);
	cout<<"递归前序遍历：";
	preOrderRecur(root);
	cout<<endl;
	cout<<"Morris前序遍历：";
	morrisPre(root);
	cout<<endl;
	cout<<"递归中序遍历：";
	inOrderRecur(root);
	cout<<endl;
	cout<<"Morris中序遍历：";
	morrisIn(root);
	cout<<endl;
	cout<<"递归后序遍历：";
	posOrderRecur(root);
	cout<<endl;
	cout<<"Morris后序遍历：";
	morrisPos(root);
	return 0;
}
