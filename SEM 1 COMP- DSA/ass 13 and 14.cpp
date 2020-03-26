//============================================================================
// Name        : bubble and selection sort and quick sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
ASS 13-?	Write C++ program to store first year percentage of students in array.
 Write function for sorting array of floating point numbers in ascending order using a) Selection Sort
  b) Bubble sort and display top five scores .

*/
/*
ASS 14-?	 Write C++ program to store first year percentage of students in array. 
Sort array of floating point numbers in ascending order using quick sort and display top five scores. 

*/

#include<iostream>
using namespace std;
class sort
{
	int n,i,j;
	float percentage[5];
public:
	void getdata()
	{
		cout<<"enter how many numbers u want"<<endl;
		cin>>n;
		cout<<"percentage are="<<endl;
		for(i=0;i<n;i++)
		{

		cin>>percentage[i];
		cout<<"\n";
	}
	}
		void bubblesort()
		{

			float temp;
			cout<<"\n";
			cout<<"sorted are"<<endl;
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{

					if(percentage[j]<percentage[i])
					{
						temp=percentage[i];
						percentage[i]=percentage[j];
						percentage[j]=temp;
				}
				}
			}



			}
		void selectionsort()
		{
		float temp;


			int min;
			for(int i=0;i<n;i++)
			{
				min=i;
				for(int j=i+1;j<n;j++)
				{
					if(percentage[j]<percentage[min])
					min=j;
				}
				temp=percentage[i];
				percentage[i]=percentage[min];
				percentage[min]=temp;
		}
		}




		void display()

		{
			cout<<"\n";
			for(i=0;i<n;i++)
			{
				cout<<percentage[i]<<endl;
			}


		}
		void quick_sort(int low ,int high)
{
int j;
if(low<high){
j=partition(percentage, low,high);
quick_sort(low,j-1);
quick_sort(j+1,high);
}
}
int partition(float percentage[],int low ,int high)
{
	float pivot,temp;
	int i,j;
	pivot = percentage[low];
    i= low + 1;
    j= high;

    while(i<j)
    {
    	while(percentage[i]<pivot && i<= high)
    		i++;
    	while(percentage[j] > pivot)
    		j--;
if(i<j)
{
	temp=percentage[i];
	percentage[i]=percentage[j];
	percentage[j]=temp;
}
    }
 if(j<i){
percentage[low] = percentage[j];
percentage[j]=pivot;
 }
return j;
}



};
	int main()
	{
		int temp;
		sort s;
			int choice;
			cout<<"1.SELECTION SORT"<<endl;
			cout<<"2.BUBBLE SORT"<<endl;
			cout<<"3.QUICK SORT"<<endl;
			cout<<"ENTER YOUR CHOICE"<<endl;
			cin>>choice;
			switch(choice)
			{
			case 1:
				s.getdata();
				s.selectionsort();
				s.display();
				break;
			case 2:
				s.getdata();
				s.bubblesort();
				s.display();
				break;
					case 3:
			s.getdata();
			s.quick_sort(0,temp-1);
			s.display();
				break;
			}
		return 0;

	}
