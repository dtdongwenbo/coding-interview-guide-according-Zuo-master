#include<iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};
ListNode* getSmallestPreNode(ListNode* head)
{
	ListNode* smallPre = NULL;
	ListNode* small = head;
	ListNode* pre = head;
	ListNode* cur = head->next;
	while(cur != NULL)
	{
		if(cur->val <small->val)
		{
			smallPre = pre;
			small = cur;
		}
		pre = cur;
		cur = cur->next;
	}
	return smallPre;
}
ListNode* selectionSort(ListNode* head)
{
	ListNode* cur = head;
	ListNode* small = NULL;
	ListNode* smallPre = NULL;
	ListNode* tail = NULL;//已排序部分的尾部 
	while(cur != NULL)
	{
		small = cur;
		smallPre = getSmallestPreNode(cur);
		if(smallPre != NULL)
		{
			small = smallPre -> next;
			smallPre->next = small->next;
		}
		cur = cur == small ? cur->next : cur;
		if(tail == NULL)
			head = small;
		else 
			tail->next = small;
		tail = small;
	}
	return head;
}
int main()
{
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	p1 = h1;
	for(int i = 8;i>0;i--)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p1->next = n;
		p1 = n;
		n->next = NULL;
	}
	p1 = h1->next;
	p1 = selectionSort(p1);
	while(p1 != NULL)
	{
		cout<<p1->val<<" ";
		p1 = p1->next;
	}
	return 0;
}
