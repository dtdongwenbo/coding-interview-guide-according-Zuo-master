#include <iostream>
#include <string>

using namespace std;

bool isValid(string str)
{
	if(str[0] != '-' &&(str[0]<'0' || str[0] > '9'))
		return false;
	if(str[0] != '-' &&(str[1] == '0' || str.size() == 1))
		return false;
	if(str[0] == '0' && str.size() > 1)
		return false;
	for(int i = 1;i<str.size();i++)
	{
		if(str[i]<'0' || str[i]>'9')
			return false;
	}
	return true;
}
int convert(string str)
{
	if(str.size() == 0)
		return 0;
	if(!isValid(str))
	{
		return 0;
	}
	bool posi = str[0] == '-' ? false : true;
	int minq = INT_MIN/10,minr = INT_MIN%10;
	int res = 0;
	int cur = 0;
	for(int i = posi ? 0 : 1;i<str.size();i++)
	{
		cur = '0' - str[i];//����������ӵ�и���ľ���ֵ��Χ������ת���������Ը�������ʽ��¼����ֵ
		if(res < minq || (res == minq && cur<minr))
			return 0;//����ͨ�������ͳ�ʮǰ����ֵ�ж϶��ܲ���ת�� 
		res = res * 10 + cur;
	}
	if(posi && res == INT_MIN)//������res���ڸ�������Сֵ 
		return 0;
	return posi ? -res : res;
}
int main()
{
	string str1 = "123";
	string str2 = "023";
	string str3 = "A13";
	string str4 = "0";
	string str5 = "2147483647";
	string str6 = "2147483648";
	string str7 = "-123";
	cout<<convert(str1)<<endl;
	cout<<convert(str2)<<endl;
	cout<<convert(str3)<<endl;
	cout<<convert(str4)<<endl;
	cout<<convert(str5)<<endl;
	cout<<convert(str6)<<endl;
	cout<<convert(str7)<<endl;
	return 0;
}
