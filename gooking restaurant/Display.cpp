#include "Display.h"
#include "Food.h"
#include "Table.h"
#include "Order.h"
#include "Role.h"


void foodDisplay(bool isWaiter)
{
	
	//bool isWaiter = false;
	//list<Food> listofFood = { listofFood };
	list<Food> listofFood = defaultList();
	list<Food>::iterator it;
	//list<Food> officeMenu;
	printFoodList(listofFood);
	
	while (true)
	{
		int choose;
		cout << "\nPress 1 to addFood. (Manager only)\n";
		cout << "Press 2 to removeFood.(Manager only)\n";
		cout << "Press 3 to Place Order.\n";
		cout << "Press 0 to back.\n";
		cin >> choose;

		if (choose == 0) {
			 character();
		}
		if (choose == 1 && isWaiter == false)
		{
			listofFood = addFood(listofFood);
			//saveMenu(listofFood);
		}
		else if (choose == 2 && isWaiter == false)
		{
			listofFood = removeFood(listofFood);
			//saveMenu(listofFood);
		}
		else if (choose == 3)
		{
			//datetime();
			orderDisplay(listofFood);

		}
	//	else if (choose == 0)  break;
		else { cout << "Not found, retry pls....\n"; }
		//officeMenu = listofFood; 
		printFoodList(listofFood);
		writingFoodFile(listofFood);
	}
//	goto flag;
	return;
}

void writingFoodFile(list<Food> a)
{
	a.sort([](const Food& f, const Food& s) { return f.fid < s.fid; });
	ofstream out_file;
	out_file.open("data/MenuFoods.txt");
	//int i = 0;
	for (const Food& f : a)
	{
		out_file << f.fid << " " << f.fname << " " << f.fprice<<std::endl;
	}
}
list<Food> readingFoodFile()
{
	ifstream fin;
	fin.open("data/MenuFoods.txt");
	//int i = 0;
	list<Food> a;
	Food tmp;
	while (fin >> tmp.fid >> tmp.fname >> tmp.fprice)
	{
		a.push_back(tmp);
	}
	printFoodList(a);
	return a;
}

