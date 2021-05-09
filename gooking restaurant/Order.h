#pragma once
#include "go.h"
#include "Food.h"
#pragma warning(disable : 4996)
#include "Table.h"
class Order: public Food, public Table
{
public:
	int oid = 0;
	list<Food> foodsOrdered;
	Table table;
	int sum;
	//static int orderNumberGenerator;
	//string fname = "";
	//int fprice = 0;
public:
	Order() {}
	~Order() { }
	Order(int a, list<Food> b, Table c, int d) : oid(a), foodsOrdered(b), table(c), sum(d)
	{

	}
	void setOid(int a) { oid = a; }
	int getOid() { return oid; }

	void setTid(int a) { tid = a; }
	int getTid() { return tid; }
	/*
	void setFoods()
	{
		cout << "run\n";
		orderDisplay(foodsOrdered);
	}

	list<Food> getFoods()
	{

		return foodsOrdered;
	}
	*/
	//void setOrderNumber();
	
	//void setFname(int a) { fname = a; }
	//string getFname() { return fname; }
	
};

//void orderDisplay(list<Food> listofFood);
void datetime();
//void orderDetail();
void orderDisplay(list<Food> listofFood);
void writingOrderFile(int x,Table a, list<Food> &b, int c);
Order readingOrderFile();