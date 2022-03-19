#include<iostream>
#include<windows.h >
using namespace std;
template <class T>
class LinkedStack;    //ʹ����ģ����
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
	LinkedStack() {   //���캯��
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
	void set(int m, int n) {     //�ı�maze_size��ֵ
		maze_size.row = m;
		maze_size.col = n;
	}
private:
	Node<T>* top; // ָ��ջ���ڵ�
	T maze_size = { 20,30 };   //Ĭ��Ϊ20*30�Ĵ�С
	int** const maze = new int* [maze_size.row + 2];   //��ά�������ڴ���
	T offset[4];  //�洢λ����Ϣ

};
template<class T>    //��������
LinkedStack<T>::~LinkedStack()
{
	Node<T>* node;
	while (top) {
		node = top->link;
		delete top;
		top = node;
	}
}
template<class T>     //���ջ��Ԫ������
T LinkedStack<T>::Top() const {
	if (IsEmpty()) { cout << "ջΪ��" << endl; }
	return top->data;
}
template<class T>
LinkedStack<T>& LinkedStack<T>::push(const T& x) {    //ջ�������Ԫ��
	Node<T>* next = new Node<T>;
	next->data = x;
	next->link = top;
	top = next;
	return *this;
}
template<class T>
LinkedStack<T>& LinkedStack<T>::pop() {   //ջ����ɾ��Ԫ��
	Node<T>* next = top;
	top = top->link;
	delete next;
	return *this;
}
template<class T>
void LinkedStack<T>::init()
{

	//ƫ��
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
			//����Χǽ
			if ((i == 0) || (i == maze_size.row + 1) || (j == 0) || (j == maze_size.col + 1))
			{
				maze[i][j] = 5;
			}
			else
			{
				rate = rand() % 10 + 1;   //ʹ����������������������1-10
				if (rate <= 2)
				{
					maze[i][j] = 1;//��������ϰ�
				}
				else
				{
					maze[i][j] = 0;
				}
			}
		}
	}
	//���֤�����յ�����
	maze[1][1] = maze[maze_size.row][maze_size.col] = 0;
}

template<class T>
bool LinkedStack<T>::findPath()
{
	//POSITION here;//��ǰλ��
	//cout << "good1" << endl;
	T here;
	here.row = here.col = 1;
	maze[1][1] = 3; //�����ϰ�����ֹ����
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

		//���ڵ�λ�����ߣ�
		if (option <= lastOption)
		{
			push(here);
			here.row = r;
			here.col = c;
			maze[r][c] = 3; //�߹���
			option = 0;
		}
		else
		{
			if (IsEmpty())
			{
				return false;
			}
			//go back
			maze[here.row][here.col] = 3; //��·����ͨ
			here = Top();
			pop();
			option = 0;
		}
	}

	maze[maze_size.row][maze_size.col] = 2;
	return true;
}

template<class T>
bool LinkedStack<T>::setPathOnMaze()    //��ջ��������������maze�����ֵ����Ϊ2
{
	T pos;
	if (IsEmpty()) {
		cout << endl;
		cout << "�������ԣ��Թ�û�г�·" << endl;
		return false;
	}
	while (!IsEmpty())
	{
		pos = Top();
		pop();
		maze[pos.row][pos.col] = 2;//·��
	}
	return true;
}

//Ȼ�󣬿��Կ�ʼ������ǵĵ�ͼ�ˡ�
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
}POSITION;    //ʹ�ýṹ�� POSITION������ʼ��λ����Ϣ

int main()
{
	cout << "�������Թ��ĳ��Ϳ�,���»���������Թ�" << endl;
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