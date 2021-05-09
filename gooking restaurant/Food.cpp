#include "Food.h"


Food enterFood()
{
	int id, price; string name;
	cout << "Enter ID: ";
	cin >> id;
	cout << " Enter name: \n";
	//getline(cin,name);
	cin >>name;
	cout << " Set Price: \n";
	cin >> price;
	Food nf(id, name, price);
	return nf;

}

list<Food> addFood(list<Food>& ls)
{
	list<Food>::iterator it;
	//it = ls.begin();
	Food a = enterFood();
	for (auto it = ls.begin(); it != ls.end(); ++it)
	{
		if (it->fid == a.fid)
		{
			cout << " This food alr in menu!\n";
			return ls;
		}	
	}
	ls.push_back(a);
	return ls;
}
list<Food> removeFood(list<Food>& ls)
{
	list<Food>::iterator it;
	it = ls.begin();
	unsigned int r;
	cout << "Choose index: ";
	cin >> r;
	if (r < 0 || r > ls.size()+1)
	{
		cout << "valid input!\n";
		return ls;
	}
	else 
	{advance(it, r - 1);
	ls.erase(it); }
	return ls;
}
list<Food> defaultList()
{
	list<Food> listofFood = { Food(1001, "Tea", 5),
				   Food(1002, "Onigiri", 12),

				   Food(2003,"Tempura", 9),
				   Food(1005, "Sushi", 7),
				   Food(1006, "Sashimi", 6),
				   Food(1007, "Udon ", 9),
				   Food(1008, "Gyoza", 10),
				   Food(1009, "Gyudon", 10),
				   Food(1010, "MisoSoup", 5),
		//			Food(1011, "Ramen", 20),
		//								Food(1012, "Robatayaki", 9)

	};
	return listofFood;
}

void printFoodList(list<Food> a)
{
	//int n = 3;
	a.sort([](const Food& f, const Food& s) { return f.fid < s.fid; });
	cout << "\n			GOK's MENU			\n\n";
	cout << "|\tINDEX\t" << "|\t" << "ID\t|\t" << "NAME\t\t" << std::endl;
	cout << "________________________________________________________________" << std::endl;
	int i = 0;
	for (const Food& f : a)
	{

		cout << "|\t" << i + 1 << "\t|\t" << f.fid << "\t|\t" << f.fname << "\t" << std::endl;
		cout << "----------------------------------------------------------------" << std::endl;
		i++;
	}

}


