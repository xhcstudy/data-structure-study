#define _CRT_SECURE_NO_WARNINGS 1

#include "Build.h"

void Build(vector<Person> &v, int n)//����n��ѡ��
{
	for (int i = 0; i < n; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;
		Person p(name, score);

		//�������Ķ������������
		v.push_back(p);
	}
}