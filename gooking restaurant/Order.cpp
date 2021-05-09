#include "Order.h"
#include "Role.h"
#include "Display.h"
#include "Table.h"

int OID = 9000;
//int Order::orderNumberGenerator = 8000;
void datetime()
{
	time_t tt = time(0);
	time(&tt);
	struct tm* ti;
	ti = localtime(&tt);
	cout << "Order date: " << asctime(ti) << endl;
}

int printOrder(list<Food> l)
{
	cout << "Amount: ";
	//else 
	int sum = 0, fquan; cin >> fquan;
	for (const Food& f2 : l)
	{
		cout << f2.fid << "\t\t" << f2.fname << "\t" << "\tPRICE: " << f2.fprice << "$" << "\tAmount: " << fquan << std::endl;
		cout << "----------------------------------------------------------------" << std::endl;
		sum = sum + f2.fprice * (fquan);
	}
	cout << "		\t\tTOTAL: \t" << sum << "$" << std::endl;
	return sum;
}


void orderDisplay(list<Food> a)
{
	list<Table> tl = readingTableFile();
	printChart(tl);
	Table t = choseTable(tl);
	
	list<Food>::iterator it;
	list<Food> l;
	int sum = 0;
	Order order = Order(OID, l, t, sum);
	while (true)
	{	
		unsigned int r;
		cout << "CREATE ORDER !\n";
		cout << "\nEnter index of food !";
		cout << "\nEnter 0 to EXIT!\n" << "you choose:";
		cin >> r;
		it = a.begin();
		if (r == 0) {
			character();
		}
		else if(r > 0 && r-1 < a.size())
		{
			advance(it, r-1);
			l.push_back(*it);
			sum = printOrder(l);
			datetime();
			cout << "\nORDER.NO: " << order.oid;
			cout << "\tTable: " << t.tid << endl;
			writingOrderFile(OID, t, l, sum);
		}	
	}
	OID++;
	return;
}


void writingOrderFile(int x,Table a, list <Food> &b, int c)
{
	
	ofstream out_file;
	out_file.open("data/Orders.txt");
	out_file << a.tid << " " << x << " " << c << " ";
			for (const Food& f : b) 
			{
				out_file << f.fid << " " << f.fname << " ";
			}
			//out_file <<endl;
}
void printfullOrder(list<Food> l)
{

	for (const Food& f2 : l)
	{
		cout << f2.fid << "\t\t" << f2.fname<<endl;
		cout << "------------------------------------" << std::endl;
		//cout << o.sum;
	}
}
Order readingOrderFile()
{
	ifstream fin;
	fin.open("data/Orders.txt");
	int x;
	list<Food> a;
	Order o;
	fin >> o.tid >> o.oid >> o.sum;// >> o.fid >> o.fname;
	std::cout << " ------------------------------------------" << endl;
	std::cout << " Table no:" << o.tid << " Order no: " << o.oid << " Total: " << "$" << o.sum << endl;

	//while (c != '\n')
	//{
		fin >> o.fid >> o.fname;
	//}
	std::cout << " Food no:" << o.fid << "\t  " << o.fname<<endl;
	//for ( Food& f : o.foodsOrdered)
	//{
	//	cout << f.fid << " \t" << f.fname << endl;
	//}
	//printfullOrder(a);
	return o;
}

