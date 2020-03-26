//============================================================================
// Name        : Assignment2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/* 
NAME-HARISH CHOUDHARY
	ROLL NO-SECOA121
ASSIGNMENT2-for given expression eg. a-b*c-d/e+f construct inorder sequence
 and traverse it using postorder traversal(recursive).*/


#include<iostream>
#include<cstring>
using namespace std;
typedef  struct node
{
	char data;
	node *left,*right;
}node;
class stack
{
public:
	node *data[30];
	int top;

	stack()
	{
		top=-1;
	}
	int isstackempty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}
	int isstackfull()
	{
		if(top==29)
			return 1;
		else
			return 0;
	}
	void push(node *t)
	{
		if(isstackfull())
			cout<<"stack is full"<<endl;
		else
			data[++top]=t;

	}
	node *pop ()
	{
		node *temp;
		if(isstackempty()){
			cout<<"stack is empty"<<endl;
			return NULL;
		}
		else{

			temp=data[top];
			top--;
		}
		return temp;
	}

	node *gettop()
	{

		return data[top];


	}



};
class exptree
{
	node *root,*cn,*nn;
public:
	exptree()
{
		root=NULL;
		cn=NULL;
		nn=NULL;
}
	int priority(char ch)
	{
		if(ch=='/'||ch=='*')
			return 2;
		else if(ch=='+'||ch=='-')
			return 1;
		else
			return 0;
	}

	void create()
	{
		int i=0;
		stack sopd,sopr;
		char exp[40];
		cout<<"Enter expression"<<endl;
		cin>>exp;
		for( i=0;exp[i]!='\0';i++)
		{
			nn=new node;
			nn->data=exp[i];
			nn->left=NULL;
			nn->right=NULL;
			if(nn->data=='+'||nn->data=='-'||nn->data=='*'||nn->data=='/')
			{
				if(sopr.isstackempty())
					sopr.push(nn);
				else
				{

					node *t=sopr.gettop();

					if(priority(t->data)>=priority(nn->data))
					{
						cn=sopr.pop();
						cn->right=sopd.pop();
						cn->left=sopd.pop();
						sopd.push(cn);
						sopr.push(nn);

					}
					else
						sopr.push(nn);
				}
			}
			else
				sopd.push(nn);
		}


		while(!sopr.isstackempty())
		{
			cn=sopr.pop();
			cn->right=sopd.pop();
			cn->left=sopd.pop();
			sopd.push(cn);
		}
		root=cn;
		display(root);

	}
	void display(node *temp)
	{
		if(temp == NULL)
			return;
		display(temp->left);
		cout << temp->data;
		display(temp->right);
 }


		void non_recursive_inorder()
	{
		stack s;
		node*temp=root;
		if(root==NULL)
		{
			cout<<"underflow"<<endl;

		}
		while(1)
		{
		while(temp!=NULL)
		{

			s.push(temp);
			temp=temp->left;

		}
		if(!s.isstackempty())
		{
			temp=s.pop();
			cout<<temp->data;
			temp=temp->right;
		}
		else
			return;
		}
	}
	void non_recursive_preorder()
	{
		stack s;
		node *temp=root;
		if(root==NULL)
				{
					cout<<"underflow"<<endl;

				}
		while(1)
		{
			while(temp!=NULL)
			{
				s.push(temp);
				cout<<temp->data;
				temp=temp->left;
			}
			if(!s.isstackempty())
			{
				temp=s.pop();
				temp=temp->right;
			}
			else
				return;
		}
	}
	void non_recursive_postorder()
	{
		stack s1,s2;
		node*temp=root;
		if(root==NULL){

			cout<<"underflow"<<endl;
		}
		s1.push(temp);
		while(!s1.isstackempty())
		{
			temp=s1.pop();
			if(temp->left!=NULL){
				s1.push(temp->left);
			}
			if(temp->right!=NULL){
				s1.push(temp->right);
			}
			s2.push(temp);
		}
		while(!s2.isstackempty())
		{
			temp=s2.pop();
			cout<<temp->data;
		}

	}





};
int main()
{
	exptree E;
		char ch;
	int choice;

	do
	{
		cout<<endl;
		cout<<"Enter 1 for creation of Bst"<<endl;
		cout<<"Enter 2 for Inorder traversal"<<endl;
		cout<<"Enter 3 for Preorder traversal"<<endl;
		cout<<"Enter 4 for Postorder traversal"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			E.create();
			break;
		case 2:
			E.non_recursive_inorder();
			break;
		case 3:
			E.non_recursive_preorder();
			break;
		case 4:
			E.non_recursive_postorder();
			break;

		}
		cout<<endl<<" do u want to continue"<<endl;
		cin>>ch;
	}while(ch=='y');
	return 0;

}






/*
 OUTPUT-

 	 	 	 Enter 1 for creation of Bst
Enter 2 for Inorder traversal
Enter 3 for Preorder traversal
Enter 4 for Postorder traversal
enter your choice
1
Enter expression
a-b*c-d/e+f
a-b*c-d/e+fdo u want to continue
y

Enter 1 for creation of Bst
Enter 2 for Inorder traversal
Enter 3 for Preorder traversal
Enter 4 for Postorder traversal
enter your choice
2
a-b*c-d/e+fdo u want to continue
y

Enter 1 for creation of Bst
Enter 2 for Inorder traversal
Enter 3 for Preorder traversal
Enter 4 for Postorder traversal
enter your choice
3
-a-*bc+/defdo u want to continue
y

Enter 1 for creation of Bst
Enter 2 for Inorder traversal
Enter 3 for Preorder traversal
Enter 4 for Postorder traversal
enter your choice
4
abc*de/f+--do u want to continue
y

Enter 1 for creation of Bst
Enter 2 for Inorder traversal
Enter 3 for Preorder traversal
Enter 4 for Postorder traversal
enter your choice
5
do u want to continue
 	 	 	 */

