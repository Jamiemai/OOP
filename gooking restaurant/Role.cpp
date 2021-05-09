#include "Role.h"
#include "Display.h"
#include "Table.h"
#include "Order.h"


bool checkPassword()
{
	bool isManager = false, isWaiter = false, isChef = false, isCashier = false, isReceptionist = true;
	int pass;
	//bool 
	cout << "Enter PassWord(3 times trying):\n";
	for (int i = 0; i < 3; i++)
	{
		cin >> pass;
		if (pass == 111)
		{
			isManager = true;
			return true;
		}
		else if (pass == 222)
		{
			isWaiter = true;
			return true;
		}
		else if (pass == 333)
		{
			isChef = true;
			return true;
		}
		else if (pass == 444)
		{
			isCashier = true;
			return true;
		}
		else if (pass == 555)
		{
			isReceptionist = true;
			return true;
		}

		else
		{
			cout << "Not found!";
		}
	}
	cout << "login fail!" << endl;
	return false;
}

Role createRole() {
	cout << "Create new account!\n";
	cout << "role!\n";
	int roleNo;
	int id = 0, pw = 0;
	Role nr;
	while (true) {
		cout << "\n1. Create manager account"
			<< "\n2. Create waiter account"
			<< "\n3.Create chef account"
			<< "\n4. Create cashier account"
			<< endl;
		cin >> roleNo;
		
		if (roleNo == 1) {
			//int id, pw;
			cout << "ID:"; cin >> id;
			cout << "Passwowd: "; cin >> pw;
			Role nr(id, pw, 1);
			cout << "new Manager Added!\n" << "ID: M" << id << "(pass:" << pw << ")" << endl;
			return nr;
		}
			
		else if (roleNo == 2)
		{

			cout << "ID: "; cin >> id;
			cout << "Passwowd: "; cin >> pw;
			Role nr(id, pw, 2);
			cout << "new Waiter Added!\n" << "ID: W" << id << "(pass:" << pw << ")" << endl;
			return nr;
		}
		else if (roleNo == 3)
		{
			cout << "ID:"; cin >> id;
			cout << "Passwowd: "; cin >> pw;
			Role nr(id, pw, 3);
			cout << "new Chef Added!\n" << "ID: C" << id << "(pass:" << pw << ")" << endl;
			return nr;
		}
		else if (roleNo == 4)
		{
			cout << "ID:"; cin >> id;
			cout << "Passwowd: "; cin >> pw;
			Role nr(id, pw, 4);
			cout << "new Cashier Added!\n" << "ID: A" << id << "(pass:" << pw << ")" << endl;
			return nr;
		}
		else if (roleNo == 5)
		{
			cout << "ID:"; cin >> id;
			cout << "Passwowd: "; cin >> pw;
			Role nr(id, pw, 5);
			cout << "new Receptionist Added!\n" << "ID: A" << id << "(pass:" << pw << ")" << endl;
			return nr;
		}
		else 
		{
			cout << "pls retry!";
		}
	}
	
}

void managerFuction()
{
	int a; bool isW = false;
	cout << "1. MENU EDIT\n" << "2. RESGITER NEW ACCOUNT\n"; cin >> a;
	if (a == 1)
	{
		foodDisplay(isW);
	}
	else if (a == 2)
	{
		createRole();
	}

	else return;
}
void waiterFuction()
{
	list<Food> l = readingFoodFile();
	orderDisplay(l);
}
void cashierFuction()
{
	int choose;
	cout << "1. Show order\n";
	cout << "2. Change STT Table\n";
	
	cin >> choose;
	if (choose == 1)
	{
		readingOrderFile();
	}
	else if (choose == 2)
	{
		list<Table> l = readingTableFile();
		//printChart(l);
		changestt(l);
	}
}
void character()
{
	while (true) {
		int n;
		cout << "\n1. MANAGER (pass 111)"
			<< "\n2. WAITER (222)"
			<< "\n3. CHEF(333)"
			<< "\n4. CASHIER(444)"
			<< "\n5. RECEPTIONIST(555)"
			<< endl;
		cin >> n;
		bool corrRole = checkPassword();
		if (n == 1 && corrRole)
		{
			managerFuction();

		}
		else if (n == 2 && corrRole)
		{
			//bool waiter = true;
			cout << "WAITER SCREEN  ";
			waiterFuction();
			//saveMenu();

		}
		else if (n == 3 && corrRole)
		{
			cout << "THE CHEF SCREEN  \n";
			//orderDetail();
			readingOrderFile();

		}
		else if (n == 4 && corrRole)
		{
			cout << "CASHIER SCREEN \n";
			cashierFuction();
		}
		else if (n == 5 && corrRole)
		{
			cout << "------------RECEPTIONIST SCREEN--------------------  ";
			tableChartDisplay();

		}
		else
		{
			cout << "LOGIN FAIL \n";
		}
	}
}
