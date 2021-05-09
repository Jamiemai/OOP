#pragma once
#include "go.h"
#include "Menu.h"

class Branch
{
public:
	int bno = 0;
	string blocal = "";
	Menu bmenu;
public:
	//Branch() {}
//	~Branch() { }
	Branch(int a,string b, Menu c) : bno(a), blocal(b), bmenu(c)
	{

	}
	//Food(int a, string b, int c, int d) : fid(a), fname(b), fprice(c), fquan(d)
	void setblocal(string a) {  blocal = a; }
	string getlocal() { return blocal; }

	void setMenu(Menu a) { bmenu = a; }
//	Menu getMenu() { return bmenu; }
};

