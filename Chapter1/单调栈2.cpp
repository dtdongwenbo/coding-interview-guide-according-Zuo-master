#include <iostream>
#include <stack>

using namespace std;

int** getMaxTree(int a[],int len)
{
	int** res = (int**)malloc(9*sizeof(int*));
	for(int i = 0;i<9;i++)
	res[i] = (int*)malloc(2*sizeof(int));

	stack<int> s;
	for(int i = 0;i<len;i++)
	{
		while(!s.empty() && a[s.top()]>a[i])
		{
			int index = s.top();
			s.pop();
			int leftindex;
			if(s.empty())
				leftindex = -1;
			else
				leftindex = s.top() ;  
			res[index][0] = leftindex;
			res[index][1] = i;
		}
		s.push(i);
	}
	while(!s.empty())
	{
		int index = s.top();
		s.pop();
		int leftindex;
		if(s.empty())
			leftindex = -1;
		else
			leftindex = s.top() ;
		res[index][0] = leftindex;
		res[index][1] = -1; 
	}
	return res;
}
int main()
{
    int a[] = {3,1,3,4,3,5,3,2,2};
    int** head = getMaxTree(a,9);
    for(int i = 0;i<9;i++)
    cout<<head[i][0]<<","<<head[i][1]<<endl;
    

    return 0;
} 
