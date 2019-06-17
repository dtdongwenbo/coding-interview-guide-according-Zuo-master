#include <iostream>

using namespace std;
int Cow(int n)
{
	if(n == 0)
		return 0;
	if(n == 1 || n == 2 || n== 3)
		return n;
	int c1 = 1,c2 = 2,c3 = 3;
	int res;
	for(int i=4;i<=n;i++)
	{
		res = c1+c3;
		c1 = c2;
		c2 = c3;
		c3 = res;
	}
	return res;
}
int main()
{
	int n = 6;
	cout<<Cow(n);
}
