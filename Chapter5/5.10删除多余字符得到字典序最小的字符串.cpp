#include <iostream>
#include <string>
#include <vector>
using namespace std;

string removeDuplicateLetters(string str)
{
	vector<int> map(26,0);
	for(int i = 0;i<str.size();i++)
	{
		map[str[i] - 'a']++;
	}
	string res;
	int index = 0;
	int l = 0;
	int r = 0; 
	while(r != str.length())
	{
		if(map[str[r] - 'a'] == -1 || --map[str[r] - 'a'] > 0)
			r++;
		else
		{
			//当前字符需要考虑且之后不会再出现
			//再l..r上所有需要考虑的字符中，找到ascll码最小字符的位置
			int pick = -1;
			for(int i =l;i<=r;i++)
			{
				if(map[str[i] - 'a'] != -1 &&(pick == -1 || str[i]<str[pick]))
					pick = i;
			 } 
		res += str[pick];
		for(int i = pick + 1;i<=r;i++)
		{
			if(map[str[i] - 'a'] != -1)
				map[str[i] - 'a']++;
		}
		map[str[pick] - 'a'] = -1;
		l = pick +1;
		r = pick + 1;
		}
	}
	return res;
	
}
int main()
{
	string str1 = "acbc";
	string str2 = "dbcacbca";
	cout<<removeDuplicateLetters(str1)<<endl;
	cout<<removeDuplicateLetters(str2)<<endl;
	return 0;
}
