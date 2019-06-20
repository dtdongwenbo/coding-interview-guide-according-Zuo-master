#include <iostream>
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
void createBT(Node** root,int arr[],int len,int index = 0)
{
	if(index>len-1)
		return ;
	(*root) = new Node(arr[index]);
	createBT(&((*root)->left),arr,len,2*index+1);
	createBT(&((*root)->right),arr,len,2*index+2);
	
}
void preOrderRecur(Node* head)
{
	if(head == NULL)
	return ;
	cout<<head->val<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}

int mostLeftLevel(Node* head,int level)
{
	while(head != NULL)
	{
		++level;
		head = head->left;
	}
	return level-1;
}
int bs(Node* root,int l,int h)
{
	if(l == h)
		return 1;
	if(mostLeftLevel(root->right,l+1) == h)//右子树能达到最后一层 	
	{
		return (1<<(h-l)) + bs(root->right,l+1,h); 
	}
	else 
	{
		return (1<<(h-l-1)) + bs(root->left,l+1,h);
	}
	
}
int nodenum(Node* root)
{
	if(root == NULL)
		return 0;
	return bs(root,1,mostLeftLevel(root,1));
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	Node* root = NULL;
	createBT(&root,arr,12);
	//preOrderRecur(root);
	cout<<nodenum(root);
	return 0;
}
