#include <iostream>
#include <string>

using namespace std;

void reverse(string &str, int start,int end)
{
	if(str.empty())
		return;
	while(start<end)
	{
		char c = str[start];
		str[start] = str[end];
		str[end] = c;
		start++;
		end--;
		
	}
}
string rotate(string str)
{
	/*先整体逆序 再逐个单词逆序*/
	if(str.empty())
		return " ";
	reverse(str,0,str.size() - 1);
	int start = 0;
	for(int i = 0;i<str.size();i++)
	{
		if(str[i] == ' ')
		{
			reverse(str,start,i-1);
			while(str[i] == ' ') i++;
			start = i;
		}
	}
	if(str[str.size() - 1] != ' ')
		reverse(str,start,str.size()-1);
	return str;
}
string rotate1(string str,int size)
{
	if(str.empty())
		return " ";
	reverse(str,0,size-1);
	reverse(str,size,str.size()-1);
	reverse(str,0,str.size()-1);
	return str;
}
void exchange(string &str,int start,int end,int size)
{
	int i = end - size + 1;
	char tmp = 0;
	while(size-- != 0)
	{
		tmp = str[start];
		str[start] = str[i];
		str[i] = tmp;
		start++;
		i++;
	}
}
string rotate2(string str,int size)
{
	if(str.empty())
		return " ";
	int start = 0;
	int end = str.size() - 1;
	int lpart = size;
	int rpart = str.size() - size;
	int s = min(lpart,rpart);
	int d = lpart - rpart;
	while(true)
	{
		exchange(str,start,end,s);
		if(d == 0)
			break;
		else if(d>0)
		{
			start += s;
			lpart = d;
		}
		else
		{
			end -=s;
			rpart = -d;
		}
		s = min(lpart,rpart);
		d = lpart-rpart;
	}
	return str;
}
int main()
{
	string str1 = "dog loves pig";
	string str2 = "I am a student";
	cout<<rotate(str1)<<endl;
	cout<<rotate(str2)<<endl;
	//
	string str3 = "1234567ABCD";
	int size = 7;
	cout<<rotate1(str3,size)<<endl;
	cout<<rotate2(str3,size)<<endl;
	return 0;
}
