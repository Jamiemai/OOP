#pragma once
#include "go.h"
#include "Food.h"
class Menu
{
public:
	int mid = 0;
	list<Food> menu;

	Menu() {}
	~Menu() {}

	Menu(int id, list<Food> f) : mid(id), menu(f)
	{ }
};
