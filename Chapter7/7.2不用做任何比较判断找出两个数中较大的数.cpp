 #include <iostream>
 
 using namespace std;
 
 int flip(int n)
 {
 	return n^1;
 }
 int sign(int n)
 {
 	return flip((n>>31)&1);//�����Ժ��жϷ���λ 
 }
 int getMax1(int a,int b)
 {
 	int c = a - b;
 	int scA = sign(c);//����c�ķ��ţ�������0����1
	int scB = flip(scA);//nΪ1����0��nΪ0����1
	return a * scA + b*scB; 
 }
 int getMax2(int a,int b)
 {
 	int c = a - b;
 	int sa = sign(a);
 	int sb = sign(b);
 	int sc = sign(c);
 	int difsab = sa ^ sb;
 	int samsab = flip(difsab);
 	int returnA = difsab * sa + samsab * sc;
 	int returnB = flip(returnA);
 	return returnA * a + returnB * b;
  } 
 int main()
 {
 	
 	int a = -10;
 	int b = 20;
 	cout<<getMax1(a,b)<<endl;//����������ķ��� 
 	cout<<getMax2(a,b)<<endl;
 	return 0;
 }
