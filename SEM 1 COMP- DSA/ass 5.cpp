//============================================================================
// Name        : harish.cpp
// Author      :
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
ASS 5-?	Department of Computer Engineering has student's club named 'Pinnacle Club'. 
Students of Second, third and final year of department can be granted membership on request.
 Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club.
  Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name.
   Write functions to  Add and delete the members as well as president or even secretary.  
   b) Compute total number of members of club c) Display members d) Display list in reverse order using recursion 
e) Two linked lists exists for two divisions. Concatenate two lists 


*/

#include <iostream>
using namespace std;

typedef struct node
{
	string data;
	struct node *next,*prev;
}node;
 class Pinacle
 {
 private :
	node *hn;
	node *ln;
	node *nn;
	node *cn;
	node *prev;
	node *hn1;
	node *ln1;
	node *nn1;
	node *cn1;
 public :
Pinacle()
 {
	hn=NULL;
	ln=NULL;
	cn=NULL;
	nn=NULL;
	prev=NULL;
	hn1=NULL;
	ln1=NULL;
	nn1=NULL;
	cn1=NULL;
 }
void create()
{
 char ch;
 cout<<"\t\t\t*******MAKE A LINK LIST*******";
 do{
     nn=new node;
     cout<<"\nEnter data in the list : ";
     cin>>nn->data;
     nn->next=NULL;
     if(hn==NULL)
     {
     hn=nn;
     ln=nn;
     }
     else
    	 {
    	 ln->next=nn;
    	 ln=nn;
    	 }
 cout<<"Do you wanna continue with the list? (y/n) : ";
         cin>>ch;
      }while(ch=='y');
     }
void display()
{
cout<<"\nYour link list is :";
        for(nn=hn;nn->next!=NULL;nn=nn->next)
        {
            cout<<nn->data<<"\t";
        }
        cout<<nn->data<<"\t";
     }
void insertStart()
{
     nn=new node;
     cout<<"\nEnter name of the president : ";
     cin>>nn->data;
     nn->next=hn;
     hn=nn;

 for(nn=hn;nn->next!=NULL;nn=nn->next)
     {
         cout<<nn->data<<"\t";
     }
     cout<<nn->data<<"\t";
}
void insertLast()
{
	  nn=new node;
	     cout<<"\nEnter name of secretary : ";
	     cin>>nn->data;
	     ln->next=nn;
	     nn->next=NULL;
	     ln=nn;

for(nn=hn;nn->next!=NULL;nn=nn->next)
	          {
	              cout<<nn->data<<"\t";
	          }
	          cout<<nn->data<<"\t";

}
void insertMiddle()
{ int a,count=0;
     cout<<"\nEnter the location where you wanna enter the new member : ";
     cin>>a;
	 nn=new node;
     cout<<"\nEnter the name of the new member : ";
	 cin>>nn->data;
	 for(cn=hn;cn!=NULL;cn=cn->next)
	 { count++;
		 if(count==a-1)
		 {  nn->next=cn->next;
			cn->next=nn;
			break;
		 }
	 }
for(nn=hn;nn->next!=NULL;nn=nn->next)
	 	          {
	 	              cout<<nn->data<<"\t";
	 	          }
	 	          cout<<nn->data<<"\t";
    }
void deleteNode()
{
	string a;
	cout<<"\nEnter the name of the member you wanna delete from the list : ";
	     cin>>a;
	     for(cn=hn;cn!=NULL;cn=cn->next)
	    	 {
			 if(cn->data!=a)
			 {
                prev=cn;
			 }
			 else
			 {
				 prev->next=cn->next;
				 delete cn;
			 }
			 }
for(nn=hn;nn->next!=NULL;nn=nn->next)
		 	          {
		 	              cout<<nn->data<<"\t";
		 	          }
		 	          cout<<nn->data<<"\t";
   }
void concatinate()
{
	cout<<"\n\n\t\t\t*******NOW MAKE THE 2ND LINK LIST*******";
	//A new link list is created
	char ch;
	 do{
	     nn1=new node;
	     cout<<"\nEnter data in the list : ";
	     cin>>nn1->data;
	     nn1->next=NULL;
	     if(hn1==NULL)
	     {
	     hn1=nn1;
	     ln1=nn1;
	     }
	     else
	    	 {
	    	 ln1->next=nn1;
	    	 ln1=nn1;
	    	 }
	 cout<<"\nDo you wanna continue with the list?";
	         cin>>ch;
	      }while(ch=='y');
	 //Concatination
	 ln->next=hn1;
	 //Display the concatinated list
	 cout<<"\n\nThe concatinated list is :\n";
	 for(nn=hn;nn->next!=NULL;nn=nn->next)
	 		 	          {
	 		 	              cout<<nn->data<<"\t";
	 		 	          }
	 		 	          cout<<nn->data<<"\t";

}
 };
 int main()
 { int choice;
 char ans;
 Pinacle obj1;
 obj1.create();
 obj1.display();
 do
 {
 cout<<"\n\nCHOOSE AN ACTION\n1).Insert a new president\n2).Insert a new secretary\n3).Insert a new member\n4).Delete an existing member\n5).Combine two lists\n";
 cin>>choice;

	 switch(choice)
	 {
 case 1 :
	 obj1.insertStart();
	 break;
 case 2 :
	 obj1.insertLast();
	 break;
 case 3 :
	 obj1.insertMiddle();
	 break;
 case 4 :
	 obj1.deleteNode();
	 break;
 case 5 :
	 obj1.concatinate();
	 break;
default :
	cout<<"Invalid input";
 }
	 cout<<"\n\nDo you wanna perform more operations?(y/n) : ";
	 cin>>ans;
 }while(ans!='n');
 return 0;
 }
