#include <iostream>
#include <vector>
using namespace std;

void printVector(vector< vector<int> > v)
{
	int row = v.size();
	int column = v[0].size();
	cout<<"矩阵本身："<<endl;
	for(int i = 0;i<row;i++)
	{
		for(int j = 0;j<column;j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
}
int minPathSum1(vector< vector<int> > v  )
{
	if(v.empty())
		return 0;
	int row = v.size();
	int column = v[0].size();
	vector< vector<int> > res(row,vector<int>(column,0));
	res[0][0] = v[0][0];
	for(int i = 1;i<column;i++)
		res[0][i] = res[0][i-1] + v[0][i];
	for(int j = 1;j<row;j++)
		res[j][0] = res[j-1][0] + v[j][0];
	for(int i = 1;i<row;i++)
		for(int j = 1;j<column;j++)
		{
			res[i][j] = v[i][j] + min(res[i-1][j],res[i][j-1]);
		}
	return res[row-1][column-1];
	 
}
int minPathSum2(vector< vector<int> > v  )
{
	if(v.empty())
		return 0;
	int row = v.size();
	int column = v[0].size();
	int less = min(row,column);
	int more = max(row,column);
	bool rowmore = (row>column)? true : false;
	vector<int> res(less,0);
	res[0] = v[0][0];
	for(int i = 1;i<less;i++)
		res[i] = res[i-1] + v[0][i];
	for(int i = 1;i<more;i++)
	{
		res[0] = res[0] + (rowmore? v[i][0] : v[0][i]);
		for(int j = 1;j<less;j++)
		{
			res[j] = (rowmore ? v[i][j] : v[j][i]) + min(res[j-1],res[j]);
		}
	}
	return res[less-1];
	
}
int main()
{
	vector< vector<int> > v = { {1, 3, 5, 9} , {8, 1, 3, 4} ,{ 5, 0, 6, 1} , {8, 8, 4, 0} };
	printVector(v);
	cout<<"方法一：";
	cout<<minPathSum1(v);
	cout<<endl;
	cout<<"方法二：";
	cout<<minPathSum2(v);
	cout<<endl;
	return 0;
}
