#include<iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

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
void createBT(Node** head,int arr[],int len, int index = 0)
{
	if(index > len-1 || arr[index] == -1)
		return ;
	(*head) = new Node(arr[index]);
	createBT(&((*head)->left),arr,len,2*index+1);
	createBT(&((*head)->right),arr,len,2*index + 2);
}
Node* getMaxBST(Node* root,int &maxNode,int &minNode,int &maxBSTSize)
{
	if(root == NULL)
	{
		maxNode = -99999;
		minNode = 99999;
		maxBSTSize = 0;
		return NULL;		
	}
	int lmin,lmax,lmaxBSTSize;
	Node* ld = getMaxBST(root->left,lmax,lmin,lmaxBSTSize);
	int rmin,rmax,rmaxBSTSize;
	Node* rd = getMaxBST(root->right,rmax,rmin,rmaxBSTSize);
	minNode = min(lmin,root->val);
	maxNode = max(rmax,root->val);
	//
	maxBSTSize = max(lmaxBSTSize,rmaxBSTSize);
	//
	Node* head = lmaxBSTSize>=rmaxBSTSize ? ld : rd;

	//
	if(root->val>lmax && root->val<rmin && root->left == ld && root->right == rd)
	{
		maxBSTSize = lmaxBSTSize + rmaxBSTSize + 1;
		head = root;
	}
	return head;
}
Node* getMax(Node* root)
{
	if(root == NULL)
	return NULL;
	int max,min,maxBSTSize;
	Node* head = getMaxBST(root,max,min,maxBSTSize);
	return head;
}
//前序遍历看树的构造是否正确
void preOrderRecur(Node* head)
{
	if(head == NULL)
	return ;
	cout<<head->val<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
 } 
 
 int main()
{
	int arr[] = {6,1,12,0,3,10,13,-1,-1,-1,-1,4,14,20,16,-1,-1,-1,-1,-1,-1,-1,-1,2,5,11,15};
	Node* root = NULL;
	createBT(&root,arr,27);
	//preOrderRecur(root);
	Node* head = getMax(root);		
	preOrderRecur(head);
	return 0;

}
