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
//前序遍历看树的构造是否正确
void preOrderRecur(Node* head)
{
	if(head == NULL)
	return ;
	cout<<head->val<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
 } 
 /*
 　　标准一：

　　1、头节点为边界节点；

　　2、叶节点为边界节点；

　　3、如果节点在其所在的层中是最左或者最右的，那么也是边界节点。
 */
 int getHeight(Node* root,int l)
 {
 	if(root == NULL)
 		return l;
 	return max(getHeight(root->left,l+1),getHeight(root->right,l+1));
 }
 void setEdgeMap(Node* root,Node* edgeMap[][2],int l)
 {
 	if(root == NULL)
 		return ;
 	edgeMap[l][0] = edgeMap[l][0] == NULL ? root : edgeMap[l][0];//第一列保存左边界 
 	edgeMap[l][1] = root;//第二列保存右边界
	setEdgeMap(root->left,edgeMap,l+1);
	setEdgeMap(root->right,edgeMap,l+1); 
	
 }
 void printLeafNotInMap(Node* root,Node* edgeMap[][2],int l)
 {
 	if(root == NULL)
 		return ;
 	if(root->left == NULL && root->right == NULL && root != edgeMap[l][0] && root != edgeMap[l][1])
 		cout<<root->val<<" ";
 	printLeafNotInMap(root->left,edgeMap,l+1);
 	printLeafNotInMap(root->right,edgeMap,l+1);
 }
void printEdge1(Node* root)
{
	if(root == NULL)
		return ;
	int height = getHeight(root,0);
	Node* edgeMap[height][2];
	//memset(edgeMap,0,height*2*sizeof(Node*));//将edgeMap相关的内存空间置0
	for(int i = 0;i<height;i++)
	{
		edgeMap[i][0] = 0;
		edgeMap[i][1] = 0;
	}
	setEdgeMap(root,edgeMap,0);//计算左边界和有边界，此处第一列为保存左边界，第二列为保存有边界
	cout<<"标准一：";
	for(int i = 0;i<height;i++)//打印左边界 
		cout<<edgeMap[i][0]->val<<" ";
	printLeafNotInMap(root,edgeMap,0);//打印既不属于右边界也不属于左边界的叶子节点
	
	for(int i = height-1;i>=0;i--)
	{
		if(edgeMap[i][0] != edgeMap[i][1])
		cout<<edgeMap[i][1]->val<<" ";//打印右边界	
	}	
	cout<<endl;
}
/*
　　标准二：

　　1、头节点为边界节点；

　　2、叶节点为边界节点；

　　3、树左边界延伸下去的路径为边界节点；

　　4、树右边界延伸下去的路径为边界节点。
*/
void printLeftEdge(Node* root,bool print)
{
	if(root == NULL)
		return ;
	if(print || (root->left == NULL && root->right == NULL))
	{
		cout<<root->val<<" ";
	}
	printLeftEdge(root->left,print);
	printLeftEdge(root->right,print&&(root->left == NULL ? true : false));//若该节点已经被打印，且左节点为空，则打印其右节点 
}
void printRightEdge(Node* root,bool print)
{
	if(root == NULL)
		return ;
	//此处需要注意，由于打印结果要求逆时针，则需要先判断左再判断右才能和左边界结合起来 
	printRightEdge(root->left,print&&(root->right == NULL ? true : false));
	printRightEdge(root->right,print);
	if(print || (root->left == NULL && root->right == NULL))
	{
		cout<<root->val<<" ";
	}
}
void printEdge2(Node* root)
{
	if(root == NULL)
		return ;
	cout<<root->val<<" ";
	if(root->left != NULL && root->right != NULL)
	{
		printLeftEdge(root->left,true);
		printRightEdge(root->right,true);
	 } 
	 else
	 {
	 	printEdge2(root->left == NULL ? root->right : root->left);
	 }
	 cout<<endl;
}
int main()
{
	int arr[63] = {1,2,3,-1,4,5,6,-1,-1,7,8,9,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,14,15,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	Node* root = NULL;
	createBT(&root,arr,63);
	//preOrderRecur(root);
	///
	printEdge2(root);
	
}
