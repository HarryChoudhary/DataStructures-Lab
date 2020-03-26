//============================================================================
// Name        : binary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================




/*
ass 12-	 Write C++ program to store roll numbers of student in array who attended training program in random order. 
Write function for- a) Searching whether particular student attended training program or not using linear search and sentinel search.
 b) Searching whether particular student attended training program or not using binary search and Fibonacci search 

*/

#include<iostream>
using namespace std;
class search
{

	int n,i,j;
int rollno[5];
public:
	void getdata()
	{
		cout<<"enter how many numbers u want"<<endl;
		cin>>n;
		cout<<"roll no of students are="<<endl;
		for(i=0;i<n;i++)
		{

		cin>>rollno[i];
		cout<<"\n";
	}
	}
		void linearsearch()
		{
			int key,flag=0;
				cout<<"ENTER THE roll no  YOU WANT TO SEARCH";
				cin>>key;
				for(int i=0;i<n;i++)
				{
					if(rollno[i]==key)
					{
						cout<<"roll no FOUND AT POSITION"<<"\t"<<i+1<<endl;
						flag=1;
						break;
					}
					else
						cout<<"element not found"<<endl;
					break;
		}

		}
		void sort(){
			float temp;
			cout<<"sorted are"<<endl;
								for(i=0;i<n;i++)
								{
									for(j=i+1;j<n;j++)
									{

										if(rollno[j]<rollno[i])
										{
											temp=rollno[i];
											rollno[i]=rollno[j];
										rollno[j]=temp;

									}
									}
								}
								for(i=0;i<n;i++)
											{
												cout<<rollno[i]<<endl;
											}
								cout<<"\n";

		}
		void binarysearch()
		{


			 int key,flag=0;
			int low=0;
			int high=n-1;
			 int mid=(low+high)/2;
					cout<<"\n";

		cout<<"ENTER THE ROLL NO YOU WANT TO SEARCH"<<endl;
			cin>>key;
			 for(i=0;i<n;i++)
			 {


				 if(key==rollno[mid])
				 {
					 cout<<"element found"<<key;
					 break;
				 }
				 else if(key<rollno[mid])
				 {
					  low=0;
					 high=mid-1;
				 cout<<"ELEMENT FOUND"<<key;
				 break;
				 }

				 else
			 {
				 low=mid+1;
				 break;
			 }

			 }
			}
	


	};
	int main()
		{
			search s;
				int choice;
				cout<<"1.binary search"<<endl;
				cout<<"2.linear search"<<endl;
				cout<<"ENTER YOUR CHOICE"<<endl;
				cin>>choice;
				switch(choice)
				{
				case 1:
					s.getdata();
					s.sort();
					s.binarysearch();
					break;
				case 2:
					s.getdata();
					s.linearsearch();
					break;
			

				}
			return 0;

		}
