#include <graphics.h>// 引用图形库头文件
#include <conio.h>//_getch()函数头文件，暂停函数
#include <stack>
#include<iostream>
#include<cmath>//math计算
using namespace std;
//_getch()函数
//a 下一步       97
//d 上一步       100
//空格   暂停    32S
//ESC    退出    27
int length, side = 15;//整个正方形的边长和单个方格的边长
int choose = 2;//判断是否分步进行演示，默认为自动进行
struct coord {//记录当前T型骨牌。
	int _midline;
	int _midlist;
	int _area;
};
stack<coord>s1, s2;//s1存储每一次渲染T型骨牌的位置，s2存储从s1中弹出的数据
void chessborder(int x1, int y1, int x2, int y2, int xp, int yp, int k);
void substep();
int main()
{
	int k;
	cout << "请输入k的值:"; cin >> k;
	if (k <= 0)
	{
		cout << "请输入正确的数值!" << endl;
		return 0;
	}
	cout << "请选择手动进行还是自动进行" << endl;
	cout << "1.手动进行   2.自动进行" << endl;
	cin >> choose;
	initgraph(500, 500);//初始化控制台图形，大小为500*500.
	length = pow(2, k);//2的k次方计算
	setfillcolor(WHITE);//设置当前填充的颜色：白色
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++)
			rectangle(side * j, side * i, side * (j + 1), side * (i + 1));//在设定好的范围里面画矩形
	srand((unsigned)time(NULL));//用于给rand()函数设定种子，参数seed是rand()的种子，用来初始化rand()的起始值
	int x = rand() % length * side;//特殊方格的横轴坐标
	int y = rand() % length * side;//特殊方格的纵轴坐标
	setfillcolor(WHITE);//设置颜色白色
	fillrectangle(x, y, x + side, y + side);// 画填充矩形(有边框)
	chessborder(0, 0, length * side, length * side, x, y, k);
	_getch();           // 按任意键关闭
	closegraph();          // 关闭绘图窗口
	return 0;
}
void substep();
void turnback()//返回上一步
{
	if (s1.empty() || s1.size() == 1)
	{
		cout << "程序出错，无上一步可以返回。" << endl;
		exit(0);
	}
	coord temp = s1.top();
	s1.pop(); s2.push(temp);
	temp = s1.top();
	setfillcolor(BLACK);
	switch (temp._area) {
	case 1:fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 2:fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 3:fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 4:fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
	}
	substep();
}
void turnfront()
{
	coord temp = s1.top(); s1.push(s2.top());
	s2.pop();
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	switch (temp._area) {
	case 1: fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 2:fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 3:fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 4: fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
	}
	substep();
}
void substep()//选择操作
{
	int temp = _getch();
	switch (temp) {
	case 97:if (!s2.empty())turnfront(); break;
	case 100:turnback(); break;
	case 27:exit(0);
	default:substep(); break;
	}
}
void chessborder(int x1, int y1, int x2, int y2, int xp, int yp, int k)
//x1，x2，y1，y2分别为该区域的上、下、左、右边界在整个图形中的位置
//xp，yp为特殊方块所在的位置
//k为判断当前所在四个小区域是否都被填满
{
	if (k == 0)return;//退出迭代。
	Sleep(100);        //看到递归过程，数字越大图形变换越慢
	int area;
	int midline = (x1 + x2) / 2, midlist = (y1 + y2) / 2;//获取中心位置,midline为横轴中线，midlist为纵轴中线
	if (xp < midline)//判断当前在哪一个象限.
		if (yp < midlist)area = 1;
		else area = 3;
	else if (yp < midlist)area = 2;
	else area = 4;
	coord c_temp;
	c_temp._midline = midline;
	c_temp._midlist = midlist;
	c_temp._area = area;
	s1.push(c_temp);
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	switch (area)
	{
	case 1://第一象限时所进行的操作
		if (choose == 1)substep();// 按任意键进行下一步操作。
		//填充T型骨牌
		fillrectangle(midline, midlist - side, midline + side, midlist);
		fillrectangle(midline - side, midlist, midline, midlist + side);
		fillrectangle(midline, midlist, midline + side, midlist + side);
		//迭代
		chessborder(x1, y1, midline, midlist, xp, yp, k - 1);//第一象限
		chessborder(midline, y1, x2, midlist, midline, midlist - side, k - 1);//第二象限
		chessborder(x1, midlist, midline, y2, midline - side, midlist, k - 1);//第三象限
		chessborder(midline, midlist, x2, y2, midline, midlist, k - 1);//第四象限
		break;
	case 2://第二象限时所进行的操作
		if (choose == 1)substep();
		//填充T型骨牌
		fillrectangle(midline - side, midlist - side, midline, midlist);
		fillrectangle(midline - side, midlist, midline, midlist + side);
		fillrectangle(midline, midlist, midline + side, midlist + side);
		//迭代
		chessborder(x1, y1, midline, midlist, midline - side, midlist - side, k - 1);//第一象限
		chessborder(midline, y1, x2, midlist, xp, yp, k - 1);//第二象限
		chessborder(x1, midlist, midline, y2, midline - side, midlist, k - 1);//第三象限
		chessborder(midline, midlist, x2, y2, midline, midlist, k - 1);//第四象限
		break;
	case 3://第三象限时所进行的操作
		if (choose == 1)substep();
		//填充T型骨牌
		fillrectangle(midline - side, midlist - side, midline, midlist);
		fillrectangle(midline, midlist - side, midline + side, midlist);
		fillrectangle(midline, midlist, midline + side, midlist + side);
		//迭代
		chessborder(x1, y1, midline, midlist, midline - side, midlist - side, k - 1);	//第一象限
		chessborder(midline, y1, x2, midlist, midline, midlist - side, k - 1);//第二象限
		chessborder(x1, midlist, midline, y2, xp, yp, k - 1);//第三象限
		chessborder(midline, midlist, x2, y2, midline, midlist, k - 1);//第四象限
		break;
	case 4://第四象限时所进行的操作
		if (choose == 1)substep();
		//填充T型骨牌
		fillrectangle(midline - side, midlist - side, midline, midlist);
		fillrectangle(midline, midlist - side, midline + side, midlist);
		fillrectangle(midline - side, midlist, midline, midlist + side);
		//迭代
		chessborder(x1, y1, midline, midlist, midline - side, midlist - side, k - 1);	//第一象限
		chessborder(midline, y1, x2, midlist, midline, midlist - side, k - 1);//第二象限
		chessborder(x1, midlist, midline, y2, midline - side, midlist, k - 1);//第三象限
		chessborder(midline, midlist, x2, y2, xp, yp, k - 1);//第四象限
		break;
	default:
		break;
	}
}