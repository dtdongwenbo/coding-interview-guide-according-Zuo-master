#include<iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};
ListNode* insertNum(ListNode* head,int num)
{
	ListNode* pre = head;
	ListNode* cur = head->next;
	ListNode* n = (ListNode*)malloc(sizeof(ListNode));
	n->val = num;
	while(cur != head)
	{
		if(pre->val <=num && cur->val >= num)
			break;
		pre = cur;
		cur = cur->next;
	}
	pre->next = n;
	n->next = cur;
	return head->val<num ? head : n; 
	
}
int main()
{
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	p1 = h1;
	for(int i = 1;i<4;i++)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p1->next = n;
		p1 = n;
		n->next = NULL;
	}
	p1->next = h1;
	p1 = h1->next;
	p1 = insertNum(p1,2);
	ListNode* pre = p1;
	ListNode* cur = p1->next;
	while(cur != p1 )
	{
		cout<<pre->val<<" ";
		pre = cur;
		cur = cur->next;
	}
	return 0;
}
