import my_pack.Int_my;
import my_pack.employee;
import java.util.Scanner;


public class Labour implements Int_my{

		public double calculate_salary(double salary,double TA,int DA,double HRA)
	{
			TA=salary*(TA/100);
			HRA=salary*(HRA/100);
			salary=salary+TA+DA+HRA;
			return salary;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		employee[] e=new employee[20];
		Labour[] l=new Labour[20];
		int choice,f=0;
		double p;
		for(int i=0;i<20;i++)
			e[i]=new employee();
		for(int i=0;i<20;i++)
			l[i]=new Labour();
		Scanner sc1=new Scanner(System.in);
		
		do
		{
		System.out.println("\n\n(1)Enter details of employee\n(2)Display total salary\n(3)Exit");
		
		System.out.println("Enter your choice : ");
		choice=sc1.nextInt();
		switch(choice)
		{
		case 1:e[f].accept();
				f++;
		break;
		case 2:
			System.out.println("\nEmployee details :-");
			for(int i=0;i<f;i++)
			{
				p=l[i].calculate_salary(e[i].salary,119,2400,10);
				e[i].display(p);
			}
			break;
		case 3: System.exit(0);
		break;
		}
		
		}while(choice<4);
		sc1.close();
		
	}

}
