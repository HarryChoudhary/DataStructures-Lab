//============================================================================
// Name        : sentinalsearch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
ASS 12-?	 Write C++ program to store roll numbers of student in array who attended training program in random order.
 Write function for- a) Searching whether particular student attended training program or not using linear search and sentinel search.
  b) Searching whether particular student attended training program or not using binary search and Fibonacci search 


*/

#include <iostream>
using namespace std;
#define size 100
class sentinel
{
	int data[size];
	int n;
	public:
	void acceptData()
		{
			cout<<"Enter Number of Elements :\t";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cout<<"Enter The Element:\t";
				cin>>data[i];
			}
		}
	void search()
	{
		int last = data[n-1],temp;
		cout<<"Enter The Element to be searched";
		cin>>temp;
		last = temp;
		int i = 0;
		while(data[i] != temp)
		{
			i++;
		}
		last = data[n-1];
		if(i<(n-1) || temp == last)
		{
		cout<<"Element Found";
		}
		else
		{
			cout<<"Not found";
		}
	}
};

int main()
{
	sentinel sn;
	sn.acceptData();
	sn.search();
	return 0;
}
