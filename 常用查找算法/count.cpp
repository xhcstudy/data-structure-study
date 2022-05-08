#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <string>

//count(iterator beg, iterator end, value);		统计元素个数 返回int

//统计内置数据类型
//void Test1()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(40);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(20);
//	v.push_back(40);
//
//	int num = count(v.begin(), v.end(), 40);
//	cout << "40的元素个数为: " << num << endl;
//}
//
////统计自定义数据类型
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
//	bool operator==(const Person &p)
//	{
//		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
//		{
//			return true;
//		}
//		return false;
//	}
//	string m_Name;
//	int m_Age;
//};
//
//void Test2()
//{
//	vector<Person> v;
//	
//	//准备数据
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 20);
//	Person p4("ccc", 20);
//	Person p5("aaa", 40);
//	Person p6("ddd", 10);
//	Person p7("bbb", 20);
//	Person p8("aaa", 10);
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	v.push_back(p6);
//	v.push_back(p7);
//	v.push_back(p8);
//
//	Person pp("ddd", 10);
//	int num = count(v.begin(), v.end(), pp);
//	cout << "pp的元素个数为: " << num << endl;
//}
//int main()
//{
//	//Test1();
//	Test2();
//
//	system("pause");
//	return 0;
//}