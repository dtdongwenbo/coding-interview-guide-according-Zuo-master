#include <stack>
#include <iostream>
using namespace std;
void sortStack(stack<int> &s)
{
	stack<int> helpS;
	while(!s.empty())
	{
		int tmp = s.top();
		s.pop();
		while(!helpS.empty()&&helpS.top()<tmp)
		{
			s.push(helpS.top());
			helpS.pop();
		}
		helpS.push(tmp);
	}
	while(!helpS.empty())
	{
		s.push(helpS.top());
		helpS.pop();
	}
}
int main()
{
    int a[] = {3,4,5,1,2,1};
    stack<int> s;
    int i;
    for(i=0;i<6;i++)
    {
        s.push(a[i]);
    }
    cout << "The datum of the stack before sorting are:" << endl;
    for(i=0;i<6;i++)
    {
        cout << s.top() << endl;
        s.pop();
    }
    for(i=0;i<6;i++)
    {
        s.push(a[i]);
    }
    cout << "The datum of the stack after sorting are:" << endl;
    sortStack(s);
    for(i=0;i<6;i++)
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
