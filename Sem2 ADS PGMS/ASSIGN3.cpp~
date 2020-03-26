//============================================================================
// Name        : threadedbinarytree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/* 
NAME-HARISH CHOUDHARY
	ROLL NO-SECOA121
 ASSIGNMENT 3-	Consider threading a binary tree using preorder threads rather than inorder threads. Design an
						algorithm for traversal without using stack and analyze its complexity
*/


#include<iostream>
using namespace std;
typedef struct node
{
	int data ;
	node *left;
	node *right;
	int lbit,rbit;
}node;
class threadedbinarytree
{
	node *root,*nn,*dummy,*temp;
	public:
	threadedbinarytree()
	{
		root=NULL;

	}
	void create()
	{
		char l;
		char ch;
		int choice,d;
		dummy=new node;
		dummy->data=-999;
		dummy->left=dummy->right=dummy;
		do
		{
			nn=new node;
			nn->left=nn->right=NULL;
			nn->lbit=nn->rbit=0;
			cout<<"enter node";
			cin>>nn->data;


			if(root==NULL)
			{
				root=nn;
					dummy->left=nn;
				nn->left=nn->right=dummy;
				nn->lbit=nn->rbit=0;



			}
			else
			{
					temp=root;

				cout<<"enter choice where to add ( choice 1 =left and choice 2 = right )"<<endl;
				cin>>choice;
				while(1)
				{

				if(choice==1)



				{
						if(temp->lbit==0)
						{

							nn->left=temp->left;
							temp->left=nn;
							nn->right=temp;
							temp->lbit=1;
							break;

						}
						else
							temp=temp->left;
					}




				else if(choice==2)

				{



					if(temp->rbit==0)
					{
						nn->right=temp->right;
						temp->right=nn;

						nn->left=temp;
						temp->rbit=1;
						break;
					}
					else
						temp=temp->right;


				}
				else
				break;
			}





		}
			cout<<"do you want to continue"<<endl;
					cin>>ch;
					cout<<endl;


	}while(ch=='y');
	}
	void inorder()
	{
		temp=root;
		while(temp!=dummy)
		{
			while(temp->lbit==1)
			{
				temp=temp->left;

			}
			cout<<temp->data<<"\t";

			while(temp->rbit==0)
			{
				temp=temp->right;
				if(temp==dummy)
				{
					return;}
				else
					cout<<temp->data<<"\t";


			}
			temp=temp->right;
		}
	}
	void preorder()
	{
		temp=root;
		while(temp!=dummy)
		{

			while(temp->lbit==1)
			{
				cout<<temp->data<<"\t";
				temp=temp->left;
		}
			cout<<temp->data;

			while(temp->rbit==0)
			{
				temp=temp->right;
				if(temp==dummy)
					return;


			}
			temp=temp->right;
	}
	}



};
int main()
{
	threadedbinarytree t;
	t.create();
	cout<<endl;
	cout<<"inorder traversal"<<endl;
	t.inorder();
	cout<<endl;
	cout<<"preorder traversal"<<endl;
	t.preorder();
	cout<<endl;
	return 0;
}





/*

output-



enter node12
do you want to continue
y

enter node24
enter choice where to add ( choice 1 =left and choice 2 = right )
1
do you want to continue
y

enter node34
enter choice where to add ( choice 1 =left and choice 2 = right )
2
do you want to continue
y

enter node44
enter choice where to add ( choice 1 =left and choice 2 = right )
2
do you want to continue
y

enter node13
enter choice where to add ( choice 1 =left and choice 2 = right )
1
do you want to continue
n


inorder traversal
13	24	12	34	44	
preorder traversal
12	24	133444
*/

