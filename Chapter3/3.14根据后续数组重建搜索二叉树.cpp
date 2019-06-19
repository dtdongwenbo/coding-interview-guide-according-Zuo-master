#include <iostream>
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
bool isPos(vector<int> arr,int start,int end)
{
	if(start == end)
		return true;
	int less = -1;
	int more = end;
	for(int i = start;i<end;i++)
	{
		if(arr[end]>arr[i])
			less = i;
		else 
			more = more == end ? i : more;
	}
	if(less == -1 || more == end)
		return isPos(arr,start,end-1);
	if(less != more-1)
		return false;
	return isPos(arr,start,less)&&isPos(arr,more,end-1);
	
}
bool isPostArray(vector<int> arr)
{
	if(arr.size() == 0)
		return false;
	return isPos(arr,0,arr.size()-1);

}
Node* posToBST(vector<int> arr,int start,int end)
{
	if(start > end)
		return NULL;
	Node* root = new Node(arr[end]);
	int less = -1;
	int more = end;
	for(int i = start;i<end;i++)
	{
		if(arr[end]>arr[i])
			less = i;
		else
			more = more == end ? i : more;
	}
	root->left = posToBST(arr,start,less);
	root->right = posToBST(arr,more,end-1);
	return root;
	
}
Node* posArratTopBST(vector<int> arr)
{
	if(arr.size() == 0)
		return NULL;
	return posToBST(arr,0,arr.size()-1);
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
	vector<int> arr = {2,1,3,6,5,7,4};
	if(isPostArray(arr))
		cout<<"ÊÇ"<<endl;
	Node* root = posArratTopBST(arr);
	preOrederRecur(root);
	return 0;
}
