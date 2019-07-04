#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
using namespace std;

void addNum(deque<string>& deq, int num)
{
	if(!deq.empty())
	{
		int cur = 0;
		string top = deq.back();
		deq.pop_back();
		if(top == "+" || top == "-"){
			deq.push_back(top);
		}
		else
		{
			cur = stoi(deq.back());
			deq.pop_back();
			num = (top == "*") ? (num * cur) : (num / cur);
		}
	}
	deq.push_back(to_string(num));
}
int getNum(deque<string>& deq)
{
	int res = 0;
	bool add = true;
	string cur;
	int num = 0;
	while(!deq.empty())
	{
		cur = deq.front();
		deq.pop_front();
		if(cur == "+")
			add = true;
		else if (cur == "-")
			add = false;
		else{
			num = stoi(cur);//stoi的对象是string 而atoi的对象是char* 
			res += add ? num : (-num);
		}
	}
	return res;
}
vector<int> value(string str,int i)
{
	deque<string> deq;
	int pre = 0;
	vector<int> bra(2,0);
	
	while(i<str.length() && str[i] != ')')
	{
		
		if(str[i] >= '0'&& str[i]<='9'){
			pre = pre*10 + str[i++] - '0';
		}
		else if(str[i]  != '(')
		{
			addNum(deq,pre);
            string temp =" ";
            temp[0] = str[i++];
            deq.push_back(temp);
			pre = 0;
		}
		else
		{
			bra = value(str,i+1);
			pre = bra[0];
			i = bra[1] +1;
		}
	}
	
	addNum(deq,pre);
	vector<int> res(2,0);
	res[0] = getNum(deq);
	res[1] = i;
	return res;
}
int getValue(string str)
{
	return value(str,0)[0];
}
int main()
{
	string str1 = "3+1*4";
	string str2 = "48*((70-65)-43)+8*1";
	cout<<getValue(str1)<<endl;
	cout<<getValue(str2)<<endl;
	return 0;
}
