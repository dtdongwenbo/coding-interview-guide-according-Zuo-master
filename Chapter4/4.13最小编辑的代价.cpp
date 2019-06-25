#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minCost2(string str1,string str2,int ic,int dc,int rc)
{
	if(str1.empty() || str2.empty())
		return 0;
	string longstr = str1.size() > str2.size() ? str1 : str2;
	string shortstr = str1.size() < str2.size() ? str1 : str2;
	if(str1.size() < str2.size())//若str2较长则交换ic和dc
	{
		int tmp = ic;
		ic = dc;
		dc = tmp;
	 } 
	 vector<int> dp(shortstr.size()+1,0);
	 for(int i = 1;i<shortstr.size() + 1;i++)
	 	dp[i] = ic * i;
	for(int i = 1;i<longstr.size()+1;i++)
	{
		int pre = dp[0];
		dp[0] = dc *i;
		for(int j = 1;j<shortstr.size() + 1;j++)
		{
			int tmp = dp[j];
			if(longstr[i-1] == shortstr[j-1])
				dp[j] = pre;
			else
				dp[j] = pre + rc;
			dp[j] = min(dp[j],tmp + dc);
			dp[j] = min(dp[j],dp[j-1] + ic);
			pre = tmp;
		}
		
	}
	return dp[shortstr.size()];
}
int minCost1(string str1,string str2,int ic,int dc,int rc)
{
	if(str1.empty() || str2.empty())
		return 0;
	int row = str1.size() + 1;
	int col = str2.size() + 1;
	
	vector<vector<int>> dp(row,vector<int>(col,0));
	
	for(int i = 1;i<col;i++)
		dp[0][i] = ic * i;
	for(int i = 1;i<row;i++)
		dp[i][0] = dc * i;
	for(int i = 1;i<row;i++)
	{
		for(int j = 1;j<col;j++)
		{
			if(str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else 
				dp[i][j] = dp[i-1][j-1] + rc;
			dp[i][j] = min(dp[i][j],dp[i][j-1] + ic);
			dp[i][j] = min(dp[i][j],dp[i-1][j] + dc);
		}
	}
	return dp[row-1][col-1];
}
int main()
{
	string str1 = "ab12cd3";
	string str2 = "abcdf";
	int ic = 5;
	int dc = 3;
	int rc = 2;
	cout<<minCost1(str1,str2,ic,dc,rc)<<endl;
	cout<<minCost2(str1,str2,ic,dc,rc)<<endl;
	return 0; 
 } 
