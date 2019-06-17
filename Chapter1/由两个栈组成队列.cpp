#include <stack>
#include <iostream>
using namespace std;
class TwoStackQueue
{
	private:
		stack<int> stackPush;
		stack<int> stackPop;
	public:
		void push(int data);
		void pop();
		int front();
		
 };

 void TwoStackQueue::push(int data)
 {
 	stackPush.push(data);
 	if(stackPop.empty())
 	{
 		while(!stackPush.empty())
 		{
 			int data = stackPush.top();
 			stackPush.pop();
 			stackPop.push(data);
		 }
	 }
 }
 void TwoStackQueue::pop()
 {
 	if(stackPush.empty() && stackPop.empty())
 		return ;
 	else if(stackPop.empty())
 	{
 		while(!stackPush.empty())
 		{
 			int data = stackPush.top();
 			stackPush.pop();
 			stackPop.push(data);
		 }
	 }
	 stackPop.pop();
 }
 int TwoStackQueue::front()
 {
 	if(stackPush.empty() && stackPop.empty())
 		return 0;
 	else if(stackPop.empty())
 	{
 		while(!stackPush.empty())
 		{
 			int data = stackPush.top();
 			stackPush.pop();
 			stackPop.push(data);
		 }
	 }
	 return stackPop.top();
 }
 int main()
 {
 	int a[] = {3,4,5,1,2,1};
 	TwoStackQueue q;
 	int i;
 	for(i = 0;i<3;i++)
 		q.push(a[i]);
 	cout<<"q.front()£»"<<q.front()<<endl;
	for(;i<6;i++)
    {
        q.push(a[i]);
    }
    for(i=0;i<6;i++)
    {
        cout << "q.front():" << q.front() <<endl;
        q.pop();
    }
    return 0; 
 }
 
 
