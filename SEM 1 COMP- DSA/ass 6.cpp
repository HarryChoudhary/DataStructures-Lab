/*
ass 6-?	The ticket booking system of Cinemax theater has to be implemented using C++ program. 
There are 10 rows and 7 seats in each row. 
Doubly circular linked list has to be maintained to keep track of free seats at rows.
 Assume some random booking to start with. Use array to store pointers (Head pointer) to each row. 
 On demand  a) The list of available seats is to be displayed  b) The seats are to be booked 
  c) The booking can be cancelled. 

*/


#include<iostream>
using namespace std;
typedef struct node
{
	string data;
	struct node *next,*prev;
	int sno;
}node;
class cinemax
{
	int i,j;
public:
	node *hn[11],*cn;
	cinemax()
{
		i=j=0;
  for(i=1;i<=11;i++)
  {
	  hn[i]=NULL;
  }
}
	void create();
	void book();
	void cancel();
	void display();
};
void cinemax::create()
{
	node *nn;

    for(i=1;i<=10;i++)
    {
     	for(j=1;j<=7;j++)
    	{
    		nn=new node;
    		nn->data='A';
    		nn->sno=j;
    		if(hn[i]==NULL)
    		{

    			hn[i]=nn;
    			hn[i]->next=hn[i];
    			hn[i]->prev=hn[i];
    		}
    		else
    		{
    			cn=hn[i];
    			while(cn->next!=hn[i])
    			{
    				cn=cn->next;
    			}
    			cn->next=nn;
    			nn->next=hn[i];
    			nn->prev=cn;
    			hn[i]->prev=nn;

    		}

    	}
    }
}
void cinemax::display()
{

	for(i=1;i<=10;i++)

	{
		cout<<i<<" "<<"ROW:"<<"\t";
	    cn=hn[i];
		while(cn->next!=hn[i])
		{

          cout<<cn->sno<<cn->data<<"\t";
          cn=cn->next;

		}

          cout<<"\n";
	}
	cout<<"\n----------------------------------------------------\n";
}
void cinemax::book()
{  int m,n,flag=0;
 cout<<"**book a seat****";
cout<<"\nenter a row no";
   cin>>m;

   if(m<1||m>10)
   {
	   cout<<"invalid row selection";
	   cout<<"reenter row no";
	   cin>>m;
   }
   cout<<"\nenter a seat no";
     cin>>n;
   if(n<1||n>7)
   {
	   cout<<"invalid seat selection";
	   cout<<"reenter seat no";
	   cin>>n;
   }
   cn=hn[m];
   	while(cn->sno!=n)
   	{  if(cn->next==hn[m]&&cn->sno!=n)
   	   {
   		flag=1;
   		break;
       }

   		cn=cn->next;
   	}
   	if(flag==1)
   	{
   		cout<<"\n seat is already booked\n";
   		return;
   	}

   	if(cn==hn[m])
   	{
   		node *temp= hn[m];
   		hn[m]->next->prev=hn[m]->prev;
   		hn[m]->prev->next=hn[m]->next;
   		hn[m]=hn[m]->next;
   		delete(temp);
   	}
   	else
   	{
   		node *temp= cn;
   		cn->prev->next=cn->next;
   		cn->next->prev=cn->prev;
   		delete(temp);
   	}

}
void cinemax::cancel()
{
	int m,n,flag=0;
		cout<<"\n**** CANCEL BOOKING *****\n\n";
		cout<<"Enter row number\n";
		cin>>m;
		cout<<"Enter seat number \n";
		cin>>n;
		node *nn=new node;
		nn->data='A';
		nn->sno=n;
		cn=hn[m];
		while(cn->next!=hn[m])
		{
			if(cn->sno==n)
			{
				flag=1;
				break;
			}
			cn=cn->next;
		}
		if(flag==1)
		{
			cout<<"seat is not booked yet\n";
			return;
		}
		cn=hn[m];
		while(cn->sno<n)
			{cn=cn->next;}
		if(cn==hn[m])
		{
			nn->next= hn[m];
			nn->prev= hn[m]->prev;
			hn[m]->prev->next=nn;
			hn[m]->prev=nn;
			hn[m]=nn;
		}
		else
		{
			nn->next= cn;
			nn->prev= cn->prev;
			cn->prev->next=nn;
			cn->prev=nn;

		}
	}

int main()
{
	cinemax c;
    char ch;
    int a,b;
	c.create();
	 cout<<"**all seats are available**\n";
	 cout<<"\n----------------------------------------------------\n";
	c.display();

	do{   cout<<"*************cinemax***********\n";
		cout<<"1.book the seat\n";
	    cout<<"2.Cancel the booking\n";
	    cout<<"enter your choice\n";
	    cin>>a;
		switch(a)
		{
		case 1: cout<<"want to book how many tickets";
		        cin>>b;
		        for(int i=0;i<b;i++)
		        { c.book();}
		        c.display();
		        break;
		case 2:  cout<<"want to cancel how many tickets";
                 cin>>b;
                for(int i=0;i<b;i++)
                { c.cancel();}

		        c.display();
		        break;

		}
		cout<<"do you want to continue";
		cin>>ch;
	}while(ch=='y');

return 0;
}

