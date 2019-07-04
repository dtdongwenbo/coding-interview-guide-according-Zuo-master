#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValid(string str)
{
	if(str.empty())
		return false;
	int status = 0;
	for(int i = 0;i<str.length();i++)
	{
		if(str[i] == ')' && (--status < 0))
			return false;
		if(str[i] != '(' && str[i] != ')')
			return false;
		if(str[i] == '(')
			status++;
	}
	
	return status == 0;
}
int maxLength(string str)
{
	if(str.empty())
		return 0;
	vector<int> dp(str.length(),0);
	int res = 0;
	int pre = 0;
	dp[0] = 0;
	for(int i = 1;i<str.length();i++)
	{
		 if(str[i] == ')')
		{
			pre = i-dp[i-1] - 1;
			if(pre >= 0 && str[pre] == '(')
			{
				dp[i] = dp[i-1] + 2 + (pre > 0 ? dp[pre-1] : 0);
			}
		}
		res = max(res,dp[i]);
	}
	return res;
}
int main()
{
	string str1 = "()";
	string str2 = "(()())";
	string str3 = "())";
	string str4 = "()a()";
	if(isValid(str1)) cout<<"str1 is true"<<endl;
	if(isValid(str2)) cout<<"str2 is true"<<endl;
	if(isValid(str3)) cout<<"str3 is true"<<endl;
	if(isValid(str4)) cout<<"str4 is true"<<endl;
	string str5 = "()(()()(";
	cout<<maxLength(str2)<<endl;
	cout<<maxLength(str3)<<endl;
	cout<<maxLength(str5)<<endl;
	return 0;
 } 
