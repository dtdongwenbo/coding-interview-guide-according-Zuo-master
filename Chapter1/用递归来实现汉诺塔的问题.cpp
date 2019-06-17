#include <iostream>
#include <string>

using namespace std;

int hanoiRes(int layer,string src,string dst)
{
	if(layer<1)
	return 0;
	if(layer == 1) //ֻ��һ��ʱ���ݹ���˳���⣩
	{
		if(src == "mid" || dst == "mid")
		{
			cout << "move 1 form " << src << " to " << dst << endl;
			return 1;
		}
		else //Դ�˻�Ŀ�Ķ�Ϊ���м���������/�ң�
		{
			cout << "move 1 form " << src << " to mid" << endl;
            cout << "move 1 form mid to " << dst << endl;
            return 2;
		}
	}
	if(src == "mid" || dst == "mid")
	{
		string help;
		if(src == "left" || dst == "left")
			help = "right"; 

		else if(src == "right" || dst == "right")
			help = "left";
        //��һ������1��layer-1���Դ���ƶ���������
        int step1 = hanoiRes(layer-1,src,help);
        //�ڶ���������layer���ƶ���Ŀ�Ķ�
        int step2 = 1;
        cout << "move " << layer << " from " << src << " to " << help << endl;
        //����������1��layer-1��Ӹ������ƶ���Ŀ�Ķ�
        int step3 = hanoiRes(layer-1,help,dst);
		return step1+step2+step3;
			
	}
	else
	{
        //��һ������1��layer-1���Դ���ƶ���Ŀ�Ķ�
        int step1 = hanoiRes(layer-1,src,dst);
        //�ڶ���������layer���Դ���ƶ���mid�ˣ���mid��Ϊ�����ˣ�
        int step2 = 1;
        cout << "move " << layer << " from " << src << " to mid" << endl;
        //����������1��layer-1���Ŀ�Ķ��ƶ���Դ��
        int step3 = hanoiRes(layer-1,dst,src);
        //���Ĳ�������layer���mid���ƶ���Ŀ�Ķ�
        int step4 = 1;
        cout << "move " << layer << " from mid to " << dst << endl;
        //���岽����1��layer-1���Դ���ƶ���Ŀ�Ķ�
        int step5 = hanoiRes(layer-1,src,dst);
		return step1+step2+step3+step4+step5;
	}
}
int main()
{
	int step = hanoiRes(2,"left","right");
	cout << "It will move " << step << " steps." << endl;
    return 0;
}
