#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int modifyIndex2(int i,int len)
{
	return (2*i)%(len+1);
}
void reverse(vector<int> &arr,int l,int r)
{
	while(l<r)
	{
		int tmp = arr[l];
		arr[l++] = arr[r];
		arr[r--] = tmp;
	}
}
void rotate(vector<int> &arr,int l,int m,int r)
{
	reverse(arr,l,m);
	reverse(arr,m+1,r);
	reverse(arr,l,r);
}
void cycles(vector<int> &arr,int start,int len,int k)
{
	//�ҵ�ÿһ������λ�ã�ÿһ��λ�ö������±�������
	//ע�����λ���Ǵ�1��ʼ��ģ��������±��Ǵ�0��ʼ���
	for(int i = 0,trigger = 1;i<k;i++,trigger *= 3)
	{
		int preValue = arr[trigger + start - 1];
		int cur = modifyIndex2(trigger,len);
		while(cur != trigger)
		{
			int tmp = arr[cur + start - 1];;
			arr[cur + start - 1] = preValue;
			preValue = tmp;
			cur = modifyIndex2(cur,len);
		}
		arr[cur+start-1] = preValue;
	 } 
}
vector<int> process(vector<int> arr,int L,int R)
{
	while(R-L+1>0){
		//������ֿ飬ʹÿһ��ĳ�������3^k-1
		int len = R - L - 1;
		int base = 3;
		int k = 1;
		while(base <= (len+1)/3)
		{
			base *= 3;
			k++;
		 } 
		 //��ǰҪ�������Ϊbase-1�Ŀ飬һ�����ٳ���2
		 int half = (base-1)/2;
		 int mid = (L+R)/2;
		
		 //Ҫ��ת���󲿷�Ϊ[L+half...mid]���Ҳ���Ϊarr[mid+1...mid+half]
		 rotate(arr,L+half,mid,mid+half);
		 //��ת��ɺ�ʹ���±�������
		 cycles(arr,L,base-1,k);
		 //ʣ�µĲ��ּ�������
		 L = L + base - 1; 
	}
	return arr;

}
vector<int> shuffle(vector<int> arr)
{
	if(!arr.empty() && (arr.size() & 1) == 0)
		return process(arr,0,arr.size() - 1);
}
vector<int> wiggleSort(vector<int> arr)
{
	if(arr.empty())
		return vector<int>(0);
	sort(arr.begin(),arr.end());
	if((arr.size() & 1) == 1)
		arr = process(arr,1,arr.size() - 1);
	else
	{
		arr = process(arr,0,arr.size() - 1);
		for(int i = 0;i<arr.size();i += 2)
		{
			int tmp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = tmp;
		}
	}
	return arr;
}
int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	vector<int> res= shuffle(arr);
	for(int i = 0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
	vector<int> arr1 = {1,2,3,4,5,6};
	res= wiggleSort(arr1);
	for(int i = 0;i<res.size();i++)
		cout<<res[i]<<" ";
	return 0;
}
