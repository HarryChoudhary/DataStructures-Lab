/*


NAME-HARISH CHOUDHARY
	ROLL NO-SECOA121
ASSIGNMENT 8-
			A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
			deleting keywords, updating values of any entry. Provide facility to display whole data sorted
			in ascending/ Descending order. Also find how many maximum comparisons may require for
			finding any keyword. Use Height balance tree and find the complexity for finding a keyword

*/



#include <iostream>
using namespace std;
typedef struct node
{
	string word,mean;
	node *l,*r;
}node;
class avl
{
	node *root;
public:
	avl()
{
		root=NULL;
}

	node* getRoot()
	{
		return root;
	}


	node *LL(node* parent)
	{
		node *temp;
		temp=parent->l;
		parent->l=temp->r;
		temp->r=parent;
		return temp;
	}
	node *RR(node* parent)
	{
		node *temp;
		temp=parent->r;
		parent->r=temp->l;
		temp->l=parent;
		return temp;
	}
	node *RL(node* parent)
	{
		parent->r=LL(parent->r);
		parent=RR(parent);
		return parent;
	}
	node *LR(node* parent)
	{
		parent->l=RR(parent->l);
		parent=LL(parent);
		return parent;
	}
	node *insert(node* temp,string word,string mean)
	{
		if(root==NULL)
		{
			temp=new node;
			temp->word=word;
			temp->mean=mean;
			temp->l=temp->r=NULL;
			root=temp;
		}
		else if(temp==NULL)
		{

			temp=new node;
			temp->word=word;
			temp->mean=mean;
			temp->l=temp->r=NULL;
		}
		else
		{
			if(word<temp->word)
			{
				temp->l=insert(temp->l,word,mean);
				if((height(temp->l)-height(temp->r))==2)
				{
					if(word<temp->word)
					{
						temp=LL(temp);
					}
					else
					{
						temp=LR(temp);
					}
				}
			}
			else
			{
				temp->r=insert(temp->r,word,mean);
				if((height(temp->r)-height(temp->l))==2)
				{
					if(word>temp->word)
					{
						temp=RR(temp);
					}
					else
					{
						temp=RL(temp);
					}
				}
			}
		}
		return temp;
	}
	int height(node *temp)
	{
		if(temp==NULL)
			return -1;
		if(temp->l==NULL&&temp->r==NULL)
		{
			return 0;
		}

		return (1+max(height(temp->l),height(temp->l))) ;
	}
	int max(int a,int b)
	{
		if(a>b)
			return a;
		else
			return b;
	}
	void  inorder(node *temp)
	{
		if(temp!=NULL)
		{
			inorder(temp->l);
			cout<<temp->word<<"-"<<temp->mean<<"\t";
			inorder(temp->r);
		}
	}



	void search(string key)
	{

		cout<<"enter key to be searched";
		cin>>key;
		int flag=0;
		node *temp=root;
		while(temp!=NULL)
		{
			if(temp->word==key)
			{
				flag=1;
				break;
			}
			else{

				if(key<temp->word)
				{

					temp=temp->l;
				}
				else
				{
					temp=temp->r;
				}
			}


		}
		if(flag==1)
		{
			cout<<"word found ="<<temp->word<<endl;
			cout<<"meaning of word is="<<temp->mean<<endl;
		}
		else
		{
			cout<<"word not found"<<endl;

		}

	}
	void update(string key)
	{

		cout<<"Enter Word whos meaning is to be updated\n";
		cin>>key;
		node *temp;

		temp=root;

		while(temp!=NULL)
		{
			if(temp->word==key)
			{
				cout<<"enter new meaning"<<endl;
				cin>>temp->mean;
				break;
			}
			else
			{
				if(key < temp->word)
					temp=temp->l;
				else
					temp=temp->r;
			}
		}

	}
	void descending_order(node *temp)
	{
		if(temp!=NULL)
		{
			descending_order(temp->r);
			cout<<temp->word<<"-"<<temp->mean<<"\t";
			descending_order(temp->l);

		}

	}
	node *delete_node(node* cn,string dval)
	{
		node *temp;


		if(cn!=NULL)
		{
			if(dval<cn->word)
			{
				cn->l=delete_node(cn->l,dval);
				if(height(cn->l)-height(cn->r)==2||height(cn->l)-height(cn->r)==-2)
				{
					if(height(cn->r->l)-height(cn->r->r)<=0)
					{
						cout<<"\n RR rotation"<<endl;
						cn=RR(cn);
					}
					else
						cout<<"RL rotation"<<endl;
					cn=RL(cn);
				}
			}
			else if(dval>cn->word)
			{
				cn->r=delete_node(cn->r,dval);
				if(height(cn->l)-height(cn->r)==2|| height(cn->l)-height(cn->r)==-2)
				{
					if(height(cn->l->l)-height(cn->l->r)>=0)
					{
						cout<<"LL rotation"<<endl;
						cn=LL(cn);
					}
					else {
						cout<<"LR rotation"<<endl;
						cn=LR(cn);
					}
				}
			}
			else
			{
				if(cn->r==NULL)
					return(cn->l);
				else
				{
					temp=cn->r;
					while(temp->l!=NULL)
					{
						temp=temp->l;
					}
					cn->word=temp->word;
					cn->mean=temp->mean;
					cn->r=delete_node(cn->r,temp->word);
					if(height(cn->l)-height(cn->r)==2||height(cn->l)-height(cn->r)==-2)
					{
						if(height(cn->l->l)-height(cn->l->r)>=0)
							cn=LL(cn);
						else
							cn=LR(cn);
					}
				}
			}


		}
		else
			return NULL;
		return(cn);

	}

};
int main()
{
	avl a;
	node *temp;
	int choice;
	char ch;
	string key;
	string word,mean,dval;
	temp=a.getRoot();

	do{
		cout<<"Enter 1 for insertion of data"<<endl;
		cout<<"Enter 2 for display data"<<endl;
		cout<<"Enter 3 for update value"<<endl;
		cout<<"Enter 4 for search the word"<<endl;
		cout<<"enter 5 for deletion of node"<<endl;
		cout<<"enter 6 for displaying in descending order"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			do{
				cout<<"\n Enter word : ";
				cin>>word;
				cout<<"\n Enter its meaning : ";
				cin>>mean;
				temp=a.insert(temp,word,mean);
				cout<<"\n Do you want to add another word (y/n) : ";
				cin>>ch;
			}while(ch=='y'||ch=='Y');
			break;
		case 2:
			a.inorder(temp);
			break;
		case 3:
			a.update(key);
			break;
		case 4:
			a.search(key);
			break;
		case 5:
			cout<<"enter element to be deleted"<<endl;
			cin>>dval;
			a.delete_node(temp, dval);
			break;
		case 6:
			a.descending_order( temp);
			break;

		}
		cout<<"do you want to continue"<<endl;
		cin>>ch;
	}while(ch=='y');
	return 0;

}

