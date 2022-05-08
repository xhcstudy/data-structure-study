#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//adjacent_find(iterator beg, iterator end);
//查找相邻重复元素，返回相邻元素的第一个位置的迭代器

//void Test1()
//{
//	vector<int> v;
//	v.push_back(0);
//	v.push_back(2);
//	v.push_back(0);
//	v.push_back(3);
//	v.push_back(1);
//	v.push_back(4);
//	v.push_back(3);
//	v.push_back(3);
//
//	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
//
//	if (pos == v.end())
//	{
//		cout << "没有重复相邻的元素" << endl;
//	}
//	else
//	{
//		cout << "有重复且相邻的元素，该元素为:" << *pos << endl;
//	}
//}
//
//int main()
//{
//	Test1();
//
//	system("pause");
//	return 0;
//}