#include <iostream>
#include <stdlib.h> 
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;

struct ListNode{
	int val;
	ListNode* next;
	ListNode* rand;
};
//使用hash_map所需要的hash函数
struct hash_Node
{
    size_t operator() (const ListNode &node) const
    {
        return node.val;
    }
};

//使用hash_map所需要的比较函数
struct compare_Node
{
    bool operator() (const ListNode &n1,const ListNode &n2) const
    {
        return n1.val == n2.val && n1.next == n2.next && n1.rand == n2.rand;
    }
};
//使用hashmap ??
ListNode* copyListWithRand1(ListNode* head)
{
	hash_map<ListNode,ListNode,hash_Node,compare_Node> map;
	ListNode* cur = head;
	while(cur!= NULL)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = cur->val;
		n->next = NULL;
		n->rand = NULL;
		map[*cur] = *n;
		cur = cur->next;
	}
	cur = head;
	while(cur != NULL)
	{
		map[*cur].next = cur->next;
		map[*cur].rand = cur->rand;
		cur = cur->next;
	}
	return &map[*head];
 } 
ListNode* copyListWithRand2(ListNode* head)
{
	if(head == NULL)
		return NULL;
	ListNode* cur = head;
	ListNode* next = NULL;
	//将每个节点都复制 
	while(cur != NULL)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = cur->val;
		next = cur->next;
		cur->next = n;
		n->next = next;
		n->rand = NULL;
		cur = next;
	}
	cur = head;
	ListNode* curCopy = NULL;
	while(cur != NULL)
	{
		next = cur->next->next;
		curCopy = cur->next;
		curCopy->rand = cur->rand != NULL ? cur->rand->next :  NULL;
		cur = next;
	}
	cur = head;
	ListNode* res = head->next;
	while(cur != NULL)
	{
		next = cur->next->next;
		curCopy = cur->next;
		cur->next = next;
		curCopy->next = next != NULL ? next->next : NULL;
		cur = next;
	}
	
	return res;
	
}
int main()
{
	ListNode* p1;
	ListNode* h1 = (ListNode*)malloc(sizeof(ListNode));
	p1 = h1;
	for(int i = 0;i<4;i++)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p1->next = n;
		p1->rand = n;
		p1 = n;
		n->next = NULL;
		n->rand = NULL; 
	}
	p1 = h1->next;
	cout<<"复制前"<<endl;
	while(p1 != NULL)
	{
		if(p1->next != NULL) 
		cout<<p1->val<<"next:"<<p1->next->val<<endl;
		else
		cout<<p1->val<<"next is NULL"<<endl;
		if(p1->rand != NULL)
		cout<<p1->val<<"rand:"<<p1->rand->val<<endl;
		else 
		cout<<p1->val<<"rand is NULL"<<endl;
		p1 = p1->next;
	
	}
	p1 = h1->next;
	p1 = copyListWithRand1(p1);
	cout<<"复制后"<<endl;
	while(p1!= NULL)
	{
		if(p1->next != NULL) 
		cout<<p1->val<<"next:"<<p1->next->val<<endl;
		else
		cout<<p1->val<<"next is NULL"<<endl;
		if(p1->rand != NULL)
		cout<<p1->val<<"rand:"<<p1->rand->val<<endl;
		else 
		cout<<p1->val<<"rand is NULL"<<endl;
		p1 = p1->next;
	}
	return 0;
}
