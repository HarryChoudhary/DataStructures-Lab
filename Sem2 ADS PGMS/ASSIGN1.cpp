/*

	NAME-HARISH CHOUDHARY
	ROLL NO-SECOA121
	ASSIGNMENT 1-
				A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
				deleting keywords, updating values of any entry. Provide facility to display whole data sorted
				in ascending/ Descending order. Also find how many maximum comparisons may require for
				finding any keyword. Use Binary Search Tree for implementation.
*/



#include <iostream>
#include<string>

using namespace std;
typedef struct node
{
	string word;
	string meaning;
	node *left,*right;
}node;

class BST
{

public:
	node *root;
	BST()
	{
		root=NULL;
	}

node* create()
{
	node *parent,*temp;
	char ch;
	do
	{
		node *nn;
		nn=new node;
		cout<<"\n Enter word\n";
		cin>>nn->word;
		cout<<"\n Enter Meaning\n";
		cin>>nn->meaning;
		nn->left=NULL;
		nn->right=NULL;
		if(root==NULL)
		{
			root=nn;
		}
		else
		{
			temp=root;
			while(temp!=NULL)
			{
				parent=temp;
				if(nn->word < temp->word)
					temp=temp->left;
				else
					temp=temp->right;
			}
			if(nn->word < parent->word)
				parent->left=nn;
			else
				parent->right=nn;;
		}
		cout<<"\n Whether you wish to continue\n";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	return root;
}


void display(node *temp)
{
	if(temp!=NULL)
	{
		display(temp->left);
		cout<<temp->word<<"-"<<temp->meaning<<"\n";
		display(temp->right);
	}
}

void search1()
{
    string key;
    cout<<"Enter Word\n";
    cin>>key;
    node *temp;
    int flag=0;
    temp=root;

    while(temp!=NULL)
    {
        if(temp->word==key)
        {
            flag=1;
            break;
        }
        else
        {
            if(key < temp->word)
                temp=temp->left;
            else
                temp=temp->right;
        }
    }

    if(flag==1)
        cout<<"\nMeaning:"<<temp->meaning;
    else
        cout<<"\n Word not found";
}

void delete1(string key)
{
    node *temp,*parent;
    int flag=0;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->word==key)
        {
            flag=1;
            break;
        }
        else
        {
            parent=temp;
            if(key < temp->word)
                temp=temp->left;
            else
                temp=temp->right;
        }
    }
        if(flag==0)
        {
            cout<<"\n Word not found";
        }
        else
        {
            if(temp->left==NULL && temp->right==NULL)
            {
                if(temp==root)
                {
                    root=NULL;
                    return;
                }
                else if(temp->word < parent->word)
                    parent->left=NULL;
                else
                    parent->right=NULL;
                delete temp;
                return;
            }
            else if(temp->left!=NULL && temp->right==NULL)
            {
                if(temp->word < parent->word)
                    parent->left=temp->left;
                else
                    parent->right=temp->left;
                delete temp;
                return;
            }
            else if(temp->left==NULL && temp->right!=NULL)
            {
                if(temp->word < parent->word)
                    parent->left=temp->right;
                else
                    parent->right=temp->right;
                delete temp;
                return;
            }
            else
            {
                node *parent1=temp;
                temp=temp->left;
                while(temp->right!=NULL)
                    temp=temp->right;
                string tword=temp->word;
                string tmeaning=temp->meaning;
                delete1(temp->word);
                parent1->word=tword;
                parent1->meaning=tmeaning;
                return;
            }
        }

}


void displayrev(node *temp)
{
	if(temp!=NULL)
		{
			displayrev(temp->right);
			cout<<temp->word<<"-"<<temp->meaning<<"\n";
			displayrev(temp->left);
		}
}
};
int main()
{
    BST b;
    int n;
    char ch;
    string key;
    do
    {

    cout<<"\n*****Dictionary******";
    cout<<"\n 1.CREATE";
    cout<<"\n 2.SEARCH";
    cout<<"\n 3.DELETE";
    cout<<"\n 4.DISPLAY";
    cout<<"\n 5.DISPLAY REVERSE";
    cout<<"\n 6.EXIT";
    cout<<"\n Enter your choice\n";
    cin>>n;
    switch(n)
    {
    case 1:
        node *root;
        root=b.create();
        b.display(root);
        break;
    case 2:
        b.search1();
        break;
    case 3:
        cout<<"\n Enter Key";
        cin>>key;
        b.delete1(key);
        b.display(root);
        break;
    case 4:
        b.display(root);
        break;
    case 5:
    	b.displayrev(root);
    	break;
    case 6:
       // exit(1);
        break;
    }
    cout<<"\n Whether you wish to continue\n";
    cin>>ch;
    }while(ch=='y'||ch=='Y');
	return 0;
}


