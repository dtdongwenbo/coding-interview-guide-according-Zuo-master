#include <stack>
#include <iostream>
using namespace std;
class stack2{
	public:
		stack2(){};
		~stack2(){};
		void push(int data);
		void pop();
		int getmin();
		int top();
		void text();
	private:
		
		stack<int> stackData;
		stack<int> stackMin;
		
}; 
void stack2::push(int data)
{
	stackData.push(data);
	if(stackMin.empty())
		stackMin.push(data);
	else if(data<stackMin.top())
		stackMin.push(data);
	else
		stackMin.push(stackMin.top());
		
}
void stack2::text()
{
	for(int i = 0;i<6;i++)
		{
			cout<<stackMin.top();
			stackMin.pop();
		}
}
void stack2::pop()
{
	if(!stackMin.empty())
		stackMin.pop();
	if(!stackData.empty())
		stackData.pop();
}
int stack2::getmin()
{

	int min = stackMin.top();
	return min;
}
int stack2::top()
{
	return stackData.top();
}
int main()
{
	int a[] = {3,4,5,1,2,1};
	stack2 s;
	for(int i = 0;i<6;i++)
	{
		s.push(a[i]);
		cout<<"s.top():"<<s.top()<<endl;
		cout<<"s.getMin():"<<s.getmin()<<endl;

	}

	return 0;

}










