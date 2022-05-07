#define _CRT_SECURE_NO_WARNINGS 1

#pragma once 

#include <iostream>
using namespace std;

class Person
{
public:
	Person(string name, int score);

	string m_Name;
	int m_Score;
};
