/*

NAME-HARISH CHOUDHARY
	ROLL NO-SECOA121

ASSIGNMENT 10=Department maintains  a student information. The file contains
roll
number, name, division 
and  address.      Allow  user  to  add,  delete  information  of  student.  Dis
play  information  of 
particular employee.  If record of student does not exist an appropriate message is displayed. 
If it is, then the system displays the student details.
Use sequential file to main the data.

*/


#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;
#define filename "person.dat"

class Person {
	int phno;
	char name[50];
public:
	void setData() {
		cout << "\nEnter Person name : ";
		cin >> name;
		cout << "Enter Phone no. ";
		cin >> phno;

	}

	void showData() {
		cout << "\nName : " << name;
		cout << "\tPhone no. : " << phno;
	}

	int retPhno() {
		return phno;
	}
	char* retName() {
		return name;
	}
};

/*
 * function to write in a binary file.
 */

void write_record() {
	ofstream outFile;
	outFile.open(filename, ios::binary | ios::app);

	Person obj;
	obj.setData();

	outFile.write((char*) &obj, sizeof(obj));

	outFile.close();
}

/*
 * function to display records of file
 */

void display() {
	ifstream inFile;
	inFile.open(filename, ios::binary);

	Person obj;

	while (inFile.read((char*) &obj, sizeof(obj))) {
		obj.showData();
		}

	inFile.close();
}

/*
 * function to search and display from binary file
 */

void search(int n) {
	ifstream inFile;
	inFile.open(filename, ios::binary);

	Person obj;

	while (inFile.read((char*) &obj, sizeof(obj)))
	{
		if (obj.retPhno() == n) {
			obj.showData();
		}
	}

	inFile.close();
}
void search(char n[]) {
	ifstream inFile;
	inFile.open(filename, ios::binary);

	Person obj;

	while (inFile.read((char*) &obj, sizeof(obj))) {
		if (!strcmp(obj.retName(), n)) {
			obj.showData();
		}
	}

	inFile.close();
}
/*
 * function to modify a record
 */

void modify_record(char n[]) {
	fstream file;
	file.open(filename, ios::in | ios::out | ios::binary);

	Person obj;

	while (file.read((char*) &obj, sizeof(obj)))
	{
		if (!strcmp(obj.retName(), n))
		{
			cout << "\nEnter the new details of Person";
			obj.setData();

			int pos = -1 * sizeof(obj);
			file.seekp(pos, ios::cur);

			file.write((char*) &obj, sizeof(obj));
		}
	}

	file.close();
}

int main() {
	int ch;
	int no1;
	char name1[50];

	do {
		cout << "\n\n1.Create\n2.Display\n3.Find Name\n4.Find Telephone No.";
		cout << "\n5.Update Telephone No.\n6.Exit\nEnter your choice : ";
		cin >> ch;
		switch (ch) {
		case 1:
			write_record();
			break;

		case 2:
			cout << "\nList of records";
			display();
			break;

		case 3:
			//Search name
			cout << "\nEnter Phone no : ";
			cin >> no1;
			search(no1);
			break;

		case 4:
			//Search phone no
			cout << "\nEnter Name : ";
			cin >> name1;
			search(name1);
			break;

		case 5:
			//Modify record
			cout << "To update, Enter Person Name: ";
			cin >> name1;
			modify_record(name1);
			break;
		default:
			cout<<"\nExit from program...";
			exit(0);
		}
	} while (1);

	return 0;
}





/*
output-

1.Create
2.Display
3.Find Name
4.Find Telephone No.
5.Update Telephone No.
6.Exit
Enter your choice : 1

Enter Person name : hari
Enter Phone no. 12
enter address of person
aundh
enter div of person
A


1.Create
2.Display
3.Find Name
4.Find Telephone No.
5.Update Telephone No.
6.Exit
Enter your choice : 1

Enter Person name : akshay
Enter Phone no. 23
enter address of person
ad
enter div of person
A


1.Create
2.Display
3.Find Name
4.Find Telephone No.
5.Update Telephone No.
6.Exit
Enter your choice : 1

Enter Person name : qwod
Enter Phone no. 22
enter address of person
qwa
enter div of person
A


1.Create
2.Display
3.Find Name
4.Find Telephone No.
5.Update Telephone No.
6.Exit
Enter your choice : 2

List of records
Name : hari	Phone no. : 12	addresss isaundh	division isA
Name : akshay	Phone no. : 23	addresss isad	division isA
Name : qwod	Phone no. : 22	addresss isqwa	division isA

1.Create
2.Display
3.Find Name
4.Find Telephone No.
5.Update Telephone No.
6.Exit
Enter your choice : 3

Enter Phone no : 12

Name : hari	Phone no. : 12	addresss isaundh	division isA

1.Create
2.Display
3.Find Name
4.Find Telephone No.
5.Update Telephone No.
6.Exit
Enter your choice : 4

Enter Name : hari


1.Create
2.Display
3.Find Name
4.Find Telephone No.
5.Update Telephone No.
6.Exit
Enter your choice : 2

List of records
Name : hari	Phone no. : 12	addresss isaundh	division isA
Name : akshay	Phone no. : 23	addresss isad	division isA
Name : qwod	Phone no. : 22	addresss isqwa	division isA

1.Create
2.Display
3.Find Name
4.Find Telephone No.
5.Update Telephone No.
6.Exit
Enter your choice : 5
To update, Enter Person Name: hari


1.Create
2.Display
3.Find Name
4.Find Telephone No.
5.Update Telephone No.
6.Exit
Enter your choice : 5
To update, Enter Person Name: hari


1.Create
2.Display
3.Find Name
4.Find Telephone No.
5.Update Telephone No.
6.Exit
Enter your choice : 2

List of records
Name : hari	Phone no. : 12	addresss isaundh	division isA
Name : akshay	Phone no. : 23	addresss isad	division isA
Name : qwod	Phone no. : 22	addresss isqwa	division isA

1.Create
2.Display
3.Find Name
4.Find Telephone No.
5.Update Telephone No.
6.Exit
Enter your choice :




 */

