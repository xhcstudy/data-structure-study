#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <string>

//���ò����㷨
//find		����Ԫ��
//find_if   ����������Ԫ��
//adjacent_find  ���������ظ�Ԫ��
//binary_search  ���ֲ��ҷ�
//count       ͳ��Ԫ�ظ���
//count_if    ������ͳ��Ԫ�ظ���

//find ����ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������end()

//����������������
//void Test1()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	//�����������Ƿ���5���Ԫ��
//	vector<int>::iterator pos = find(v.begin(), v.end(), 50);
//	if (pos == v.end())
//	{
//		cout << "û���ҵ���" << endl;
//	}
//	else
//	{
//		cout << "�ҵ���:" << *pos << endl;
//	}
//}
//
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//	//����==  �ײ�find֪����ζԱ�Person������
//	bool operator==(const Person &p)
//	{
//		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//		{
//			return true;
//		}
//		return false;
//	}
//	string m_Name;
//	int m_Age;
//};
//
////�����Զ�����������	�ײ����һ��ѭ�� �ж���ȵ�ʱ���ֱ��break��������Ҫ����==�ž���ʹ��
//void Test2()
//{
//	vector<Person> v;
//
//	//��������
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//
//	//��������
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//
//	Person ppp("bbb", 20);
//	vector<Person>::iterator pos = find(v.begin(), v.end(), ppp);
//	if (pos == v.end())
//	{
//		cout << "û���ҵ���" << endl;
//	}
//	else
//	{
//		cout << "�ҵ���" << endl
//			<< "����:" << pos->m_Name
//			<< "\t����:" << pos->m_Age << endl;
//	}
//}
//
//int main()
//{
//	//Test1();
//	Test2();
//
//	system("pause");
//	return 0;
//}