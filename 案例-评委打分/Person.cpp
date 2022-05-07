#define _CRT_SECURE_NO_WARNINGS 1

#include "Person.h"

Person::Person(string name, int score)
{
	this->m_Name = name;
	this->m_Score = score;
}