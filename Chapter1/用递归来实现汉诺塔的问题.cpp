#include <iostream>
#include <string>

using namespace std;

int hanoiRes(int layer,string src,string dst)
{
	if(layer<1)
	return 0;
	if(layer == 1) //只有一层时（递归的退出检测）
	{
		if(src == "mid" || dst == "mid")
		{
			cout << "move 1 form " << src << " to " << dst << endl;
			return 1;
		}
		else //源端或目的端为非中间的情况（左/右）
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
        //第一步，将1～layer-1层从源端移动到辅助端
        int step1 = hanoiRes(layer-1,src,help);
        //第二步，将第layer层移动到目的端
        int step2 = 1;
        cout << "move " << layer << " from " << src << " to " << help << endl;
        //第三步，将1～layer-1层从辅助端移动到目的端
        int step3 = hanoiRes(layer-1,help,dst);
		return step1+step2+step3;
			
	}
	else
	{
        //第一步，将1～layer-1层从源端移动到目的端
        int step1 = hanoiRes(layer-1,src,dst);
        //第二步，将第layer层从源端移动到mid端（即mid端为辅助端）
        int step2 = 1;
        cout << "move " << layer << " from " << src << " to mid" << endl;
        //第三步，将1～layer-1层从目的端移动到源端
        int step3 = hanoiRes(layer-1,dst,src);
        //第四步，将第layer层从mid端移动到目的端
        int step4 = 1;
        cout << "move " << layer << " from mid to " << dst << endl;
        //第五步，将1～layer-1层从源端移动到目的端
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
