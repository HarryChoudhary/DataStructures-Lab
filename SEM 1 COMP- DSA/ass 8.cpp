//============================================================================
// Name        : well.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
ass 8-?	In any language program mostly syntax error occurs due to unbalancing delimiter 
such as (),{},[]. Write C++ program using stack to check whether given expression is well parenthesized or not

*/
#include <iostream>
using namespace std;
class stack
{
	char data[20];
	char exp[20];
	int top;
	char ch;
	int i,j;
public:
	 stack()
	{
		top=-1;
		j=0;
	}


void get_exp()
{
	cout<<"\n Enter Your Expression";
	cin>>exp;
}
int isStackempty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 char pop()
 {
	 char x;
	 if(isStackempty())
	 {
		 cout<<"\n Expression is empty"<<endl;
	 }
	 else
	 {
		 x=data[top];
		 top--;
	 }
	 return x;
 }
 void push(char c)
 {
	 top++;
	 data[top]=c;
 }
 int welformed()
 {
	 int temp=0;
	 int flag;

	 for(i=0;exp[i]!='\0';i++)
		 {
			 ch=exp[i];
			 if(exp[i]=='('||ch=='{'||ch=='[')
			 {
				 push(ch);

			 }
			 else if(exp[i]==')'||ch=='}'||ch==']')
			 {
			 	 if(! isStackempty())
				 temp=pop();
				 else
				 push(ch);
				 
			 }

		 }
	 if((exp[i]==')'&&temp=='(')||(exp[i]=='}'&&temp=='{')||(exp[i]==']'&&temp=='['))
	 {
		 flag=0;

	 }
	 else
	 {
		 flag=1;



	 }
	 if( isStackempty()&&flag==1)
	 {
		 cout<<"well formed paranthesis";
	 }
	 else
		 cout<<"mismatch found";
 }
};
int main()
{
	stack s;
	s.get_exp();
	s.welformed();
	return 0;
}



