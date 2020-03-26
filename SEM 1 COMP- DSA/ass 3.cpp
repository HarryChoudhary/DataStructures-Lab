/*
ASS 3-
?	Write C++ program for string operations- copy, concatenate, check substring, equal, reverse and length 

*/
#include<iostream>
using namespace std;

class strings
{
public:
	int i,l=0,l2=0;
	char a[10],c[10];

public:
	void input();
	void length();
	void copy();
	void con();
	void rev();
	void equal();
	void sub();

};

void strings::input()
{
	cout<<"enter the string";
	cin>>a;
}

void strings::length()
{
	for(i=0;a[i]!='\0';i++)
	{
		l++;
	}
	cout<<"length of string is \t"<<l<<endl;

}

void strings::copy()
{
	int j=0;
	char b[10];
	for(i=0;i<l;i++)
	{
		b[j]=a[i];
		j++;
	}
	cout<<"the copied string is \t"
			;
	for(i=0;i<l;i++)
	{
		cout<<b[i];
	}
}

void strings::con()
{
	int j=0,r;
		char b[10];
		cout<<"\n enter another string for concatenation";
		cin>>c;
		for(i=0;c[i]!='\0';i++)
			{
				r++;
			}
		for(i=0;i<l;i++)
		{
			b[j]=a[i];
			j++;
		}
		for(i=0;i<r;i++)
		{
			b[j]=c[i];
			j++;
		}
		cout<<"concatenated string is \t";
		for(i=0;i<(l+r);i++)
		{
			cout<<b[i];
		}
}

void strings::rev()
{
	cout<<"\n reverse of string is: \t";
	for(i=(l-1);i>=0;i--)
	{
		cout<<a[i];
	}
}

void strings::equal()
{
	cout<<"\n enter a string to compare";
	cin>>c;
	for(i=0;c[i]!='\0';i++)
	{
		l2++;
	}
	i=0;
	while(a[i]!='\0')
	{
		if(a[i]==c[i])
		{
			i++;
		}
		else
			break;
	}
	if(i==l)

		cout<<"strings are equal."<<endl;

	else
		cout<<"strings are not equal"<<endl;

}

void strings::sub()
{
	int j,flag=0;
	cout<<"enter string for comparing substring";
	cin>>c;
	for(i=0;c[i]!='\0';i++)
		{
			l2++;
		}
	for(i=0;i<=(l-l2);i++)
	{
		for(j=i;j<(i+l2);j++)
		{
			flag=1;
			if(a[j]!=c[j-i])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			break;
		}
	}
	if(flag==1)
		cout<<"substring is present.";
	else
		cout<<"substring is not present.";
}

int main ()
{
	strings a;
	a.input();
	a.length();
	a.copy();
	a.con();
	a.rev();
	a.equal();
	a.sub();

}
