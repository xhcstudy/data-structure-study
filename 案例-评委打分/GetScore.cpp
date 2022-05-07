#define _CRT_SECURE_NO_WARNINGS 1

#include "GetScore.h"

void GetScore(vector<Person>&v, deque<int>&d, int n)
{
	for (vector<Person>::iterator vit = v.begin(); vit != v.end(); vit++)
	{
		//打分并且存放到deque容器中
		for (int i = 0; i < n; i++)
		{
			vit->m_Score = rand() % 41 + 60;  //60 ~ 100
			d.push_back(vit->m_Score);
		}

		//排序之后去除最高分和最低分
		sort(d.begin(), d.end());
		d.pop_front();
		d.pop_back();
		
		//求平均分之后将分数放入vector容器
		int average = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			average += *dit;
		}
		average /= (n - 2);
		vit->m_Score = average;
		d.clear();
	}
}