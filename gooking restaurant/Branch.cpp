#include "Branch.h"
#include "Role.h"


list<Branch>  defaultBranch()
{

	Menu mn;
	list<Branch> brl = { Branch(1, "Tokyo", mn ),
						Branch(2, "Okinawa", mn),
						Branch(2, "Hanoi", mn),
	};
	return brl;
}

void printBrachList(list<Branch> a)
{
	//int n = 3;
	//a.sort([](const Food& f, const Food& s) { return f.fid < s.fid; });
	cout << "\n			GOK's BRANCH			\n\n";
	cout << "|\t" << "ID\t|\t" << "LOCAL\t\t" << std::endl;
	cout << "______________________________________________" << std::endl;
	int i = 0;
	for (const Branch& b : a)
	{

		cout << "|\t" << i + 1 << "\t|\t" << b.bno << "\t|\t" << b.blocal << "\t" << std::endl;
		cout << "----------------------------------------------------------------" << std::endl;
		i++;
	}
}


void BranchDisplay()
{

	list<Branch> bl = defaultBranch();


flag:
	//bl.sort([](const Branch& f, const Branch& s) { return f.tid < s.tid; });
	cout << "\n			GOK's BRANCH			\n\n";
	cout << "|\t **NOTE: X is mark the table is placed!\n" << std::endl;
	printBrachList(bl);
	int n = 0;

	list<Branch>::iterator it;
	int choose;
	cout << "\n>Press 1 to add table.\n";
	cout << ">Press 2 to remove Table.\n";
	cout << ">Press 3 to Choose Order.\n";
	cout << ">Press 0 to Exit.\n";
	
	cin >> choose;
	if (choose == 0) {
	//	character();
		return;
	}

	else if (choose == 2)
	{

	}
	else if (choose == 3)
	{


	}
	else { cout << "Not found, retry pls....\n"; }
	goto flag;
}
