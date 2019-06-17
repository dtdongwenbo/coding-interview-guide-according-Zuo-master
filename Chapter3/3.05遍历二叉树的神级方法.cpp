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
				cout<<cur->val<<" ";//���Ե������εĽڵ��һ�ε����ӡ 
				cur = cur->left;
				continue;
			}
			else 
			{
				mostRight->right = NULL;				
			}
	   }
	   else 
	   	cout<<cur->val<<" ";//���������Ľڵ��һ�ε���ʱ��ӡ 
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
	cout<<"�ݹ�ǰ�������";
	preOrderRecur(root);
	cout<<endl;
	cout<<"Morrisǰ�������";
	morrisPre(root);
	cout<<endl;
	cout<<"�ݹ����������";
	inOrderRecur(root);
	cout<<endl;
	cout<<"Morris���������";
	morrisIn(root);
	cout<<endl;
	cout<<"�ݹ���������";
	posOrderRecur(root);
	cout<<endl;
	cout<<"Morris���������";
	morrisPos(root);
	return 0;
}
