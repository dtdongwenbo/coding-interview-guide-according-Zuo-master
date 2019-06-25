#include <iostream>
#include <string>

using namespace std;

string countStr(string str)
{
	if(str.size() == 0)
		return "";
	
	string res;
	res += str[0];
	int len = str.size();
	int num = 1;
	for(int i = 1;i<len;i++) 
	{
		if(str[i] == str[i-1])
			num++;
		else 
		{
			char c = num + '0';
			res = res + '_' + c + '_' + str[i];
			num = 1;
		}
	}
	char c = num + '0';
	res = res + '_' + c;
	return res;
}
char getChar(string str, int index)
{
	if(str.size() == 0)
		return '\0';
	int len = str.size();
	int num = 0;
	int sum = 0;
	bool stage = true;
	char cur = 0;
	for(int i = 0;i<len;i++)
	{
		if(str[i] == '_')
		{
			stage = !stage;
			continue;
		}
		//µ±Ç°ÊÇ×ÖÄ¸
		else if(stage)
		{
			sum += num;
			if(sum>index)
				return cur;
			else 
			{
				cur = str[i];
				num = 0;
			}
		 } 
		 else 
		 {
		 	num = num * 10 + str[i] - '0';
		 }
	}
	return sum + num > index ? cur : 0;
}
int main()
{
	cout << countStr("aaabbadddffc") << endl;
	cout << getChar("a_100_b_2_c_4", 105) << endl;	
	return 0;
}
