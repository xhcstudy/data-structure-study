#define _CRT_SECURE_NO_WARNINGS 1

#include "Build.h"

void Build(vector<Person> &v, int n)//创建n个选手
{
	for (int i = 0; i < n; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;
		Person p(name, score);

		//将创建的对象放入容器中
		v.push_back(p);
	}
}