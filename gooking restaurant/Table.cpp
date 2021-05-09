#include "Table.h"
#include "Role.h"


Table addTable()
{

	int id; bool isplaced = false;
	std::cout << "Enter ID: \n";
	cin >> id;
	//cout << "Enter status: \n";
	//cin >> isplaced;

	Table nf(id, isplaced);
	return nf;
}

void printChart(list<Table> a)
{
	int n = 3;
	for (Table& f : a)
	{

		if (f.isPlace == false)
		{
			std::cout << "\t|-" << f.tid << "-" << "|\t";
			n++;
			if (n % 3 == 0) std::cout << endl << endl;
		}
		else
		{
			std::cout << "\t|-" << f.tid << "-" << "|-X\t";
			n++;
			if (n % 3 == 0) std::cout << endl << endl;
		}
	}
	
}

list<Table> defaultChart()
{
	bool isPlaced = false;
	list<Table> il = {
		Table(5001, isPlaced), Table(5003, isPlaced),
			Table(5002, isPlaced), Table(5004, isPlaced),
			Table(5005, isPlaced), Table(5006, isPlaced),
			Table(5007, isPlaced), Table(5009, isPlaced),
			Table(5008, isPlaced), Table(5010, isPlaced)
	};
	return il;
}

void changestt(list<Table> a)
{

//	Table b;
	
	while (true)
	{
		list<Table> l = readingTableFile();
		printChart(l);
		int r;
		std::cout << "\n0. to Exit. ";
		std::cout << "\nEnter Table ID to change: ";

		cin >> r;
		if (r == 0) { return; }
		else
		{
			for (auto it = a.begin(); it != a.end(); ++it)
			{

				if (it->tid == r && it->isPlace == true)
				{
					l.push_back(*it);
					it->isPlace = false;
					writingTableFile(a);
				}
			}
		//	list<Table> l = readingTableFile();
		}
		
		
	}
	return;
}

Table choseTable(list<Table> a)
{
//	void choseTable(list<Table> a);
	Table b;
	list<Table> l = readingTableFile();
	//printChart(l);
	while (true)
	{
		
		int r;
		std::cout << "\n0. to Exit. ";
		//std::cout << "\n9. to Choose. ";
		std::cout << "\nEnter Table ID to choose: ";

		cin >> r;
		if (r == 0) { return b; }
		else
		{
			//std::cout << "\nEnter Table ID to Place: ";
			for (auto it = a.begin(); it != a.end(); ++it)
			{

				if (it->tid == r && it->isPlace == 0)
				{
					b.tid = r; b.isPlace = true;
					l.push_back(*it);
					it->isPlace = true;
					
				}
				else
				{
					cout << "Table not available!\n";
				}
				writingTableFile(a);
			}
		}
		//std::cout << "\nTable(s) is placed : ";
		list<Table> l = readingTableFile();
		printChart(l);
		cout << endl;
	//	std::cout << endl << endl;
		//printChart(a);
	}
	return b;
}

void tableChartDisplay()
{

	list<Table> tc = defaultChart();


flag:
	tc.sort([](const Table& f, const Table& s) { return f.tid < s.tid; });
	std::cout << "\n			GOK's TABLE			\n\n";
	std::cout << "|\t **NOTE: X is mark the table is placed!\n" << std::endl;
	printChart(tc);
	
	int n = 0;
		
		list<Table>::iterator it;
		int choose;
		std::cout << "\n>Press 1 to add table.\n";
		std::cout << ">Press 2 to remove Table.\n";
		std::cout << ">Press 3 to Choose Order.\n";
		std::cout << ">Press 0 to Exit.\n";
	
		cin >> choose;
		if (choose == 0) { 
			character();
			return; }
		else if (choose == 1)
		{
			//it = tc.begin();
			Table a = addTable();
			for (auto it = tc.begin(); it != tc.end(); ++it)
			{
				if (a.tid == it->tid)
				{
					std::cout << " This table ID alr in chart!\n";
				}
			}
			tc.push_back(a);

		}
		else if (choose == 2)
		{	int r;
			std::cout << "Choose ID: ";
			cin >> r;
			auto it = tc.begin();
			if (it->tid != r)
			{
				std::cout << "valid input!\n";
			}
			for (auto it = tc.begin(); it != tc.end(); ++it) {
				if ((it->tid) == r) {
					it = tc.erase(it);
					it--;
				}

			}
			//tc = removeTable(tc);
		}
		else if (choose == 3)
		{
			choseTable(tc);
			//changestt(l, tc);
			

		}
		else { std::cout << "Not found, retry pls....\n"; }
		writingTableFile(tc);
		
		goto flag;
}
void writingTableFile(list<Table> a)
{
	//5int n = 3;
	ofstream out_file;
	out_file.open("data/TableFile.txt");
	//int i = 0;
	for (const Table& t : a)
	{
		out_file << t.tid << " " << t.isPlace << " ";
	}
}
list<Table> readingTableFile()
{
	ifstream fin;
	fin.open("data/TableFile.txt");
	//int i = 0;
	list<Table> a;
	Table tmp;
	while (fin >> tmp.tid >> tmp.isPlace){
		a.push_back(tmp);
	}
	//printChart(a);
	return a;
}