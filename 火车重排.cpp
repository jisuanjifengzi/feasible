#include<iostream>
#include<malloc.h>
#include<string>
#include<queue>
using namespace std;


void enter(int train[10],int num)
{
	queue<int>h[3];//构建了三个队列，实际上只有h[1]和h[2]在使用
	queue<int>injection;//构建一个用于存储入轨车厢的队列，通过队列可以方便与其他两个缓冲轨交互
	int all[10] = {};//存储最后排列好的车厢
	int size = 0;
	int nowOut = 1;
	int b = 0;
	for (int i = 0; i < num; i++)
	{
		injection.push(train[i]);//原车厢依次进对列
	}
	for (int i = 0; i <= num; i++)
	{
		if (injection.empty())//当入轨元素没有后直接退出这个循环，这时候会有两种情况，一种是所有车厢已经全部按正确顺序排列出去第二种是两个缓冲轨还有车厢，这时候只需要这两个队列和nowOut进行对比即可
		{
			break;
		}
    if (injection.front() == nowOut)//如果入轨队首车厢编号就是对应的nowOut那么就直接出列输出
	{
		all[b] = injection.front();
		injection.pop();
		nowOut++;
		b++;
		continue;
	}
	else
	{
		if (!h[1].empty() && !h[2].empty())//否则若这两个缓冲轨都有元素进入了，那么就在这两个队列里找是否有对应的编号
		{ 
        for (int j = 1; j <= 2; j++)
		{
			int c = h[j].front();
			if (c == nowOut)
			{
				all[b] = h[j].front();
				h[j].pop();
				nowOut++;
				b++;
				break;//找到了直接退出这次的循环开始下一次的
			}
		}
	    }
		
	}
	if (h[1].empty() && h[2].empty())//如果两个缓冲轨是空的并且入轨元素不是nowOut那么就先将这个入轨元素放到h[1]
	{
		if (injection.front() != nowOut)
		{
			h[1].push(injection.front());
			injection.pop();
			
			continue;
		}
	}
	if (!h[1].empty()&&h[2].empty())//判断如果现在的入轨元素是大于h[1]的队尾元素，那么就进入h[1]否则进入h[2]
	{
		
			if (injection.front() > h[1].back())
			{
				h[1].push(injection.front());
				injection.pop();
                if (h[1].front() == nowOut)//入列后如果发现h[1]的队首元素是对应nowOut的那么就输出
		        {
			     all[b] = h[1].front();
			     h[1].pop();
				 nowOut++;
				 b++;
		        }
				 continue;
			}
			else {
				h[2].push(injection.front());
				injection.pop();
				continue;
			}
		
		
	}
	if (injection.front()!=nowOut)//如果现在三个队列队首都没有对应的nowOut元素那么就判断入轨的队首元素与缓冲轨中哪个大的元素更接近。并且还要比这个元素大，之后就放入对应的队列队尾
	{
			if(h[1].front()!=nowOut)
			{
				if (h[2].front() != nowOut)
				{
        int b1 = 0;
		int b2 = 0;
		int max = 0;
		int e = injection.front();
		if (e > h[1].back())
		{
			b1 = h[1].back();
	    }
		if (e > h[2].back())
		{
			b2 = h[2].back();
		}
		if (b1 >= b2)
			max = b1;
		else
			max = b2;
		
		if (max == b1)
		{
			if (injection.front() > h[1].front())
			{
            h[1].push(injection.front());
			injection.pop();
			 continue;
		    }
			if(injection.front()>h[2].front()) 
			{
				h[2].push(injection.front());
				injection.pop();
				 continue;
			}
		}
		if (max == b2)
		{
			if (injection.front() > h[2].front())
			{
				h[2].push(injection.front());
				injection.pop();
				 continue;
			}
			if (injection.front() > h[1].front())
			{
				h[1].push(injection.front());
				injection.pop();
				 continue;
			}
			continue;
		}
				}
			    if(h[2].front()==nowOut)//如果h[2]队首是nowOut那就输出这个元素。
				{ 
					all[b] = h[2].front();
					h[2].pop();
					h[2].push(injection.front());
					injection.pop();
					nowOut++;
					b++;
					continue;
				}
			}
		
	}
	}
	for (int u = b; u <num; )//考虑到可能h[1]h2[]会有剩下的车厢没有输出，那么就在这两个队列进行寻找，找到后输出然后nowOut加一继续找，直到两个队列全部找空为止
	{
		if (!h[1].empty())
		{
			if (h[1].front() == nowOut)
			{
				all[u] = h[1].front();
				h[1].pop();
				u++;
				nowOut++;
			}
		}
		if (!h[2].empty())
		{
			if (h[2].front()==nowOut)
			{
				all[u] = h[2].front();
				h[2].pop();
				u++;
				nowOut++;
			}
			
		}
	}
	for (int c = 0; c < num; c++)
	{
		cout << all[c]<<" ";
	}
	cout << endl;
}
int main() {
	int b = 0;
	int core = 0;
	
	cout << "请输入车厢总数" << endl;
	cin >> b;
	cout << "将原车厢编号依次输出" << endl;
	int train[10] = {  };

	for (int i = 0; i < b; i++)
	{
		cin >> core;
		train[i] = core;
	}
	enter(train,b);
}