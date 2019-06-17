#include<iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

struct ListNode{
	int val;
	ListNode* left;
	ListNode* right;
	ListNode(int data){
		val = data;
		left = NULL;
		right = NULL;
	};
}; 
void bt_insert(ListNode **head,int data)
{

	if((*head) == NULL)
	{
		*head = new ListNode(data);
		return ;
	}
	else if((*head)->left == NULL&& (*head)->val > data)
	{

		(*head)->left = new ListNode(data);
		return ;
	}
	else if((*head)->right == NULL&& (*head)->val < data)
	{
		(*head)->right = new ListNode(data);
		return ;
	}

	if(data<(*head)->val)
	{
		bt_insert(&((*head)->left),data);	
	}		
	else if(data>(*head)->val)
	{
		bt_insert(&((*head)->right),data);
	}
		
	else
	 return ;
}
void preOrderRecur(ListNode* head)//ǰ���������������ڵ�ֵ 
{

	if(head == NULL)
		return ;
	cout<<head->val<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}
//��һ�ַ��� 
void inOrderToQueue(ListNode* head, queue<ListNode*> &q)
{
	//ʹ������������������Ľڵ���뵽������ 
	if(head == NULL)
	return ;
	inOrderToQueue(head->left,q);
	q.push(head);
	inOrderToQueue(head->right,q);
	
}
ListNode* convert1(ListNode* head)
{
	queue<ListNode*> q;
	inOrderToQueue(head,q);
	head = q.front();
	q.pop();
	ListNode* pre = head;
	pre->left = NULL;
	
	ListNode* cur = NULL;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		pre->right = cur;
		cur->left = pre;
		pre = cur;
	}
	cur->right = NULL;
	return head;
}
//�ڶ��ַ���
ListNode* process(ListNode* head)
{
	if(head == NULL)
		return NULL;
	ListNode* leftE = process(head->left);
	ListNode* rightE = process(head->right);
	
	ListNode* leftS = leftE != NULL ? leftE->right : NULL;
	ListNode* rightS = rightE != NULL ? rightE->right : NULL;
	
	if(NULL != leftE && NULL != rightE)
    {
        leftE->right = head;
        head->left = leftE;
        head->right = rightS;
        rightS->left = head;
        rightE->right = leftS;        //βָ��ͷ
        return rightE;        //����β��ָ��
    }
    else if(NULL != leftE)
    {
        leftE->right = head;
        head->left = leftE;
        head->right = leftS;    //βָ��ͷ
        return head;    //����β��ָ��
    }
    else if(NULL != rightE)
    {
        head->right = rightS;
        rightS->left = head;
        rightE->right = head;    //βָ��ͷ
        return rightE;            //����β
    }
    else
    {
        head->right = head;        //βָ��ͷ
        return head;            //����β
    }
}
ListNode* convert2(ListNode* head)
{
    if(NULL == head)
        return NULL;
    ListNode *last = process(head);
    head = last->right;
    last->right = NULL;
    return head;
 } 
int main()
{
	int arr[] = {6,4,7,2,5,9,1,3,8};
	ListNode *head = NULL;
	for(int i = 0;i<9;i++)
	{
		bt_insert(&head,arr[i]);
	}
	preOrderRecur(head);
	cout<<endl;
	head = convert2(head);
	while(head != NULL)
	{
		cout<<head->val<<" ";
		head= head->right;
	}
	return 0;
}
