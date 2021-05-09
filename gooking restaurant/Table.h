#pragma once
#include "go.h"


class Table
{
public:
	int tid = 0;
	bool isPlace = 0;
public:
	Table() { };
	~Table() {};
	Table(int a, bool b) : tid(a), isPlace(b)
	{ }


};

void tableChartDisplay();
list<Table> readingTableFile();
void writingTableFile(list<Table> a);
Table choseTable(list<Table>);
void printChart(list<Table> a);
void changestt(list<Table> a);

