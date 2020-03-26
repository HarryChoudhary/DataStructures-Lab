//==================================================================
// Name        : infi to postfix.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
ass 9-?	Implement C++ program for expression conversion as infix to postfix and its evaluation using stack
 based on given conditions i. Operands and operator, both must be single character. 
 ii. Input Postfix expression must be in a desired format. iii. Only '+', '-', '*' and '/ ' operators are expected. 

*/


#include <iostream>
using namespace std;
class stack
{
	char data[20];
	char infix[20];
	char postfix[20];
	char post[20];
	int top;
	char ch;
	int nu;
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
	cin>>infix;
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
		 cout<<"\n stack is empty";
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
 
 void display()
 {
	 for(int i=0;postfix[i]!='\0';i++)
	 {
		 cout<<postfix[i];
	 }
 }
 int prior(char ch)
 {
 	if(ch=='^')
 	return 3;
	 else if(ch=='*'||ch=='/')
	 {
		 return 2;
	 }
	 else if(ch=='+'||ch=='-')
	 {
		 return 1;
	 }
	 else
		 return 0;
 }
void infixtopostfix()
 {
 	int a;
	 for(i=0;infix[i]!='\0';i++)
	 {
		 ch=infix[i];

			 if(ch=='(')
			 {
				 push(ch);
			 }
			 else if((ch=='+'||ch=='-')||(ch=='/'||ch=='*')||(ch=='^'))
			 {
				 if(isStackempty())
				 {
					 push(ch);
				 }
				 else
				 {
					 if(prior(data[top])>=prior(ch))
					 {
						 postfix[j]=pop();
						 j++;
						 push(ch);

					 }
					 else{
						 push(ch);
					 }


				 	}

			 }
			 else if(ch==')')
			 {
				 char k;
				 k=pop();
				 while( k!='(')
				 {
					 postfix[j]=k;
					 j++;
					 k=pop();
				 }
			 }
			 else
			 {
				 postfix[j]=ch;
				 j++;
			 }
	 }
	 while(!isStackempty())
	 {
		 postfix[j]=pop();
		 j++;

	 }
cout<<postfix[i];
	 cout<<endl;

 }

void evaluate()
{
	cout<<endl;
	cout<<"evaluation is";
int n1,n2,n3,c;

for(int i=0;postfix[i]!='\0';i++)
{
ch=postfix[i];
if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
{
n1=pop();
n2=pop();
switch(ch)
{
case '+':
n3=n1+n2;
c=n3;
push(c);
break;
case '-':
n3=n2-n1;
c=n3;
push(c);
break;
case '*':
n3=n1*n2;
c=n3;
push(c);
break;
case '/':
n3=n2/n1;
c=n3;
push(c);
break;
case '^':
	n3=n2^n1;
	c=n3;
	push(c);
	break;
}
}
else
{
	int a=(ch)-48;
	push(a);

}
}
int x=pop();
cout<<x;
}

};
int main()
{
	stack s1;
	s1.get_exp();
	s1.infixtopostfix();
	s1.display();
s1.evaluate();
	return 0;
}
 
