#include <iostream>
#include <string>

using namespace std;

string modify(string str)
{
	if(str.empty())
		return " ";
	int j = str.size() - 1;
	for(int i = j;i>=0;i--)
	{
		if(str[i] != '*')
			str[j--] = str[i];
	}
	for(j;j>=0;j--)
		str[j] = '*';
		return str;
}
string replace(string str)
{
	if(str.empty())
		return " ";
	int num = 0;
	int i = 0;
	for(i;i<str.size();i++)
	{
		if(str[i] == ' ')
			++num;
	}
	int j = i + num *2;
	string res(j,'0');
	for(i;i>=0;i--)
	{
		if(str[i] != ' ')
		{
			res[j--] = str[i];
		}
		else 
		{
			res[j--] = '0';
			res[j--] = '2';
			res[j--] = '%';
		}
			
	}

	return res;
}
int main()
{
	string str = "a b  c";
	cout<<replace(str)<<endl;
	string str1 = "12**345";
	cout<<modify(str1)<<endl;
	return 0;
}
