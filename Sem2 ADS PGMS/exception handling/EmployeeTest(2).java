import java.io.*;
import java.util.Scanner;
class Employee {

   String name;
   int age;
   String designation;
   double salary;

   // This is the constructor of the class Employee
   public Employee(String name) {
      this.name = name;
   }

   // Assign the age of the Employee  to the variable age.
   public void empAge(int empAge) throws InvalidInputException
   {
	if(empAge<18)
	   throw new InvalidInputException("Exception");
	else
		 System.out.println("Age:" + empAge );
	   }

   /* Assign the designation to the variable designation.*/
   public void empDesignation(String empDesig) {
      designation = empDesig;
   }

   /* Assign the salary to the variable	salary.*/
   public void empSalary(double empSalary) {
      salary = empSalary;
   }

   /* Print the Employee details */
   public void printEmployee() {
      System.out.println("Name:"+ name );
    //  System.out.println("Age:" + age );
      System.out.println("Designation:" + designation );
      System.out.println("Salary:" + salary);
   }
}

public class EmployeeTest {

   public static void main(String args[]) {
      /* Create two objects using constructor */
      Employee empOne = new Employee("James Smith");
      Employee empTwo = new Employee("Mary Anne");

      // Invoking methods for each object created
	 Scanner scanner = new Scanner(System.in);
        System.out.println(" enter age of employee 1");
        int age = scanner.nextInt();

       

try{
      empOne.empAge(age);
}
catch( InvalidInputException S)
{
    System.out.println(" Exception caught for age");
}
      empOne.empDesignation("Senior Software Engineer");
      empOne.empSalary(1000);
     System.out.println(" Details of employee 1");
       
      empOne.printEmployee();

 System.out.println(" enter age of employee 2");
        int age1 = scanner.nextInt();

try{
     empTwo.empAge(age1);
}
catch( InvalidInputException S)
{
    System.out.println(" Exception caught for age");
}


      empTwo.empDesignation("Software Engineer");
      empTwo.empSalary(500);
 System.out.println(" Details of employee 1");
      empTwo.printEmployee();
   }
}


class InvalidInputException extends Exception
{  
    InvalidInputException(String exceptionText)
	{  
        super(exceptionText);  
        }    
}
