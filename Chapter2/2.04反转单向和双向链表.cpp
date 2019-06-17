#include <iostream>
using namespace std;

struct SingleNode 
{
	int val;
	struct SingleNode* next;
	SingleNode(int x):
		val(x),next(NULL){		
		}
};
struct DoubleNode 
{
	int val;
	struct DoubleNode* pre;
	struct DoubleNode* next;
	DoubleNode(int x):
		val(x),next(NULL){		
		}
};
SingleNode* reverseList(SingleNode* head)
{
	SingleNode* pre = NULL;
	SingleNode* nxt = NULL;
	while(head != NULL)
	{
		nxt = head->next;
		head->next = pre;
		pre = head;
		head = nxt;
	}
	return pre;
}
DoubleNode* reverseList(DoubleNode* head)
{
	DoubleNode* pre = NULL;
	DoubleNode* nxt = NULL;
	while(head != NULL)
	{
		nxt = head->next;
		head->next = pre;
		head->pre = nxt;
		pre = head;
		head = nxt;
	}
	return pre;
}
int main()
{
	//单向链表 
	SingleNode* p1;
	SingleNode* h1 = (SingleNode*)malloc(sizeof(SingleNode));	
	p1 = h1;
	for(int i = 0;i<10;i++)
	{
		SingleNode* n = (SingleNode*)malloc(sizeof(SingleNode));
		n->val = i;
		p1->next = n;
		p1 = n;
		n ->next = NULL;
	}
	p1 = h1->next;
	//单向链表反转
	p1 = reverseList(p1);
	cout<<"单向链表的反转结果：";
	for(int i = 0;i<10;i++)
	{
		cout<<p1->val<<" ";
		p1 = p1->next;	
	} 
	cout<<endl; 
	//双向链表
	DoubleNode* p2;
	DoubleNode* h2 = (DoubleNode*)malloc(sizeof(DoubleNode));	
	p2 = h2;
	for(int i = 0;i<10;i++)
	{
		DoubleNode* n = (DoubleNode*)malloc(sizeof(DoubleNode));
		n->val = i;
		p2->next = n;
		n->pre = p2;
		p2 = n;
		n ->next = NULL;
	}
	p2 = h2->next;
	p2 = reverseList(p2);
	cout<<"双向链表的反转结果：";
	for(int i = 0;i<10;i++)
	{
		cout<<p2->val<<" ";
		p2 = p2->next;	
	} 
	return 0;
}
