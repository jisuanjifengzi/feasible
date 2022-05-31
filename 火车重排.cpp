
#include<iostream>
#include<malloc.h>
#include<string>
#include<queue>
using namespace std;


void enter(int train[10],int num)
{
	queue<int>h[3];//�������������У�ʵ����ֻ��h[1]��h[2]��ʹ��
	queue<int>injection;//����һ�����ڴ洢��쳵��Ķ��У�ͨ�����п��Է�����������������콻��
	int all[10] = {};//�洢������кõĳ���
	int size = 0;
	int nowOut = 1;
	int b = 0;
	for (int i = 0; i < num; i++)
	{
		injection.push(train[i]);//ԭ�������ν�����
	}
	for (int i = 0; i <= num; i++)
	{
		if (injection.empty())//�����Ԫ��û�к�ֱ���˳����ѭ������ʱ��������������һ�������г����Ѿ�ȫ������ȷ˳�����г�ȥ�ڶ�������������컹�г��ᣬ��ʱ��ֻ��Ҫ���������к�nowOut���жԱȼ���
		{
			break;
		}
    if (injection.front() == nowOut)//��������׳����ž��Ƕ�Ӧ��nowOut��ô��ֱ�ӳ������
	{
		all[b] = injection.front();
		injection.pop();
		nowOut++;
		b++;
		continue;
	}
	else
	{
		if (!h[1].empty() && !h[2].empty())//����������������춼��Ԫ�ؽ����ˣ���ô�������������������Ƿ��ж�Ӧ�ı��
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
				break;//�ҵ���ֱ���˳���ε�ѭ����ʼ��һ�ε�
			}
		}
	    }
		
	}
	if (h[1].empty() && h[2].empty())//�������������ǿյĲ������Ԫ�ز���nowOut��ô���Ƚ�������Ԫ�طŵ�h[1]
	{
		if (injection.front() != nowOut)
		{
			h[1].push(injection.front());
			injection.pop();
			
			continue;
		}
	}
	if (!h[1].empty()&&h[2].empty())//�ж�������ڵ����Ԫ���Ǵ���h[1]�Ķ�βԪ�أ���ô�ͽ���h[1]�������h[2]
	{
		
			if (injection.front() > h[1].back())
			{
				h[1].push(injection.front());
				injection.pop();
                if (h[1].front() == nowOut)//���к��������h[1]�Ķ���Ԫ���Ƕ�ӦnowOut����ô�����
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
	if (injection.front()!=nowOut)//��������������ж��׶�û�ж�Ӧ��nowOutԪ����ô���ж����Ķ���Ԫ���뻺������ĸ����Ԫ�ظ��ӽ������һ�Ҫ�����Ԫ�ش�֮��ͷ����Ӧ�Ķ��ж�β
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
			    if(h[2].front()==nowOut)//���h[2]������nowOut�Ǿ�������Ԫ�ء�
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
	for (int u = b; u <num; )//���ǵ�����h[1]h2[]����ʣ�µĳ���û���������ô�������������н���Ѱ�ң��ҵ������Ȼ��nowOut��һ�����ң�ֱ����������ȫ���ҿ�Ϊֹ
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
	
	cout << "�����복������" << endl;
	cin >> b;
	cout << "��ԭ�������������" << endl;
	int train[10] = {  };

	for (int i = 0; i < b; i++)
	{
		cin >> core;
		train[i] = core;
	}
	enter(train,b);
}