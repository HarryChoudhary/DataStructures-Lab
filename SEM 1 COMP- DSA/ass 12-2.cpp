/*
ASS 12-?	 Write C++ program to store roll numbers of student in array who attended training program in random order.
 Write function for- a) Searching whether particular student attended training program or not using linear search and sentinel search. 
 b) Searching whether particular student attended training program or not using binary search and Fibonacci search 


*/

#include<iostream>
using namespace std;

class fibonacci
{
int n,rollno[60];
public:


int fibo(int n)
{
	if(n==0 || n==1)
		return 1;
	else
	return	fibo(n-1)+fibo(n-2);
}


void getrollno()
{
	cout<<"\n Enter Total number of students : ";
	cin>>n;
	cout<<"Enter the roll Number ";
	for(int i=0;i<n;i++)
	{
		cin>>rollno[i];

	}
}
void display()
{
	cout<<"\n List of roll Numbers ";
	for(int i=0;i<n;i++)
	{
	cout<<"\n"<<rollno[i];
	}
}
int fibonaccisearch(int key)
{
int f,f1,f2,mid,j;
j=1;
while(fibo(j)<=n)
{
	fibo(j);
	j++;
}
f=fibo(j);
f1=fibo(j-2);
f2=fibo(j-3);
mid=n-f1+1;
while(key!=rollno[mid])
{
if(mid<0 || key > rollno[mid])
{
	if(f1==1)
		return -1;
	else
		mid=mid+f2;
	    f1=f1-f2;
        f2=f2-f1;

}
else
{
	if(f2==0)
		return -1;
	else
	{
		mid=mid-f2;
		int t=f1-f2;
		f2=f1;
		f1=t;
	}
}
}
return mid;
}
void dispalyroll()
{
int roll,findroll;
cout<<"\n Enter the roll Number you are looking for";
cin>>findroll;
roll=fibonaccisearch(findroll);
if(roll == -1)
	cout<<"\n Student was not present";
else
	cout<<"\n roll Number "<< rollno[roll] <<" was present ";
}
};
int main()
{
	fibonacci f;
	f.getrollno();
	f.display();
	f.dispalyroll();
	return 0;
}



