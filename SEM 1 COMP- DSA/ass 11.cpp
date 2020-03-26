/*
ass 11-?	Pizza parlor accepting maximum M orders.
 Orders are served in first come first served basis. 
 Order once placed cannot be cancelled. Write C++ program to simulate the system using circular queue using array 

*/

#include <iostream>
using namespace std;
#define MAX 5
typedef struct pizza
{
    int orderno;

}pizza;
class Pizza
{

pizza p[30];
int front,rear;
    public:
          Pizza()
          {
              front=rear=-1;
          }
          int isQempty()
{
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}
int isQfull()
{
    if((rear+1)%MAX==front||(front==0&&rear==MAX-1))
   
        return 1;
    else
        return 0;
}
         
void place_order()
{
    if(isQfull())
    {
        cout<<"\nOrders are full!!!";
    }
    else
    {
        int i;
		char ans;
        rear=(rear+1)%MAX;
        if(front==-1)
          front=rear;
        cout<<"\nEnterorder no: ";
        cin>>p[rear].orderno;

    }
}

void Serve_order()
{
    if(isQempty())
        cout<<"\nAll orders are served";
    else
    {
        if(front==rear)
        {
            front=rear=-1;
        }
        else
            front=(front+1)%MAX;
    }

}
void display()
{
    int i;
    for(i=front;i!=rear;)
        {cout<<p[i].orderno<<"\t";
		i=(i+1)%MAX;
		}
    if(rear!=-1)
      cout<<p[i].orderno;
}
};
int main()
{
    Pizza p1;
    int ch;
    char ans;
    do
    {
        cout<<"\n********PIZZA PARLOUR**********";
        cout<<"\n1.Place order";
        cout<<"\n2.Serve order";
        cout<<"\n3.Display orders";
        cout<<"\nEnter choice: ";
        cin>>ch;
        switch(ch)
        {
           case 1:cout<<"\nPlace order";
                  p1.place_order();
                  break;
           case 2:cout<<"\nServe Order";
                  p1.Serve_order();
                  break;
           case 3:cout<<"\nAll orders are: ";
                  p1.display();
                  break;
           default:cout<<"\nWrong choice ";
                   break;
        }
        cout<<"\nDo you want to continue: ";
        cin>>ans;
    }while(ans='y');
    return 0;
}

