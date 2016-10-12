// Assignment #: 10
//         Name: Joel Christiansen
//    StudentID: 1207242942
//  Lab Lecture: TTH 4:30
//  Arizona State University CSE205
//  Description: The Assignment 10 class displays a menu of choices to a user
//               and performs the chosen task. It will keep asking a user to
//               enter the next choice until the choice of 'Q' (Quit) is
//               entered.

import java.io.*;

public class Assignment10
{
   public static void main(String[] args)
   {
      char input1;
       String inputInfo = new String();
       int operation2;
       String line = new String();

       //create a linked list to be used in this method.
       LinkedList list1 = new LinkedList();

       try
        {
         // print out the menu
         printMenu();

         // create a BufferedReader object to read input from a keyboard
         InputStreamReader isr = new InputStreamReader (System.in);
         BufferedReader stdin = new BufferedReader (isr);

         do
          {
           System.out.print("What action would you like to perform?\n");
           line = stdin.readLine().trim();  //read a line
           input1 = line.charAt(0);
           input1 = Character.toUpperCase(input1);

           if (line.length() == 1)   //check if a user entered only one character
            {
             switch (input1)
              {
               case 'A':   //Add String Once
                 System.out.print("Please enter a string to add:\n");
                 String str1 = stdin.readLine().trim();
                 list1.addElement(str1);
                 break;
               case 'B':   //Add String Multiple Times
                 System.out.print("Please enter a string to add:\n");
                 String str2 = stdin.readLine().trim();
                 System.out.print("Please enter a number of times to add:\n");
                 String times = stdin.readLine().trim();
                 int howMany = Integer.parseInt(times);
                 list1.addElements(str2, howMany);
                 break;
               case 'C':   //Check if the list is empty
                 if (list1.isEmpty())
                  System.out.print("The list is empty.\n");
                 else
                  System.out.print("The list contains some element(s).\n");
                 break;
               case 'D':   //Duplicate Each element in the linked list
                 list1.duplicateEach();
                 System.out.print("Element(s) duplicated if any.\n");
                 break;
               case 'E':   //Search for a String at an Index
                 System.out.print("Please enter an index to search:\n");
                 inputInfo = stdin.readLine().trim();
                 int searchIndex = Integer.parseInt(inputInfo);
                 try
                  {
                    System.out.print("String at the index " + searchIndex 
                         + " is " + list1.getElement(searchIndex) + "\n");
                  }
                 catch(IndexOutOfBoundsException ex)
                  {
                    System.out.print("The index is out of bounds\n");
                  }
                 break;
               case 'L':   //List Strings
                 System.out.print(list1.toString());
                 break;
               case 'Q':   //Quit
                 break;
               case 'S':  //Search and Remove
                 System.out.print("Please enter a string to be searched and removed:\n");
                 inputInfo = stdin.readLine().trim();
                 list1.searchAndRemove(inputInfo);
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
          } while (input1 != 'Q' || line.length() != 1);
        }
       catch (IOException exception)
        {
          System.out.print("IO Exception\n");
        }
    }

    /** The method printMenu displays the menu to a user **/
    public static void printMenu()
     {
       System.out.print("Choice\t\tAction\n" +
                        "------\t\t------\n" +
                        "A\t\tAdd String Once\n" +
                        "B\t\tAdd String Multiple Times\n" +
                        "C\t\tCheck if Empty\n" +
                        "D\t\tDuplicate Strings\n" +
                        "E\t\tSearch for String\n" +
                        "L\t\tList Strings\n" +
                        "Q\t\tQuit\n" +
                        "S\t\tSearch and Remove\n" +
                        "?\t\tDisplay Help\n\n");
    } //end of printMenu()
}