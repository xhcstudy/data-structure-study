#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

//find_if(iterator beg, iterator end, _Pred)  _Pred 谓词或者函数
//底层  遍历之后判断  返回迭代器
//if (_Pred(*_First))
//break;

//内置数据类型

//class GreaterFive
//{
//public:
//	bool operator()(int val)
//	{
//		return val > 5;
//	}
//};
//
//void Test1()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
//	if (pos == v.end())
//	{
//		cout << "找不到！" << endl;
//	}
//	else
//	{
//		cout << "找到了为:" << *pos << endl;
//	}
//}
//
////自定义数据类型
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
//	string m_Name;
//	int m_Age;
//};
//
//class Greater
//{
//public:
//	bool operator()(const Person &p)
//	{
//		return p.m_Age > 20;
//	}
//};
//
//void Test2()
//{
//	vector<Person> v;
//
//	//创建数据
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//
//	
//	vector<Person>::iterator pos = find_if(v.begin(), v.end(), Greater());
//	if (pos == v.end())
//	{
//		cout << "找不到！" << endl;
//	}
//	else
//	{
//		cout << "找到了:" << endl
//			<< "姓名:" << pos->m_Name
//			<< "\t年龄:" << pos->m_Age << endl;
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