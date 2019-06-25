#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> getdp(string str1,string str2)
{
	vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),0));
	for(int i = 0;i<str1.size();i++)
	{
		if(str1[i] == str2[0])
			dp[i][0] = 1;
	}
	for(int j = 1;j<str2.size();j++)
		if(str1[0] == str2[j])
			dp[0][j] = 1;
	for(int i = 1;i< str1.size();i++)
	{
		for(int j = 1;j<str2.size();j++)
			if(str1[i] == str2[j])
				dp[i][j] = dp[i-1][j-1] + 1;
	}
	return dp;
}
string lcst(string str1,string str2)
{
	if(str1.size() == 0 || str2.size() == 0)
		return "";
	vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),0));
	dp = getdp(str1,str2);
	int max = 0;
	int end = 0;
	for(int i = 0;i<str1.size();i++)
	{
		for(int j = 0;j<str2.size();j++)
		{
			if(dp[i][j] > max)
			{
				max = dp[i][j];
				end = i;
			}
		}
	}

	return str1.substr(end-max+1,max);
}
string lcst2(string str1,string str2)
{
	if(str1.size() == 0 || str2.size() == 0)
		return "";
	int row = 0;
	int col = str2.size() - 1;//从右上角的点开始依次往左下方扫
	int max = 0;
	int end = 0;
	while(row<str1.size())
	{
		int i = row;
		int j = col;
		int len = 0;
		while(i<str1.size() && j<str2.size())
		{
			if(str1[i] != str2[j])
				len = 0;
			else 
				len++;
			if(len > max)
			{
				end = i;
				max = len;
			}
			i++;
			j++;
		}
		if(col>0)
			col--;
		else 
			row++;
	 } 
	 return str1.substr(end-max+1,max);
}
int main()
{
	string str1 = "1AB2345CD";
	string str2 = "12345EF";
	cout<<lcst(str1,str2)<<endl;
	cout<<lcst2(str1,str2)<<endl;
	return 0;
}
