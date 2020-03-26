package my_pack;
import java.util.Scanner;

public class employee {
	private String name;
	private String addr;
	public double salary;
	
	public void accept()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter name of employee :");
		name=sc.next();
		System.out.println("Enter address of the employee : ");
		addr=sc.next();
		System.out.println("Enter Basic Salary : ");
		salary=sc.nextDouble();
		
	}
	
	public void display(double salary)
	{
		System.out.println("\nName : "+name+"\nAddress : "+addr+"\nSalary : "+salary);
	}

}


