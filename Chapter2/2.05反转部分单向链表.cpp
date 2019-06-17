#include <iostream>
using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
	ListNode(int x):
		val(x),next(NULL){
		}
};
ListNode* reversePart(ListNode* head,int from,int to)
{
	if(head == NULL)
		return head;
	int len = 0;
	ListNode* node = head;
	ListNode* fPre = NULL;
	ListNode* tPos = NULL;
	while(node!=NULL)
	{
		len++;
		if(len == from-1)
			fPre = node;
		if(len == to+1)
			tPos = node;
		node = node->next;

	}

	if(from>to || from<1 || to>len)
		return head;
	node = (fPre == NULL ? head : fPre->next);
	ListNode* begin = node->next;
	ListNode* next = NULL;
	node->next = tPos;//指向to之后的第一个节点 
	while(begin != tPos)
	{
		next = begin->next;
		begin->next = node;
		node = begin;
		begin = next;
	}
	//fPre非头结点时
	if(fPre != NULL)
	{
		fPre->next = node;
		return head;
	} 
	return node;
	
		
}
int main()
{
	//从2开始到4结束这部分进行反转 
	int from = 1,to = 5;
	int N = 5;//此处为链表长度 
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	p1 = h1;
	for(int i = 1;i<6;i++)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p1->next = n;
		p1 = n;
		n->next = NULL;
	}
	p1 = h1->next;
	if(from<1||to>N)
	{
		cout<<"不用调整"<<endl;
	}
	else
	{
		p1 = reversePart(p1,from,to);
	
		for(int i = 0;i<5;i++)
		{
			cout<<p1->val<<" ";
			p1 = p1->next;
		}
	}
	return 0;
}
