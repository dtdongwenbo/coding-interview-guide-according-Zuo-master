#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > multiMatrix(vector< vector<int> > a, vector< vector<int> > b)
{
	if (a.empty() || b.empty())
		return vector< vector<int> >();

	/*保存矩阵相乘结果*/
	vector< vector<int> > res(a.size(), vector<int>(b[0].size(), 0));
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < b[0].size(); ++j)
		{
			for (int k = 0; k < b.size(); ++k)
			{
				res[i][j] += a[i][k] * b[k][j];
			}	
		}
	}

	return res;
}
vector< vector<int> > matrixPower(vector< vector<int> >matrix,int p)
{
	int row = matrix.size(),col = matrix[0].size();
	vector< vector<int> > res(row,vector<int>(col,0));////初始化row * col二维动态数组，初始化值为0
	for (unsigned int i = 0; i < res.size(); ++i)
	{
		res[i][i] = 1;
	}
	vector< vector<int> > tmp = matrix;
	for(;p !=0;p>>=1)
	{
		if((p&1)!=0 )
		{
			res = multiMatrix(res,tmp);
		}
		tmp = multiMatrix(tmp,tmp);
	}
	return res;
}
int fibonacci_3(int n)
{
	if(n<1)
		return 0;
	else if(n == 1 || n== 2)
		return 1;
	else
	{
		vector< vector<int> > base(2,vector<int>(2));
		 base[0][0] = 1;
		 base[0][1] = 1;
		 base[1][0] = 1;
		 base[1][1] = 0;
		vector< vector<int> > res = matrixPower(base,n-2);
		return res[0][0] + res[1][0];
		
	}	
 } 
 int fibonacci_2(int n)
 {
 	if(n<1)
 		return 0;
 	if(n == 1 || n==2)
 		return 1;
 	int f1 = 1;
 	int f2 = 1;
 	int res;
 	
 	for(int i = 3;i<=n;i++)
 	{
 		res = f1 + f2;
		f1 = f2;
		f2 = res;	
	 }
	 return res;
 }
  int fibonacci_1(int n)
 {
 	if(n<1)
 		return 0;
 	if(n == 1 || n==2)
 		return 1;
	return fibonacci_1(n-1) + fibonacci_1(n-2);
 	
 }
 int main()
{
	cout << fibonacci_1(6) << endl;
	cout << fibonacci_2(6) << endl;
	cout << fibonacci_3(6) << endl;

	return 0;
}
