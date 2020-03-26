//============================================================================
// Name        : symboltable.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*



NAME-HARISH CHOUDHARY
	ROLL NO-SECOA121
ASSIGNMENT-6
			The symbol table is generated by compiler. From this perspective, the symbol table is a set of
				name-attribute pairs. In a symbol table for a compiler, the name is an identifier, and the
				attributes might include an initial value and a list of lines that use the identifier.
			Perform the following operations on symbol table:
			(1) Determine if a particular name is in the table
			(2) Retrieve the attributes of that name
			(3) Modify the attributes of that name
			(4) Insert a new name and its attributes
			(5) Delete a name and its attributes

*/

#include <iostream>
using namespace std;
typedef struct table
{
	string Name;
	string type;
	int count;
	int initi_value;
	int line_no[10];

}table;
class symbol
{
	table t[10];

		int i,j,n,m;

public:
	symbol()
{
	for( i=0;i<10;i++)
	{
		t[i].initi_value=0;
		t[i].line_no[i]=0;
		t[i].count=0;
	}


}

	void create_symbol_table()
	{	char ch;

		i=0;
		cout<<"enter size of symbol table"<<endl;
		cin>>n;
		for(i=0;i<n;i++)
		{


			cout<<"enter Name of identifier"<<endl;
			cin>>t[i].Name;
			cout<<"enter type of identifier"<<endl;
			cin>>t[i].type;
			cout<<endl;

			cout<<"enter how many times identifier is used"<<endl;
			cin>>m;
			for(int j=0;j<m;j++)
			{
				cout<<"enter line no of identifier "<<endl;
				cin>>t[i].line_no[j];
				t[i].count++;

			}


		}

	}
	void display()
	{
	cout<<"NAME"<<"\t"<<"TYPE"<<"\t"<<"INITIAL_VALUE"<<"\t";
	cout<<"LINE_NO"<<"\t"<<"\t"<<"COUNT"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<t[i].Name<<"\t"<<t[i].type<<"\t"<<"\t"<<t[i].initi_value<<"\t";
		for(j=0;j<t[i].count;j++)
		{


		cout<<t[i].line_no[j]<<",";
		}
		cout<<"\t"<<"\t";
			cout<<t[i].count;
			cout<<endl;
	}

	}
	void search()
	{
		int flag=0;
		string key;
		cout<<"enter  identifier name to be searched"<<endl;
		cin>>key;
		for(i=0;i<n;i++)
		{
		if(t[i].Name==key)
		{
			flag=1;
			
			break;

		}
		
		
		}
		if(flag==1)
		{
			cout<<"identifier found"<<endl;
			cout<<t[i].Name<<"\t"<<t[i].type<<"\t"<<t[i].initi_value;
		}

	}
	
	
	
		
	
	
	void delete_sy( )
	{
		int flag=0;
		string key;
		cout<<"enter  identifier name to be deleted"<<endl;
		cin>>key;
		for(i=0;i<n;i++)
		{
		if(t[i].Name==key)
		while(i<n)
		{
			t[i].Name=t[i+1].Name;
			t[i].type=t[i+1].type;
			t[i].count=t[i+1].count;
			//t[i].line_no=t[i+1].line_no;
			t[i].initi_value=t[i+1].initi_value;
			i++;
		}
		
		
		}
		
		
	}
	
	
	void modify_sy()
	{
		string key;
		cout<<"enter  identifier name to be updated"<<endl;
		cin>>key;
		for(i=0;i<n;i++)
		{
		if(t[i].Name==key)
		{
			cout<<"enter new type"<<endl;
			cin>>t[i].type;
			cout<<"enter how many times identifier is used"<<endl;
			cin>>m;
			for(int j=0;j<m;j++)
			{
				cout<<"enter line no of identifier "<<endl;
				cin>>t[i].line_no[j];
				t[i].count++;

			}

		
		}
		
	}
}
};
int main()
{
	symbol s;
	char ch;
	int choice;
	do
	{
		cout<<"enter 1 for creating symbol table"<<endl;
		cout<<"enter 2 for displaying symbol table"<<endl;
		cout<<"enter 3 for searching a element in symbol table "<<endl;
		cout<<"enter 4 for deletion of element"<<endl;
		cout<<"enter 5 for update name of identifier attributes"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			s.create_symbol_table();
			break;
		case 2:
			s.display();
			break;
		case 3:
			s.search();
			break;
		case 4:
			s.delete_sy();
			break;
		case 5:
			s.modify_sy();
			break;
			
		}
		cout<<" do you wish to continue"<<endl;
		cin>>ch;
	}while(ch=='y');


	return 0;

}
/*

 OUTPUT-
 enter 1 for creating symbol table
enter 2 for displaying symbol table
enter 3 for searching a element in symbol table
enter 4 for deletion of element
enter 5 for update name of identifier attributes
enter your choice
1
enter size of symbol table
4
enter Name of identifier
int
enter type of identifier
int

enter how many times identifier is used
2
enter line no of identifier
3
enter line no of identifier
1
enter Name of identifier
qw
enter type of identifier
float

enter how many times identifier is used
4
enter line no of identifier
1
enter line no of identifier
4
enter line no of identifier
3
enter line no of identifier
6
enter Name of identifier
wertg
enter type of identifier
double

enter how many times identifier is used
1
enter line no of identifier
2
enter Name of identifier
b
enter type of identifier
bool

enter how many times identifier is used
2
enter line no of identifier
0
enter line no of identifier
9
 do you wish to continue
y
enter 1 for creating symbol table
enter 2 for displaying symbol table
enter 3 for searching a element in symbol table
enter 4 for deletion of element
enter 5 for update name of identifier attributes
enter your choice
2
NAME	TYPE	INITIAL_VALUE	LINE_NO		COUNT
int	int		0	3,1,		2
qw	float		0	1,4,3,6,		4
wertg	double		0	2,		1
b	bool		0	0,9,		2
 do you wish to continue
y
enter 1 for creating symbol table
enter 2 for displaying symbol table
enter 3 for searching a element in symbol table
enter 4 for deletion of element
enter 5 for update name of identifier attributes
enter your choice
3
enter  identifier name to be searched
bool
 do you wish to continue
y
enter 1 for creating symbol table
enter 2 for displaying symbol table
enter 3 for searching a element in symbol table
enter 4 for deletion of element
enter 5 for update name of identifier attributes
enter your choice
3
enter  identifier name to be searched
int
identifier found
int	int	0 do you wish to continue
y
enter 1 for creating symbol table
enter 2 for displaying symbol table
enter 3 for searching a element in symbol table
enter 4 for deletion of element
enter 5 for update name of identifier attributes
enter your choice
4
enter  identifier name to be deleted
int
 do you wish to continue
y
enter 1 for creating symbol table
enter 2 for displaying symbol table
enter 3 for searching a element in symbol table
enter 4 for deletion of element
enter 5 for update name of identifier attributes
enter your choice
2
NAME	TYPE	INITIAL_VALUE	LINE_NO		COUNT
qw	float		0	3,1,-714310200,32699,		4
wertg	double		0	1,		1
b	bool		0	2,0,		2
			0			0
 do you wish to continue
y
enter 1 for creating symbol table
enter 2 for displaying symbol table
enter 3 for searching a element in symbol table
enter 4 for deletion of element
enter 5 for update name of identifier attributes
enter your choice
5
enter  identifier name to be updated
q
 do you wish to continue
y
enter 1 for creating symbol table
enter 2 for displaying symbol table
enter 3 for searching a element in symbol table
enter 4 for deletion of element
enter 5 for update name of identifier attributes
enter your choice
5
enter  identifier name to be updated
qw
enter new type
int
enter how many times identifier is used
3
enter line no of identifier
1
enter line no of identifier
4
enter line no of identifier
2
 do you wish to continue
y
enter 1 for creating symbol table
enter 2 for displaying symbol table
enter 3 for searching a element in symbol table
enter 4 for deletion of element
enter 5 for update name of identifier attributes
enter your choice
2
NAME	TYPE	INITIAL_VALUE	LINE_NO		COUNT
qw	int		0	1,4,2,32699,4195216,0,0,		7
wertg	double		0	1,		1
b	bool		0	2,0,		2
			0			0
 do you wish to continue
n
*/


