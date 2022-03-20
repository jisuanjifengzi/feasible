#include<iostream>
#include<windows.h >
using namespace std;
template <class T>
class LinkedStack;    
template <class T>
class Node {
	friend LinkedStack<T>;
private:
	T data;
	Node<T>* link;
};

template<class T>
class LinkedStack {
public:
	LinkedStack() {   //构造函数
		top = 0;
	}
	~LinkedStack();
	bool IsEmpty() const
	{
		return top == 0;
	}
	T Top() const;
	LinkedStack<T>& push(const T& x);
	LinkedStack<T>& pop();
	bool findPath();
	void init();
	void randomMaze();
	bool setPathOnMaze();
	void outputMaze();
	void set(int m, int n) {     //改变maze_size的值
		maze_size.row = m;
		maze_size.col = n;
	}
private:
	Node<T>* top; // 指向栈顶节点
	T maze_size = { 20,30 };   //默认为20*30的大小
	int** const maze = new int* [maze_size.row + 2];   //二维数组用于储存
	T offset[4];  //存储位置信息

};
template<class T>    //析构函数
LinkedStack<T>::~LinkedStack()
{
	Node<T>* node;
	while (top) {
		node = top->link;
		delete top;
		top = node;
	}
}
template<class T>     //获得栈顶元素数据
T LinkedStack<T>::Top() const {
	if (IsEmpty()) { cout << "栈为空" << endl; }
	return top->data;
}
template<class T>
LinkedStack<T>& LinkedStack<T>::push(const T& x) {    //栈里面添加元素
	Node<T>* next = new Node<T>;
	next->data = x;
	next->link = top;
	top = next;
	return *this;
}
template<class T>
LinkedStack<T>& LinkedStack<T>::pop() {   //栈里面删除元素
	Node<T>* next = top;
	top = top->link;
	delete next;
	return *this;
}
template<class T>
void LinkedStack<T>::init()
{

	//偏移
	offset[0].row = 0; offset[0].col = 1; //right
	offset[1].row = 1; offset[1].col = 0; //down
	offset[2].row = 0; offset[2].col = -1; //left
	offset[3].row = -1; offset[3].col = 0; //up

	for (int i = 0; i < maze_size.row + 2; i++)
	{
		maze[i] = new int[maze_size.col + 2];
	}
}

template<class T>
void LinkedStack<T>::randomMaze()
{
	int i, j, rate;

	for (i = 0; i < maze_size.row + 2; i++)
	{
		for (j = 0; j < maze_size.col + 2; j++)
		{
			//设置围墙
			if ((i == 0) || (i == maze_size.row + 1) || (j == 0) || (j == maze_size.col + 1))
			{
				maze[i][j] = 5;
			}
			else
			{
				rate = rand() % 10 + 1;   //使用随机数方法，产生随机数1-10
				if (rate <= 2)
				{
					maze[i][j] = 1;//随机生成障碍
				}
				else
				{
					maze[i][j] = 0;
				}
			}
		}
	}
	//最后保证起点和终点能走
	maze[1][1] = maze[maze_size.row][maze_size.col] = 0;
}

template<class T>
bool LinkedStack<T>::findPath()
{
	//POSITION here;//当前位置
	//cout << "good1" << endl;
	T here;
	here.row = here.col = 1;
	maze[1][1] = 3; //放置障碍，防止回来
	int option = 0; //next step
	const int lastOption = 3;

	//find a path
	while (here.row != maze_size.row || here.col != maze_size.col)
	{
		//not reach the end
		int r, c;
		while (option <= lastOption)
		{
			r = here.row + offset[option].row;
			c = here.col + offset[option].col;
			if (maze[r][c] == 0)
			{
				break;
			}
			option++;//next choice
		}

		//相邻的位置能走？
		if (option <= lastOption)
		{
			push(here);
			here.row = r;
			here.col = c;
			maze[r][c] = 3; //走过了
			option = 0;
		}
		else
		{
			if (IsEmpty())
			{
				return false;
			}
			//go back
			maze[here.row][here.col] = 3; //此路不可通
			here = Top();
			pop();
			option = 0;
		}
	}

	maze[maze_size.row][maze_size.col] = 2;
	return true;
}

template<class T>
bool LinkedStack<T>::setPathOnMaze()    //将栈里面的数据输出给maze数组的值，设为2
{
	T pos;
	if (IsEmpty()) {
		cout << endl;
		cout << "经过尝试，迷宫没有出路" << endl;
		return false;
	}
	while (!IsEmpty())
	{
		pos = Top();
		pop();
		maze[pos.row][pos.col] = 2;//路径
	}
	return true;
}


template<class T>
void LinkedStack<T>::outputMaze()
{
	int i, j;
	for (i = 0; i < maze_size.row + 2; i++)
	{
		for (j = 0; j < maze_size.col + 2; j++)
		{
			if (maze[i][j] == 1)
			{
				cout << "1" << " ";

			}
			else if ((maze[i][j] == 0) || (maze[i][j] == 3))
			{

				cout << "0" << " ";
			}
			else if (maze[i][j] == 5)
			{

			}
			else
			{
				HANDLE hOut;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "#" << " ";
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		}
		cout << endl;
	}
}
typedef struct
{
	int row;
	int col;
}POSITION;    //使用结构体 POSITION，来初始化位置信息

int main()
{
	cout << "请输入迷宫的长和宽,等下会随机生成迷宫" << endl;
	int m, n;
	cin >> m >> n;
	LinkedStack<POSITION> path;
	path.set(m, n);
	path.init();

	path.randomMaze();
	path.outputMaze();
	cout << "**********************************************************" << endl;
	path.findPath();
	if (path.setPathOnMaze()) {

		path.outputMaze();
	}
	return 0;
}
