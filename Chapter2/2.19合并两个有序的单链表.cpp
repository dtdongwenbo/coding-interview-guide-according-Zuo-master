#include<iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};
ListNode* merge(ListNode* head1,ListNode* head2)
{
	if(head1 == NULL || head2 == NULL)
		return head1 != NULL ? head1 : head2;
	ListNode* pre = NULL;
	ListNode* next = NULL;
	ListNode* head = head1->val < head2->val ? head1 : head2;
	ListNode* cur1 = head == head1 ? head1 : head2;
	ListNode* cur2 = head == head1 ? head2 : head1;
	while(cur1 != NULL && cur2 != NULL)
	{
		if(cur1->val <= cur2->val)
		{
			pre = cur1;
			cur1 = cur1 -> next;			
		}
		else
		{
			next = cur2->next;
			pre->next = cur2;
			cur2->next = cur1;
			pre = cur2;
			cur2 = next;
		}
	
	}
	pre->next = cur1 == NULL ? cur2 : cur1;
	return head;
}
int main()
{
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	p1 = h1;
	for(int i = 1;i<10;i = i + 2)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p1->next = n;
		p1 = n;
		n->next = NULL;
	}
	p1 = h1->next;
	ListNode* p2;
	ListNode* h2 = (ListNode*)malloc(sizeof(ListNode));
	p2 = h2;
	for(int i = 1;i<5;i++)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p2 ->next = n;
		p2 = n;
		n->next = NULL;
	}
	p2 = h2->next;
	ListNode* newhead = merge(p1,p2);
	while(newhead != NULL)
	{
		cout<<newhead->val<<" ";
		newhead = newhead->next;
	}
	return 0;
}
