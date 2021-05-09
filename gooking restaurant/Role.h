#pragma once
#include "go.h"
class Role
{
public:
	int rid = 0;
	int rpw = 0;
	int r = 0;
public:
	Role() {}
	~Role() {}
	//Role(int a, int b) : rid(a), rpw(b)

	Role(int a, int b, int c) : rid(a), rpw(b), r(c)
	{

	}

};
/*
Role::Role()
{
	rid = 0;
	rpw = 0;
}

*/
void character();
Role createRole();