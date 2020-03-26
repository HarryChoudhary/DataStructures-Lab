//============================================================================
// Name        : harish .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================




/*
ASSIGNMENT 2
	In Second year Computer Engineering class of M students, 
set A of students play cricket and set B of students play badminton. 
Write C/C++ program to find and display- i. Set of students who play either cricket or badminton or both .
ii. Set of students who play both cricket and badminton iii. Set of students who play only cricket .
iv. Set of students who play only badminton v. Number of students who play neither cricket nor badminton
 (Note- While realizing the set duplicate entries are to avoided)

*/


#include <iostream>
using namespace std;

class set
{
	int i,j,n,b,c,f,k,cnt,rc[20],rb[20],z[20],u[20],cri[20],bad[20];
public:


	void accept()
	{
		cout<<"Enter the number of students playing sports : ";
	cin>>n;
	    cout<< "Enter the number of students who are playing badminton : ";
	cin>>b;
	    cout<< "Enter the roll numbers of the students who are playing badminton : "<<"\n";
	for(i=0;i<b;i++)
	{
	    cin>> rb[i];
	}
	cout<<"Enter the number of the students who are playing cricket : ";
    cin>>c;
        cout<<"Enter the roll numbers of the students of the students who are playing cricket : "<<"\n";
        for(j=0;j<c;j++)
        	{
        	    cin>> rc[j];
        	}
}

	void common()
	{
		int i,j;

	f=0;

		 for(i=0;i<c;i++)
		        {
			           for(j=0;j<b;j++)
		                       {
			        	            if ( rc[i]==rb[j] )
			        	              {
			        	            	z[f]=rc[i];

			        	                f++;

			        	               }

		                     }
		          }
		 cout<<"The students who are playing both sports are : "<<"\n";
		 		for(i=0;i<f;i++)
		 		{
		 			cout<<z[i]<<"\n";
		 		}

	}


	void uni()
		{
		int flag,r=0,cnt;

cout<<"The students who are playing at least one game are : "<<"\n";
		for(i=0;i<c;i++)
		{			u[r]=rc[i];
		r++;
		}

		for(int i=0;i<c;i++)
		{
                 flag=0;
			for(int j=0;j<b;j++)
			{
				if(rb[i]==rc[j])
				{	flag=1;
				break;
				}
			}
			if(flag==0)
			{
			u[r]=rb[i];
			r++;
			}

		}

	for(i=0;i<r;i++)
	{
		cout<<u[i]<<"\n";
	}
	cout<<"The students who aren't playing anything are: "<<"\n";
		cnt=n-(b+c);
		cout<<cnt<<"\n";

		}

	void onlyBadminton()
	{int flag,r=0;

		cout<<"The students who are badminton game are"<<"\n";


			  for(int i=0;i<c;i++)
					{
			                 flag=0;
						for(int j=0;j<b;j++)
						{
							if(rb[i]==rc[j])
							{	flag=1;
							break;}

						}
						if(flag==0)
									{
							cout<<rb[i]<<"\n";
									}
					}


		}


	void onlyCricket()
	{
		int flag,r=0;

		cout<<"The students who are playing cricket game are : "<<"\n";


		  for(int i=0;i<c;i++)
				{
		                 flag=0;
					for(int j=0;j<b;j++)
					{
						if(rc[i]==rb[j])
							{flag=1;
						break;
							}
					}
					if(flag==0)
								{
						cout<<rc[i]<<"\n";
								}
				}


	}

 };
 int main()
 {
	 set obj1;
	 obj1.accept();
	 obj1.common();
	 obj1.uni();
	 obj1.onlyCricket();
	 obj1.onlyBadminton();


	 return 0;

 }
