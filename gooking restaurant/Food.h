#pragma once
#include "go.h"
class Food
{
public:
	int fid = 0;
	string fname = "";
	int fprice = 0;
	//list<Food> lf;
	//int fquan = 0;
	friend class Display;
public:
	Food() {}
	~Food() { }
	Food(int a, string b, int c) : fid(a), fname(b) ,fprice(c)
	{

	}
	//Food(list<Food> l) : lf(l)
	//{

	//}
	//Food(int a, string b, int c, int d) : fid(a), fname(b), fprice(c), fquan(d)
	void setFid(int a) { fid = a; }
	int getFid() { return fid; }

	void setFname(int a) { fname = a; }
	string getFname() { return fname; }

	
	//void printFoodList(list<Food> a);
	//list<Food> defaultList();
	//friend std::ostream& operator<<(std::ostream& out, const Food& point);
//	friend std::istream& operator>>(std::istream& in, Food& point);
	//list<Food> orderDisplay(list<Food> l);
	bool operator==(const Food& obj)
	{
		return (fid == obj.fid) && (fname == obj.fname) && (fprice == obj.fprice);
	}
	//void foodDisplay();
};

//void foodDisplay();
list<Food> defaultList();
Food enterFood();
list<Food> addFood(list<Food>& listofFood);
void printFoodList(list<Food> a);
list<Food> removeFood(list<Food>& ls);
//void saveMenu(list<Food> a);
void foodFile(list<Food> a);
//vector<City> initRoute { City("Boston", 42.3601, -71.0589),
//City("Houston", 29.7604, -95.3698), ... };