// Assignment #: 5
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30-5:45
//  Description: Driver class for Assignment 5

import java.io.*;         //to use InputStreamReader and BufferedReader
import java.util.*;       //to use ArrayList

public class Assignment5
 {
  public static void main (String[] args)
   {
     char input1;
     String inputInfo = new String();
     String line = new String();
     boolean operation;

     // ArrayList object is used to store employee objects
     // complier was NOT happy with this.
     ArrayList<Employee> employeeList = new ArrayList<Employee>();

     try
      {
       printMenu();     // print out menu

       // create a BufferedReader object to read input from a keyboard
       InputStreamReader isr = new InputStreamReader (System.in);
       BufferedReader stdin = new BufferedReader (isr);

       do
        {
         System.out.println("What action would you like to perform?");
         line = stdin.readLine().trim();
         input1 = line.charAt(0);
         input1 = Character.toUpperCase(input1);

         if (line.length() == 1)
          {
           switch (input1)
            {
             case 'A':   //Add Employee
               System.out.print("Please enter some employee information to add:\n");
               inputInfo = stdin.readLine().trim();
               employeeList.add(EmployeeParser.parseStringToEmployee(inputInfo));
/***********************************************************************************
***  ADD your code here to create an object of one of child classes of Employee class
***  and add it to the employeeList
***********************************************************************************/
               break;
             case 'C':   //Compute Pay
/***********************************************************************************
***  ADD your code here to compute the pay for all employees the employeeList.
***********************************************************************************/
                for (int i = 0;i<employeeList.size();i++) {
                    Employee person = employeeList.get(i);
                    person.computePay();
                }
                System.out.println("pay computed");
                break;
             case 'D':   //Search for Employee
               System.out.print("Please enter an employeeID to search:\n");
               inputInfo = stdin.readLine().trim();
/***********************************************************************************
***  ADD your code here to search a given employeeID. If found, set "found" true,
***  and set "found" false otherwise.
***********************************************************************************/
                operation = false;
                for (int i = 0;i<employeeList.size();i++) {
                    Employee person = employeeList.get(i);
                    if (person.getEmployeeId().equals(inputInfo)){
                        operation=true;
                        break;
                    }
                    operation=false;
                }
                if (operation == true)
                 System.out.print("Employee found\n");
                else
                 System.out.print("Employee not found\n");
               break;
             case 'L':   //List Employees
/***********************************************************************************
***  ADD your code here to print out all employee objects. If there is no employee,
***  print "no employee\n"
***********************************************************************************/
                if (employeeList.size()==0){
                    System.out.println("no employee");
                }else {
                    for (int i = 0;i<employeeList.size();i++) {
                        Employee person = employeeList.get(i);
                        System.out.println(person);
                    }
                }
               break;
             case 'Q':   //Quit
               break;
             case '?':   //Display Menu
               printMenu();
               break;
             default:
               System.out.print("Unknown action\n");
               break;
            }
         }
        else
         {
           System.out.print("Unknown action\n");
          }
        } while (input1 != 'Q'); // stop the loop when Q is read
      }
     catch (IOException exception)
      {
        System.out.println("IO Exception");
      }
  }

  /** The method printMenu displays the menu to a user **/
  public static void printMenu()
   {
     System.out.print("Choice\t\tAction\n" +
                      "------\t\t------\n" +
                      "A\t\tAdd Employee\n" +
                      "C\t\tCompute Pay\n" +
                      "D\t\tSearch for Employee\n" +
                      "L\t\tList Employees\n" +
                      "Q\t\tQuit\n" +
                      "?\t\tDisplay Help\n\n");
  }
}


