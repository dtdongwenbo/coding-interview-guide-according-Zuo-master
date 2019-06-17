#include <iostream>
#include <stdlib.h> 
#include <stack>
using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
	ListNode(int x):
		val(x),next(NULL){
		}
};
bool isPalindrome2(ListNode* head)
{//ʹ��ջ��ʵ��,�������Ż� 
	if(head == NULL ||head->next == NULL)
		return true;
	ListNode* right = head;
	ListNode* cur = head;
	while(cur != NULL && cur->next != NULL)
	{
		right = right->next;
		cur = cur->next->next;
	}
	stack<ListNode> s;
	while(right != NULL)
	{
		s.push(*right);
		right = right->next;
	}
	while(!s.empty())
	{
		if(head->val != s.top().val)
			return false;
		s.pop();
		head = head->next;
	}
	return true;
 
	
}
bool isPalindrome3(ListNode* head)
{//���׷�����ʹ�÷�ת������ʵ�� 
	if(head == NULL || head->next == NULL)
		return true;
	//���м�ڵ�ķ���ֵ��ѧϰ
	ListNode* l1 = head;
	ListNode* l2 = head;
	while(l2 != NULL && l2->next != NULL)
	{
		l1 = l1 ->next;//�ҵ��м�ڵ� 
		l2 = l2->next->next;
	 } 
	 l2 = l1->next;//�Ұ벿�ֵĵ�һ���ڵ�
	 l1->next = NULL; 
	 ListNode* l3;
	 while(l2 != NULL){//��ת�Ұ벿�� 
	 	l3 = l2->next;
	 	l2->next = l1;
	 	l1 = l2;
	 	l2 = l3;
	 }
	l3 = l1;
	l2 = head;
	bool result = true;
	while(l1 != NULL && l2!=NULL)
	{
		if(l1->val != l2->val){
			result = false;
			break;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	//�ָ��б�
	l1 = l3->next;
	l3->next = NULL;
	while(l1 != NULL)
	{
		l2 = l1->next;
		l1->next = l3;
		l3 = l1;
		l1 = l2;
	 } 
	 return result;
	
}
int main(){
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
	for(int i = 4;i>0;i--)
	{
		ListNode* n = (ListNode*)malloc(sizeof(ListNode));
		n->val = i;
		p1->next = n;
		p1 = n;
		n->next = NULL;
	}
	p1 = h1->next;
	if(isPalindrome2(p1)&&isPalindrome3(p1))
		cout<<"�ǻ��Ľṹ"<<endl;
	else 
		cout<<"���ǻ��Ľṹ"<<endl;
	for(int i = 0;i<7;i++)
	{
		cout<<p1->val<<" ";
		p1 = p1->next;
	}
		return 0;
}

