#include <iostream>
#include <hash_set>
using namespace std;
using namespace __gnu_cxx; 
struct ListNode{
	int val;
	ListNode* next;
};
void removeRep1(ListNode* head)
{
	if(head == NULL)
		return ;
	hash_set<int> set;
	ListNode* cur = head->next;
	ListNode* pre = head;
	ListNode* next = NULL;
	set.insert(head->val);
	while(cur != NULL)
	{
		if(set.find(cur->val) != set.end())//find会挨个查找set，当到达set.end()时，也就是一个也没找到，返回end
		{
			pre->next = cur->next;
			delete cur;
		}
		else
		{
			set.insert(cur->val);
			pre = cur;
		}
		cur = pre->next;
		
	}
	return ;
	
}
void removeRep2(ListNode* head)
{
	ListNode* pre = NULL;
	ListNode* cur = head;
	ListNode* next = NULL;
	while(cur != NULL)
	{
		int value = cur->val;
		pre = cur;
		next = cur->next;
		while(next != NULL)
		{
			if(value == next->val)
			{
				pre->next = next->next;
				next = next->next;;
				
			}
			else
			{
				pre = next;
				next = next->next;
			}
		}
		cur = cur->next;
	}
}
int main()
{
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	p1 = h1;
	for(int i = 1;i<7;i++)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i-1;
		p1->next = n;
		p1 = n;
		ListNode* m = (ListNode*)malloc(sizeof(ListNode));
		m->val = i;
		p1->next = m;
		p1 = m;
		m->next = NULL;
	}
	p1 = h1->next;
	cout<<"构造的链表:";
	while(p1 != NULL)
	{
		cout<<p1->val<<" ";
		p1 = p1->next;
	}
	p1 = h1->next;
	removeRep2(p1);
	p1 = h1->next;
	cout<<"删除的链表:";
	while(p1 != NULL)
	{
		cout<<p1->val<<" ";
		p1 = p1->next;
	}
	return 0;
}
