

/*
ass 7-?	Write C++ program for storing binary number using doubly linked lists. Write functions-  
a) to compute 1‘s and 2‘s complement b) add two binary numbers 

*/
#include <iostream>
using namespace std;
typedef struct node
{
	int bd;
	struct node *next;
	struct node *prev;
}node;

class dll
{

public:
    node *hn,*ln;   int b;
	dll()
	{
        hn=NULL; ln=NULL;
	}
    node * create()
    {

        hn=NULL;

		node *nn,*cn;
        cout<<"\nEnter number of BITS of binary number ";
		cin>>b;
		cout<<"Enter binary number:"<<endl;
        for(int i=0;i<b;i++)
		{
		nn=new node;
		cin>>nn->bd;
		nn->next=NULL;
		nn->prev=NULL;

		if(hn==NULL)
        {hn=nn;  ln=nn;}
			else
			{
				cn=hn;
				while(cn->next!=NULL)
				{
					cn=cn->next;
				}

			cn->next=nn;
		nn->prev=cn;
        ln=nn;
			}
		}

        return hn;
	}
	void disp(node *pq)
	{

		node *cn;
		cn=pq;
		while(cn!=NULL)
		{
		    cout<<cn->bd;
                    cn=cn->next;
                }


	}
	void ones()
	{
        cout<<"\nOne's Complement: "<<endl;
        node *cn; 
        cn=hn;
		while(cn!=NULL)
			{
			if(cn->bd==0)
            {	cout<<1; }
			else cout<<0;
			cn=cn->next;
			}
       
	}
	void twos()
	{


        cout<<"\n2's Complement:\n";
       
        node *cn,*t,*x;	int flag=0; int m;
		t=ln;
	for(cn=ln;cn!=NULL;cn=cn->prev)
	{
			if(flag==0)
		{
			if(cn->bd==0)
			t->bd=0;
			else
			{
			t->bd=1;
			flag=1;
			}
		}
			else
			{
				if(cn->bd==0)
				t->bd=1;
				else t->bd=0;
			}
			x=t;
			t=t->prev;
            		m=cn->bd;
			
	}


	disp(x);

	}

    void add()
    {

        node *hn1,*hn2;
        node *l1,*l2;
        cout<<"\n\nBinary number 1\n";
        hn1=create();
         l1=ln;
        cout<<"\n\nBinary number 2\n";
        hn2=create();
        l2=ln;
        cout<<"\nNumber 1: ";
        disp(hn1); cout<<endl;
        cout<<"\nNumber 2: ";
        disp(hn2); cout<<endl;

        int A[20]; int p=0;
        cout<<"\nAddition is\n";

        int cy=0;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->bd==l2->bd&&l1->bd==0)
            {
                A[p]=0+cy;

                p++;
                cy=0;

            }
         else if(l1->bd==l2->bd&&l1->bd==1)
            {
               A[p]=0+cy;

               p++;

               cy=1;

            }
            else if(l1->bd!=l2->bd)
            {
                  if(cy==1)
                {
                     A[p]=0;

                     p++;
                  cy=1;

                  }
                  else
                     {
                     A[p]=1;

                     p++;

                  }
            }
          l1=l1->prev;
          l2=l2->prev;

        }
        while(l1!=NULL)
        {

            if(cy==0)
             {   A[p]=l1->bd;
            p++;
                }
            else if(l1->bd==1&&cy==1)
            {
                A[p]=0;
                p++;
            }
            else if(l1->bd==0&&cy==1)
            {
                A[p]=1;
                p++;
                cy=0;
            }
            l1=l1->prev;
        }
        while(l2!=NULL)
        {

            if(cy==0)
             {   A[p]=l2->bd;
            p++;
                }
            else if(l2->bd==1&&cy==1)
            {
                A[p]=0;
                p++;
            }
            else if(l2->bd==0&&cy==1)
            {
                A[p]=1;
                p++;
                cy=0;
            }
            l2=l2->prev;

        }
        if(cy==1)
        {
            A[p]=cy;

            p++;
        }
        for(int i=p-1;i>=0;i--)
            cout<<A[i];


    }
};

int main()
{
	dll obj;

node *p;


cout<<"****Menu****\n";
cout<<"1. Enter Binary Number\n";
cout<<"2. Display number\n";
cout<<"3. Calculate One's Complement\n";
cout<<"4. Calculate Two's Complement\n";
cout<<"5. Add Two Binary Numbers\n";
cout<<"6. Exit\n";

int ch;
do{
    cout<<"\nEnter Choice:\t";
     cin>>ch;
    switch(ch)
    {
    case 1: obj.create();
            p=obj.hn; break;
    case 2: cout<<"\nEntered Number is ";
        p=obj.hn;
            obj.disp(p); cout<<endl;break;
    case 3: obj.ones(); cout<<endl; break;
    case 4: obj.twos(); cout<<endl; break;
    case 5: obj.add();  cout<<endl; break;
    case 6: cout<<"Exit.\n"; break;
    default: ch=6; cout<<"Exit.\n"; break;
    }
}while(ch!=6);

}