/*
enter 1 for create dictionary
enter 2 add new record
enter 3 for delete a record
enter 4 for search dictionary
enter  5 for update meaning
enter 6 for display ascending order
enter 7 for display descending order
enter your choice
1
enter word u want
b
enter meaning
ball
do want to continuey
enter word u want
a
enter meaning
apple
do want to continuey
enter word u want
z
enter meaning
zev
do want to continuey
enter word u want
d
enter meaning
dd
do want to continuey
enter word u want
h
enter meaning
hh
do want to continuen

do u want to continue
y
enter 1 for create dictionary
enter 2 add new record
enter 3 for delete a record
enter 4 for search dictionary
enter  5 for update meaning
enter 6 for display ascending order
enter 7 for display descending order
enter your choice
6
word is=a       meaning is=apple
word is=b       meaning is=ball
word is=d       meaning is=dd
word is=h       meaning is=hh
word is=z       meaning is=zev
do u want to continue
y
enter 1 for create dictionary
enter 2 add new record
enter 3 for delete a record
enter 4 for search dictionary
enter  5 for update meaning
enter 6 for display ascending order
enter 7 for display descending order
enter your choice
2
enter word u want
a
enter meaning
apple
do want to continuey
enter word u want
w
enter meaning
w
do want to continuen

do u want to continue
y
enter 1 for create dictionary
enter 2 add new record
enter 3 for delete a record
enter 4 for search dictionary
enter  5 for update meaning
enter 6 for display ascending order
enter 7 for display descending order
enter your choice
6
word is=a       meaning is=apple
word is=a       meaning is=apple
word is=b       meaning is=ball
word is=d       meaning is=dd
word is=h       meaning is=hh
word is=w       meaning is=w
word is=z       meaning is=zev
do u want to continue
y
enter 1 for create dictionary
enter 2 add new record
enter 3 for delete a record
enter 4 for search dictionary
enter  5 for update meaning
enter 6 for display ascending order
enter 7 for display descending order
enter your choice
3
enter key to be searcheda

node is deleted
do u want to continue
y
enter 1 for create dictionary
enter 2 add new record
enter 3 for delete a record
enter 4 for search dictionary
enter  5 for update meaning
enter 6 for display ascending order
enter 7 for display descending order
enter your choice
6
word is=a       meaning is=apple
word is=b       meaning is=ball
word is=d       meaning is=dd
word is=h       meaning is=hh
word is=w       meaning is=w
word is=z       meaning is=zev
do u want to continue
y
enter 1 for create dictionary
enter 2 add new record
enter 3 for delete a record
enter 4 for search dictionary
enter  5 for update meaning
enter 6 for display ascending order
enter 7 for display descending order
enter your choice
3
enter key to be searcheda

deleted word is
do u want to continue
y
enter 1 for create dictionary
enter 2 add new record
enter 3 for delete a record
enter 4 for search dictionary
enter  5 for update meaning
enter 6 for display ascending order
enter 7 for display descending order
enter your choice
6
word is=b       meaning is=ball
word is=d       meaning is=dd
word is=h       meaning is=hh
word is=w       meaning is=w
word is=z       meaning is=zev
do u want to continue
y
enter 1 for create dictionary
enter 2 add new record
enter 3 for delete a record
enter 4 for search dictionary
enter  5 for update meaning
enter 6 for display ascending order
enter 7 for display descending order
enter your choice
5
enter key to be updatedb
enter new meaning of word
bat

do u want to continue
y
enter 1 for create dictionary
enter 2 add new record
enter 3 for delete a record
enter 4 for search dictionary
enter  5 for update meaning
enter 6 for display ascending order
enter 7 for display descending order
enter your choice
6
word is=b       meaning is=bat
word is=d       meaning is=dd
word is=h       meaning is=hh
word is=w       meaning is=w
word is=z       meaning is=zev
do u want to continue
y
enter 1 for create dictionary
enter 2 add new record
enter 3 for delete a record
enter 4 for search dictionary
enter  5 for update meaning
enter 6 for display ascending order
enter 7 for display descending order
enter your choice
7
word is =z      meaning is =zev
word is =w      meaning is =w

word is =h      meaning is =hh

word is =d      meaning is =dd


word is =b      meaning is =bat

do u want to continue
n

--------------------------------
Process exited after 124.6 seconds with return value 0
Press any key to continue . . .
*/
