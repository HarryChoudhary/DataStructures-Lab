/*

NAME-HARISH CHOUDHARY
	ROLL NO-SECOA121
ASSIGNMENT-9=Implement all the functions of a dictionary (ADT) using hashing.
Data:  Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys 
must be unique
Standard Operations:  In
sert(key, value), Find(key), Delete(key)
*/



#include<iostream>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
} node;

class ADT {
	node *hn, *nn, *cn, *ln;
public:
	ADT() {
		hn = NULL;
		nn = NULL;
		cn = NULL;
		ln = NULL;
	}


void subset()
{
	ADT A,B;
   int flag=0;
	node* t1, *t2;
    cout << "first Set :";
	A.create();
	cout << "Enter Set which you wish to check whether it is Subset of first set or not :";
    B.create();
    t1 = A.hn;
    t2 = B.hn;
    while(t1->data != t2->data){
    	t1 = t1->next;}
    while(t2!=NULL)
    {
     t1=t1->next;
     t2=t2->next;
     if(t1->data!=t2->data)
     {
         flag=1;
    	 break;
    }
    }
    if(flag==1)
    	cout<<"\nSecond Set is not a Subset of First ";
    else
    	cout<<"\nSecond set is Subset of first ";
}
void difference()
{
	ADT A, B, C;
			int dta = 0,flag;
			node* t1, *t2;
			cout << "first Set :";
			A.create();
			cout << "Second Set :";
			B.create();
			for (t1 = A.hn; t1 != NULL; t1 = t1->next) {
				flag=0;
				for (t2 = B.hn; t2 != NULL; t2 = t2->next) {
					if (t1->data == t2->data) {
					flag = 1;
					break;
					}
				}
				if(flag==0)
				{
					dta = t1->data;
								C.set_add(dta);
				}
			}
			cout<<"\nDifference of two Sets :";
		  C.display();
		}
void intersection()
{
	ADT A, B, C;
		int dta = 0,flag;
		node* t1, *t2;
		cout << "first Set :";
		A.create();
		cout << "Second Set :";
		B.create();
		for (t2 = B.hn; t2 != NULL; t2 = t2->next) {
			flag=0;
			for (t1 = A.hn; t1 != NULL; t1 = t1->next) {
				if (t2->data == t1->data) {
				flag = 1;
				break;
				}
			}
			if(flag==1)
			{
				dta = t2->data;
							C.set_add(dta);
			}
		}
		cout<<"\nIntersection of two Sets :";
	  C.display();
	}
void union_set() {
	ADT A, B, C;
	int dta = 0,flag;
	node* t1, *t2;
	cout << "first Set :";
	A.create();
	cout << "Second Set :";
	B.create();
	for (t1 = A.hn; t1 != NULL; t1 = t1->next) {
		dta = t1->data;
		C.set_add(dta);
	}
	for (t2 = B.hn; t2 != NULL; t2 = t2->next) {
		flag=0;
		for (t1 = A.hn; t1 != NULL; t1 = t1->next) {
			if (t2->data != t1->data) {
			flag = 1;
			break;
			}
		}
		if(flag==1)
		{
			dta = t2->data;
						C.set_add(dta);
		}
	}
	cout<<"\nUnion of two Sets :";
  C.display();
}
void create() {
	char ch;
	do {
		nn = new node;
		cout << "\nEnter Data :";
		cin >> nn->data;
		nn->next = NULL;
		if (hn == NULL) {
			hn = nn;
			ln = nn;
		} else {
			ln->next = nn;
			ln = nn;
		}
		cout << "\nDo you wish to continue (Y/N) :";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}
void display() {
	if (size()) {
		cout << "{";
		for (cn = hn; cn != ln; cn = cn->next) {
			cout << cn->data;
			if (cn != ln)
				cout << ",";
		}
		cout << cn->data;
		cout << "}";
	} else
		cout << "List is empty ";
}
void add(int item) {
	nn = new node;
	nn->data = item;
	nn->next = NULL;
	ln->next = nn;
	ln = nn;
}
void set_add(int dta)
{
		nn = new node;
			nn->data = dta;
			nn->next = NULL;
			if (hn == NULL) {
				hn = nn;
				ln = nn;
			} else {
				ln->next = nn;
				ln = nn;
			}
	}

bool contain(int item) {
	int flag = 0;
	if (hn == NULL)
		cout << "\nList is Empty ";
	else {
		for (cn = hn; cn != NULL; cn = cn->next) {
			if (cn->data == item) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			cout << "\nData is Present\n";
		} else
			cout << "\nData is not present\n";
	}
	if (flag == 1)
		return 1;
	else
		return 0;
}
void Remove(int item) {
	node* prev;
	node* temp = hn;
	if (contain(item)) {
		while (temp != NULL) {
			prev = temp;
			if (temp->data == item) {

				if (temp == hn) {
					hn = temp->next;
					delete temp;
					break;
				}
				if (temp == ln) {
					ln = prev;
					delete temp;
					ln->next = NULL;
					break;
				} else {
					prev->next = temp->next;
					delete temp;
					break;
				}
			} else {
				temp = temp->next;
			}
		}
	}
}
int size() {
	int count = 0;
	for (cn = hn; cn != NULL; cn = cn->next)
		count++;
	return count;
}
};
int main() {
	char ch;
	int data = 0, n = 0;
	int t;
	ADT c;
	do {
		cout << "\nPress 1 for creating list";
		cout << "\nPress 2 for adding new data";
		cout << "\nPress 3 for searching the data";
		cout << "\nPress 4 for removing the data";
		cout << "\nPress 5 for getting the size of the list";
		cout << "\nPress 6 for performing Union ";
		cout << "\nPress 7 for performing Intersection ";
		cout << "\nPress 8 for performing difference ";
		cout << "\nPress 9 for performing Subset ";
		cout << "\nEnter your choice :";
		cin >> n;
		switch (n) {
		case 1:
			c.create();
			c.display();
			break;
		case 2:
			cout << "\nEnter data :";
			cin >> data;
			c.add(data);
			c.display();
			break;
		case 3:
			cout << "\nEnter the data for which you are looking :";
			cin >> data;
			t = c.contain(data);
			break;
		case 4:
			cout << "\nEnter data to be removed :";
			cin >> data;
			c.Remove(data);
			c.display();
			break;
		case 5:
			t = c.size();
			cout << "\nSize = " << t;
			break;
		case 6 :
			c.union_set();
			break;
		case 7 :
			c.intersection();
			break;
		case 8 :
			c.difference();
			break;
		case 9 :
			c.subset();
			break;
		default :
			cout<<"\nEnter Valid choice ";
		}
		cout << "\nDo you wish to continue (Y/N) :";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	cout << "\nThank you ";
}





/*
OUTPUT-


Press 1 for creating list
Press 2 for adding new data
Press 3 for searching the data
Press 4 for removing the data
Press 5 for getting the size of the list
Press 6 for performing Union 
Press 7 for performing Intersection 
Press 8 for performing difference 
Press 9 for performing Subset 
Enter your choice :1

Enter Data :12

Do you wish to continue (Y/N) :Y

Enter Data :23

Do you wish to continue (Y/N) :Y

Enter Data :34

Do you wish to continue (Y/N) :N
{12,23,34}
Do you wish to continue (Y/N) :Y

Press 1 for creating list
Press 2 for adding new data
Press 3 for searching the data
Press 4 for removing the data
Press 5 for getting the size of the list
Press 6 for performing Union 
Press 7 for performing Intersection 
Press 8 for performing difference 
Press 9 for performing Subset 
Enter your choice :2

Enter data :44
{12,23,34,44}
Do you wish to continue (Y/N) :Y

Press 1 for creating list
Press 2 for adding new data
Press 3 for searching the data
Press 4 for removing the data
Press 5 for getting the size of the list
Press 6 for performing Union 
Press 7 for performing Intersection 
Press 8 for performing difference 
Press 9 for performing Subset 
Enter your choice :3

Enter the data for which you are looking :33

Data is not present

Do you wish to continue (Y/N) :Y

Press 1 for creating list
Press 2 for adding new data
Press 3 for searching the data
Press 4 for removing the data
Press 5 for getting the size of the list
Press 6 for performing Union 
Press 7 for performing Intersection 
Press 8 for performing difference 
Press 9 for performing Subset 
Enter your choice :4

Enter data to be removed :44

Data is Present
{12,23,34,0}
Do you wish to continue (Y/N) :Y

Press 1 for creating list
Press 2 for adding new data
Press 3 for searching the data
Press 4 for removing the data
Press 5 for getting the size of the list
Press 6 for performing Union 
Press 7 for performing Intersection 
Press 8 for performing difference 
Press 9 for performing Subset 
Enter your choice :5

Size = 4
Do you wish to continue (Y/N) :Y

Press 1 for creating list
Press 2 for adding new data
Press 3 for searching the data
Press 4 for removing the data
Press 5 for getting the size of the list
Press 6 for performing Union 
Press 7 for performing Intersection 
Press 8 for performing difference 
Press 9 for performing Subset 
Enter your choice :6
first Set :
Enter Data :12

Do you wish to continue (Y/N) :Y

Enter Data :23

Do you wish to continue (Y/N) :Y

Enter Data :34

Do you wish to continue (Y/N) :N
Second Set :
Enter Data :23

Do you wish to continue (Y/N) :Y

Enter Data :45

Do you wish to continue (Y/N) :Y

Enter Data :12

Do you wish to continue (Y/N) :N

Union of two Sets :{12,23,34,23,45,12}
Do you wish to continue (Y/N) :Y

Press 1 for creating list
Press 2 for adding new data
Press 3 for searching the data
Press 4 for removing the data
Press 5 for getting the size of the list
Press 6 for performing Union 
Press 7 for performing Intersection 
Press 8 for performing difference 
Press 9 for performing Subset 
Enter your choice :7
first Set :
Enter Data :12

Do you wish to continue (Y/N) :Y

Enter Data :23

Do you wish to continue (Y/N) :Y

Enter Data :34

Do you wish to continue (Y/N) :Y

Enter Data :44

Do you wish to continue (Y/N) :N
Second Set :
Enter Data :12

Do you wish to continue (Y/N) :Y

Enter Data :44

Do you wish to continue (Y/N) :N

Intersection of two Sets :{12,44}
Do you wish to continue (Y/N) :Y

Press 1 for creating list
Press 2 for adding new data
Press 3 for searching the data
Press 4 for removing the data
Press 5 for getting the size of the list
Press 6 for performing Union 
Press 7 for performing Intersection 
Press 8 for performing difference 
Press 9 for performing Subset 
Enter your choice :8
first Set :
Enter Data :12

Do you wish to continue (Y/N) :Y

Enter Data :23

Do you wish to continue (Y/N) :Y

Enter Data :44

Do you wish to continue (Y/N) :N
Second Set :
Enter Data :23

Do you wish to continue (Y/N) :Y

Enter Data :44

Do you wish to continue (Y/N) :Y

Enter Data :12

Do you wish to continue (Y/N) :N

Difference of two Sets :List is empty 
Do you wish to continue (Y/N) :Y

Press 1 for creating list
Press 2 for adding new data
Press 3 for searching the data
Press 4 for removing the data
Press 5 for getting the size of the list
Press 6 for performing Union 
Press 7 for performing Intersection 
Press 8 for performing difference 
Press 9 for performing Subset 
Enter your choice :9
first Set :
Enter Data :12

Do you wish to continue (Y/N) :Y

Enter Data :23

Do you wish to continue (Y/N) :Y

Enter Data :44

Do you wish to continue (Y/N) :Y

Enter Data :65

Do you wish to continue (Y/N) :N
Enter Set which you wish to check whether it is Subset of first set or not :
Enter Data :12

Do you wish to continue (Y/N) :Y

Enter Data :34

Do you wish to continue (Y/N) :Y

Enter Data :24

Do you wish to continue (Y/N) :Y

Enter Data :65

Do you wish to continue (Y/N) :N

Second Set is not a Subset of First 
Do you wish to continue (Y/N) :Y

Press 1 for creating list
Press 2 for adding new data
Press 3 for searching the data
Press 4 for removing the data
Press 5 for getting the size of the list
Press 6 for performing Union 
Press 7 for performing Intersection 
Press 8 for performing difference 
Press 9 for performing Subset 
Enter your choice :0

Enter Valid choice 
Do you wish to continue (Y/N) :

*/
