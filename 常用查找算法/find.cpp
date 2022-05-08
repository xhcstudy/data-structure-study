#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <string>

//常用查找算法
//find		查找元素
//find_if   按条件查找元素
//adjacent_find  查找相邻重复元素
//binary_search  二分查找法
//count       统计元素个数
//count_if    按条件统计元素个数

//find 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

//查找内置数据类型
//void Test1()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	//查找容器中是否有5这个元素
//	vector<int>::iterator pos = find(v.begin(), v.end(), 50);
//	if (pos == v.end())
//	{
//		cout << "没有找到！" << endl;
//	}
//	else
//	{
//		cout << "找到了:" << *pos << endl;
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
//	//重载==  底层find知道如何对比Person数类型
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
////查找自定义数据类型	底层就是一个循环 判断相等的时候就直接break，所以需要重载==号就能使用
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
//	//放入容器
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//
//	Person ppp("bbb", 20);
//	vector<Person>::iterator pos = find(v.begin(), v.end(), ppp);
//	if (pos == v.end())
//	{
//		cout << "没有找到！" << endl;
//	}
//	else
//	{
//		cout << "找到了" << endl
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