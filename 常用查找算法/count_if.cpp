#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//count_if(iterator beg, iterator end, _Pred);

//内置数据类型

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

	//统计大于20的数
	int num = count_if(v.begin(), v.end(), Greater20());
	cout << "容器中大于20的数的个数:" << num << endl;
}

//自定义数据类型

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
	
	//准备数据
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 40);
	Person p5("曹操", 20);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//统计 大于20岁的人员个数
	int num = count_if(v.begin(), v.end(), Greater());
	cout << "容器中年龄大于20岁的人员个数为:" << num << endl;
}

int main()
{
	//Test1();
	Test2();

	system("pause");
	return 0;
}