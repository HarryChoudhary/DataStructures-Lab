//============================================================================
// Name        : ASS5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*


NAME-HARISH CHOUDHARY
	ROLL NO-SECOA121
ASSIGNMENT-5

		You have a business with several offices; you want to lease phone lines to connect them up
		with each other; and the phone company charges different amounts of money to connect
		different pairs of cities. You want a set of lines that connects all your offices with a minimum
		total cost. Solve the problem by suggesting appropriate data structures.

*/

#include <iostream>
using namespace std;

class MST
{
	int Offices[10][10];
	int V,E;
	int M[10][10];
	int infinity;
	int visited[10];
	int min_cost;
public:
	MST()
{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				M[i][j]=0;
				Offices[i][j]=0;
				visited[i]=0;
			}
		}
		infinity=999;
		min_cost=0;
}
	void create();
	void MST1();
	void display();
	void dfs(int);

};


void MST::create()
{
	int i,j,cost;
	char ch;
	cout<<"\n Enter total no.of cities";
	cin>>V;
	cout<<"\n Enter telephone line paths between offices";
	do
			{
				cout<<"\n Enter path";
				cin>>i>>j;
				if(i<V && j<V)
				{
					cout<<"\n Enter Cost";
					cin>>cost;
					M[i][j]=cost;
					M[j][i]=cost;
				}
				else
				{
					cout<<"\n Error. Enter Valid input";
				}

				cout<<"\n Whether you wish to continue";
				cin>>ch;
			}while(ch=='y'||ch=='Y');
}

void MST::MST1()
{
	int cost[10][10];
	int dist[10];
	int source[10];
	int u,v;
	int min_dist=infinity;
	E=V-1;

	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(M[i][j]==0)
				cost[i][j]=infinity;
			else
				cost[i][j]=M[i][j];
		}
	}

	dist[0]=0;
	source[0]=0;
	visited[0]=1;

	for(int i=1;i<V;i++)
	{
		dist[i]=cost[0][i];
		source[i]=0;
		visited[i]=0;
	}

	while(E>0)
	{
		min_dist=infinity;

		for(int i=1;i<V;i++)
		{
			if(visited[i]==0 && dist[i]<min_dist)
			{
				min_dist=dist[i];
				v=i;
			}
		}

		u=source[v];
		Offices[u][v]=min_dist;
		Offices[v][u]=min_dist;
		visited[v]=1;
		E--;

		for(int i=1;i<V;i++)
		{
			if(visited[i]==0 && cost[i][v]<dist[i])
			{
				dist[i]=cost[i][v];
				source[i]=v;
			}
		}

		min_cost=min_cost + Offices[u][v];
	}
}

void MST::display()
{

	cout<<"\n The minimum cost for the telephone lines connecting all the offices in the cities is ";
	cout<<min_cost;
}


int main()
{
	MST m;
	m.create();
	m.MST1();
	m.display();
	return 0;
}


/*
OUTPIT-

 Enter total no.of cities7

 Enter telephone line paths between offices
 Enter path0
1

 Enter Cost3

 Whether you wish to continuey

 Enter path0
2

 Enter Cost6

 Whether you wish to continuey

 Enter path0
4

 Enter Cost8

 Whether you wish to continuey

 Enter path1
3

 Enter Cost7

 Whether you wish to continuey

 Enter path1
5

 Enter Cost3

 Whether you wish to continuey

 Enter path2
3

 Enter Cost1

 Whether you wish to continuey

 Enter path3
4

 Enter Cost2

 Whether you wish to continuey

 Enter path4
5

 Enter Cost5

 Whether you wish to continuey

 Enter path5
6

 Enter Cost2

 Whether you wish to continuey

 Enter path4
6

 Enter Cost3

 Whether you wish to continuen

 The minimum cost for the telephone lines connecting all the offices in the citi
es is 14
--------------------------------
Process exited after 219.8 seconds with return value 0
Press any key to continue . . .
*/
