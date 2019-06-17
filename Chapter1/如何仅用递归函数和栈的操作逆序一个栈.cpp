#include<iostream>
#include<stack>
using namespace std;

int popLast(stack<int> &s)
{
	int tmp = s.top();
	s.pop();
	if(s.empty())
	return tmp;
	else
	{
		int last = popLast(s);
		s.push(tmp);
		return last;
	}
}
void reStack(stack<int> &s)
{
	if(s.empty())
	return ;
	int tmp = popLast(s);
	reStack(s);
	s.push(tmp);
	return ;
}
int main()
{
	stack<int> s;
	int a[] = {1,2,3,4,5};
	int i;
	for(i = 0;i<5;i++)
	{
		s.push(a[i]);
	}
	reStack(s);
    cout << "After Reverse:" << endl;
    for(i=0;i<5;i++)
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
