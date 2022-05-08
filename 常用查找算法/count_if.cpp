#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//count_if(iterator beg, iterator end, _Pred);

//������������

class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

void Test1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);
	v.push_back(80);

	//ͳ�ƴ���20����
	int num = count_if(v.begin(), v.end(), Greater20());
	cout << "�����д���20�����ĸ���:" << num << endl;
}

//�Զ�����������

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

class Greater
{
public:
	bool operator()(const Person &p)
	{
		return p.m_Age > 20;
	}
};

void Test2()
{
	vector<Person> v;
	
	//׼������
	Person p1("����", 35);
	Person p2("����", 35);
	Person p3("�ŷ�", 35);
	Person p4("����", 40);
	Person p5("�ܲ�", 20);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//ͳ�� ����20�����Ա����
	int num = count_if(v.begin(), v.end(), Greater());
	cout << "�������������20�����Ա����Ϊ:" << num << endl;
}

int main()
{
	//Test1();
	Test2();

	system("pause");
	return 0;
}