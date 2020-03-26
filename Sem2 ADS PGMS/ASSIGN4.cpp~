//============================================================================
// Name        : graph.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================





/*

NAME-HARISH CHOUDHARY
	ROLL NO-SECOA121

ASSIGNMENT-4=Write a function to get the number of vertices in an undirected graph and its edges. You may 
assume that
no edge is input twice. 
i.
Use adjacency 
list representation of the graph and find runtime of the function
ii.
Use adjacency matrix representation of the graph and find runtime of the function


*/

#include <iostream>
using namespace std;
typedef struct node
{
	int vertices;
	node *next;
}node;

class graph
{
	int v,v1,v2;
	int mat[10][10];
	int i,j;
	node *head[20];
	int visited[20];
public:
	graph()
{
		v=v1=v2=0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				mat[i][j]=0;
			}
		}
		for(i=0;i<20;i++)
		{
			head[i]=NULL;
		}
		for(i=0;i<20;i++)
		{
			visited[i]=0;
		}
}

		void add_node( int i,int j)// create adjancy list function
		{
			node *nn,*cn;
			nn=new node;
			nn->vertices=j;
			if(head[i]==NULL)
			{
				head[i]=nn;
			}
			else
			{
			cn=head[i];
				while(cn->next!=NULL)
				{
					cn=cn->next;
				}
				cn->next=nn;
				return;
			}




		}
		void accept_adj_list()// create  adjanecy list function
		{
			char ch;
			cout<<"enter no of vertices"<<endl;
			cin>>v;
			do
			{
				cout<<"enter edge"<<endl;
				cin>>i>>j;
				if(i<=v&&j<=v)
				{
					add_node(i,j);
					add_node(j,i);
				}
				else
				{
					cout<<"error";
			}
				cout<<"do you want to continue"<<endl;
				cin>>ch;
		}while(ch=='y');
		}



		void accept_adj_matrix()//adjacency matrix function
		{
			char ch;

			cout<<"enter total no of vertices"<<endl;
			cin>>v;
			cout<<endl;
			do
			{
				cout<<"enter edge if present"<<endl;
				cout<<"enter edge 1"<<endl;
				cin>>v1;
				cout<<"enter 2nd vertice"<<endl;
				cin>>v2;
				mat[v1-1][v2-1]=mat[v2-1][v1-1]=1;
				cout<<"do you want to continue"<<endl;
				cin>>ch;
			}while(ch=='y');

			}
		void display_adj_matrix()
				{

					for(i=0;i<v;i++)
					{
						for(j=0;j<v;j++)
						{
							cout<<mat[i][j]<<"\t";
						}
						cout<<endl;
					}
				}
		void display_adj_list()
		{
			node *cn;
			for(i=1;i<=v;i++)
			{
				cn=head[i];
				cout<<i<<"->";
				while(cn!=NULL)
				{
					cout<<cn->vertices<<"\t";
					cn=cn->next;
				}
				cout<<endl;

			}

		}
		void dfs_display_recursive()//adjancy matrix display
		{
			int V;
			cout<<"enter starting vertex"<<endl;
			cin>>V;
			dfs(V);


		}
		void dfs(int x)
		{
			cout<<x;
			visited[x]=1;

			for(i=1;i<=v;i++)
			{
				if(mat[x][i]==1&&visited[i]==0)
					dfs(i);
		
			}

		}






};
int main()
{
	int x;
	graph g;
	char ch;
	int choice;
	do
	{
		cout<<"enter 1 for create adj matrix"<<endl;
		cout<<"enter 2 for create adj list"<<endl;
		cout<<"enter 3 for display adj matrix"<<endl;
		cout<<"enter 4 for display adj list"<<endl;
		cout<<"enter 5for dispay DFS recursive"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;

		switch(choice)
		{
		case 1:
			g.accept_adj_matrix();
			break;
		case 2:
			g.accept_adj_list();
			break;
		case 3:
			g.display_adj_matrix();
			break;
		case 4:
			g.display_adj_list();
			break;
		case 5:
			g.dfs_display_recursive();

			break;
		}
		cout<<"do you want to continue"<<endl;
		cin>>ch;
	}while(ch=='y');
	return 0;

}



/*
output-


enter 1 for create adj matrix
enter 2 for create adj list
enter 3 for display adj matrix
enter 4 for display adj list
enter 5for dispay DFS recursive
enter your choice
1
enter total no of vertices
3

enter edge if present
enter edge 1
1
enter 2nd vertice
2
do you want to continue
y
enter edge if present
enter edge 1
2
enter 2nd vertice
3
do you want to continue
y
enter edge if present
enter edge 1
1
enter 2nd vertice
3
do you want to continue
n
do you want to continue
y
enter 1 for create adj matrix
enter 2 for create adj list
enter 3 for display adj matrix
enter 4 for display adj list
enter 5for dispay DFS recursive
enter your choice
3
0	1	1	
1	0	1	
1	1	0	
do you want to continue
y
enter 1 for create adj matrix
enter 2 for create adj list
enter 3 for display adj matrix
enter 4 for display adj list
enter 5for dispay DFS recursive
enter your choice
2
enter no of vertices
3
enter edge
1
2
do you want to continue
y
enter edge
2
3
do you want to continue
y
enter edge
1
3
do you want to continue
n
do you want to continue
y
enter 1 for create adj matrix
enter 2 for create adj list
enter 3 for display adj matrix
enter 4 for display adj list
enter 5for dispay DFS recursive
enter your choice
4
1->2	3	
2->1	3	
3->2	1	
do you want to continue
n
*/

