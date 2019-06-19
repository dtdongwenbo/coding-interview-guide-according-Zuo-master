#include<iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;
struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int data)
	{
		val = data;
		left = NULL;
		right = NULL;
	}
};
struct ReturnType{
	bool isBalanced;
	int height;
	ReturnType(bool balanc,int h){
		isBalanced = balanc;
		height = h;
	}
};
ReturnType process(Node* head)
{
	if(head == NULL)
		return ReturnType(true,0);
	ReturnType left = process(head->left);
	ReturnType right = process(head->right);
	int height = max(left.height,right.height) + 1;
	bool isbalanced = left.isBalanced && right.isBalanced&&abs(left.height - right.height)<2;
	return ReturnType(isbalanced,height);
}
bool Balance(Node* head)
{
	return process(head).isBalanced;
}
void createBT(Node** head,int arr[],int len,int index = 0)
{
	if(index>len-1 || arr[index] == -1)
		return ;
	(*head) = new Node(arr[index]);
	createBT(&((*head)->left),arr,len,2*index+1);
	createBT(&((*head)->right),arr,len,2*index+2);
}
void preOrederRecur(Node* head)
{
	if(head == NULL)
		return ;
	cout<<head->val<<" ";
	preOrederRecur(head->left);
	preOrederRecur(head->right);
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	Node* root = NULL;
	createBT(&root,arr,7);
	//preOrederRecur(root);
	if(Balance(root))
		cout<<"Is Balance";
	else
		cout<<"Is Not Balance";
	return 0; 
}
