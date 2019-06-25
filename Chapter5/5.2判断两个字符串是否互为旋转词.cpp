#include <iostream>
#include <string>

using namespace std;

bool isRotation(string a,string b)
{
	if(a.size() == 0 || b.size() == 0)
		return false;
	string b1 = b + b;
	if(b1.find(a) == string::npos)// string::npos表示字符串中不存在a这个字符串
		return  false;
	else 
		return true; 
}
int main()
{
	string a1 = "cdab";
	string b1 = "abcd";
	string a2 = "1ab2";
	string b2 = "ab12";
	string a3 = "2ab1";
	string b3 = "ab12";
	if(isRotation(a1,b1))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	if(isRotation(a2,b2))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	if(isRotation(a3,b3))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
		
	return 0;
}
