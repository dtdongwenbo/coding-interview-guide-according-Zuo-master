#include<iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};
void mergeLR(ListNode* left,ListNode* right)
{
	//这里按照书上的思路使用把right插进left
	ListNode* next = NULL;
	while(left->next != NULL)
	{
		next = right->next;
		right->next = left->next;
		left->next = right;
		left = right->next;
		right = next;
	}
	left->next = right;
	 
}
void relocate(ListNode* head)
{
	if(head == NULL || head->next == NULL)
		return ;
	ListNode* mid = head;
	ListNode* right = head->next;
	while(right->next != NULL && right->next->next != NULL)
	{
		mid = mid->next;
		right = right->next->next;
	}
	right = mid->next;
	mid->next = NULL;
	mergeLR(head,right);
		
}
int main()
{
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	p1 = h1;
	for(int i = 1;i<7;i++)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p1->next = n;
		p1 = n;
		n->next = NULL;
	}

	p1 = h1->next;
	relocate(p1);
	while(p1!= NULL)
	{
		cout<<p1->val<<" ";
		p1 = p1->next;
	}
	return 0;
}