/*
OUTPUT-
Enter 1 for insertion of data
Enter 2 for display data
Enter 3 for update value
Enter 4 for search the word
enter 5 for deletion of node
enter 6 for displaying in descending order
Enter your choice
1

 Enter word : a

 Enter its meaning : a

 Do you want to add another word (y/n) : y

 Enter word : z

 Enter its meaning : z

 Do you want to add another word (y/n) : y

 Enter word : b

 Enter its meaning : b

 Do you want to add another word (y/n) : y

 Enter word : y

 Enter its meaning : y

 Do you want to add another word (y/n) : y

 Enter word : c

 Enter its meaning : c

 Do you want to add another word (y/n) : y

 Enter word : x

 Enter its meaning : x

 Do you want to add another word (y/n) : y

 Enter word : d

 Enter its meaning : d

 Do you want to add another word (y/n) : y

 Enter word : e

 Enter its meaning : e

 Do you want to add another word (y/n) : y

 Enter word : v

 Enter its meaning : v

 Do you want to add another word (y/n) : y

 Enter word : f

 Enter its meaning : f

 Do you want to add another word (y/n) : y

 Enter word : m

 Enter its meaning : m

 Do you want to add another word (y/n) : y

 Enter word : r

 Enter its meaning : r

 Do you want to add another word (y/n) : n
do you want to continue
y
Enter 1 for insertion of data
Enter 2 for display data
Enter 3 for update value
Enter 4 for search the word
enter 5 for deletion of node
enter 6 for displaying in descending order
Enter your choice
2
a-a     b-b     c-c     d-d     e-e     f-f     m-m     r-r     v-v     x-x
y-y     z-z     do you want to continue
y
Enter 1 for insertion of data
Enter 2 for display data
Enter 3 for update value
Enter 4 for search the word
enter 5 for deletion of node
enter 6 for displaying in descending order
Enter your choice
3
Enter Word whos meaning is to be updated
b
enter new meaning
ball
do you want to continue
y
Enter 1 for insertion of data
Enter 2 for display data
Enter 3 for update value
Enter 4 for search the word
enter 5 for deletion of node
enter 6 for displaying in descending order
Enter your choice
2
a-a     b-ball  c-c     d-d     e-e     f-f     m-m     r-r     v-v     x-x
y-y     z-z     do you want to continue
y
Enter 1 for insertion of data
Enter 2 for display data
Enter 3 for update value
Enter 4 for search the word
enter 5 for deletion of node
enter 6 for displaying in descending order
Enter your choice
4
enter key to be searchedb
word found =b
meaning of word is=ball
do you want to continue
y
Enter 1 for insertion of data
Enter 2 for display data
Enter 3 for update value
Enter 4 for search the word
enter 5 for deletion of node
enter 6 for displaying in descending order
Enter your choice
5
enter element to be deleted
d
do you want to continue
y
Enter 1 for insertion of data
Enter 2 for display data
Enter 3 for update value
Enter 4 for search the word
enter 5 for deletion of node
enter 6 for displaying in descending order
Enter your choice
2
a-a     b-ball  c-c     e-e     f-f     m-m     r-r     v-v     x-x     y-y
z-z     do you want to continue
y
Enter 1 for insertion of data
Enter 2 for display data
Enter 3 for update value
Enter 4 for search the word
enter 5 for deletion of node
enter 6 for displaying in descending order
Enter your choice
5
enter element to be deleted
v
do you want to continue
y
Enter 1 for insertion of data
Enter 2 for display data
Enter 3 for update value
Enter 4 for search the word
enter 5 for deletion of node
enter 6 for displaying in descending order
Enter your choice
2
a-a     b-ball  c-c     e-e     f-f     m-m     r-r     x-x     y-y     z-z
do you want to continue
y
Enter 1 for insertion of data
Enter 2 for display data
Enter 3 for update value
Enter 4 for search the word
enter 5 for deletion of node
enter 6 for displaying in descending order
Enter your choice
6
z-z     y-y     x-x     r-r     m-m     f-f     e-e     c-c     b-ball  a-a
do you want to continue
n

--------------------------------
Process exited after 156.5 seconds with return value 0
Press any key to continue . . .

*/
