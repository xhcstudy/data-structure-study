#define _CRT_SECURE_NO_WARNINGS 1

//案例描述：选手ABCDE，10个评委分别对每一名选手打分，去掉最高分，去除评委中最低分，取平均分。

#include <iostream>
using namespace std;
#include "Build.h"
#include "GetScore.h"
#include "ShowScore.h"
#include <time.h>

int main()
{
	//添加随机数种子
	srand((unsigned int)time(NULL));

	//1、创建n名选手
	vector<Person> v;
	Build(v, 5);
	//测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名:" << it->m_Name
	//		<< "\t得分:" << it->m_Score << endl;
	//}

	//2、n个评委打分
	deque<int> d;  //存放每个选手的分数
	GetScore(v, d, 10);
	//测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名:" << it->m_Name
	//		<< "\t得分:" << it->m_Score << endl;
	//}

	//3、显示每个选手的平均分
	ShowScore(v);

	system("pause");
	return 0;
}