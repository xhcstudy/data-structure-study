#define _CRT_SECURE_NO_WARNINGS 1

#include "GetScore.h"

void GetScore(vector<Person>&v, deque<int>&d, int n)
{
	for (vector<Person>::iterator vit = v.begin(); vit != v.end(); vit++)
	{
		//��ֲ��Ҵ�ŵ�deque������
		for (int i = 0; i < n; i++)
		{
			vit->m_Score = rand() % 41 + 60;  //60 ~ 100
			d.push_back(vit->m_Score);
		}

		//����֮��ȥ����߷ֺ���ͷ�
		sort(d.begin(), d.end());
		d.pop_front();
		d.pop_back();
		
		//��ƽ����֮�󽫷�������vector����
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