

//Java program to illustrate the  concept of inheritance
 

// base class

class Bicycle

{

public int gear; // the Bicycle class has two fields

public int speed;

public Bicycle(int gear, int speed) // the Bicycle class has one constructor

{

this.gear = gear;

this.speed = speed;

}public void applyBrake(int decrement)

{

speed -= decrement;

}

// the Bicycle class has three methods

public void speedUp(int increment)

{

speed += increment;

}

public String toString() // toString() method to print info of Bicycle

{

return("No of gears are "+gear+"\n"+ "speed of bicycle is "+speed);

}

}

class MountainBike extends Bicycle

{

// derived class

public int seatHeight; // the MountainBike subclass adds one more field

public MountainBike(int gear,int speed, int startHeight) // the MountainBike subclass has one constructor

{

super(gear, speed);// invoking base-class(Bicycle) constructor

seatHeight = startHeight; 

}

public void setHeight(int newValue)

{

seatHeight = newValue;

}

// the MountainBike subclass adds one more method

public String toString()

// overriding toString() method of Bicycle to print more info

{
return (super.toString()+"\nseat height is "+seatHeight);
}

}

public class Test // driver class

{

public static void main(String args[])

{

MountainBike mb = new MountainBike(3, 100, 25);

System.out.println(mb.toString());

}

}

/*
Output:

No of gears are 3

speed of bicycle is 100

seat height is 25
*/
