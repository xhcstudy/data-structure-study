#define _CRT_SECURE_NO_WARNINGS 1

//����������ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�

#include <iostream>
using namespace std;
#include "Build.h"
#include "GetScore.h"
#include "ShowScore.h"
#include <time.h>

int main()
{
	//������������
	srand((unsigned int)time(NULL));

	//1������n��ѡ��
	vector<Person> v;
	Build(v, 5);
	//����
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "����:" << it->m_Name
	//		<< "\t�÷�:" << it->m_Score << endl;
	//}

	//2��n����ί���
	deque<int> d;  //���ÿ��ѡ�ֵķ���
	GetScore(v, d, 10);
	//����
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "����:" << it->m_Name
	//		<< "\t�÷�:" << it->m_Score << endl;
	//}

	//3����ʾÿ��ѡ�ֵ�ƽ����
	ShowScore(v);

	system("pause");
	return 0;
}