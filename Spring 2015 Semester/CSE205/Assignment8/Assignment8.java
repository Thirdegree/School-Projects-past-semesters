// Assignment #: 8
//         Name: Joel Christiansen
//    StudentID: 1207242943
//      Lecture: TTh 4:30
//  Arizona State University CSE205 Spring 2015
//  Description: The Assignment 8 class displays a menu of choices to a user
//               and performs the chosen task. It will keep asking a user to
//               enter the next choice until the choice of 'Q' (Quit) is
//               entered. 

import java.io.*;
import java.util.*;

public class Assignment8
 {
  public static void main (String[] args)
   {
     char input1;
     String city, state, zipStr;
     int zipcode;
     boolean operation = false;
     int operation2 = 0;
     String line;
     String filename;

     // create a PostOffice object. This is used throughout this class.
     PostOffice office1 = new PostOffice();

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

         if (line.length() == 1)          //check if a user entered only one character
          {
           switch (input1)
            {
             case 'A':   //Add Zipcode
               try 
                {
                 System.out.print("Please enter a city to add:\n");
                 city = stdin.readLine().trim();
                 System.out.print("Please enter its state to add:\n");
                 state = stdin.readLine().trim();
                 System.out.print("Please enter its zipcode to add:\n");
                 zipStr = stdin.readLine().trim();
                 zipcode = Integer.parseInt(zipStr);

                 operation = office1.addZipInfo(city, state, zipcode);
                 if (operation == true)
                  System.out.print("zipcode added\n");
                 else
                  System.out.print("zipcode exists\n");
                }
/************************************************************************************
***  Complete the follwing catch statement
***********************************************************************************/
               catch( NumberFormatException e  )
                {
                  System.out.print("Please enter an integer for zipcode. Zipcode not added\n");
                }
               break;
             case 'D':  //Search by Zipcode
              try
               {
                 System.out.print("Please enter zipcode to search:\n");
                 zipStr = stdin.readLine().trim();
                 zipcode = Integer.parseInt(zipStr);
                 operation2=office1.zipcodeExists(zipcode);

                 if (operation2 > -1)
                   System.out.print("zipcode found\n");
                 else
                   System.out.print("zipcode not found\n");
                }
/************************************************************************************
***  Complete the follwing catch statement
***********************************************************************************/
               catch(NumberFormatException e)
                {
                  System.out.print("Please enter an integer for zipcode. Zipcode not found\n");
                }
               break;
             case 'E':  //Search by City and State
                System.out.print("Please enter a city to search:\n");
                city = stdin.readLine().trim();
                System.out.print("Please enter a state to search:\n");
                state = stdin.readLine().trim();
                operation2=office1.cityStateExists(city, state);
                    
                if (operation2 > -1)
                    System.out.print("city and state found\n");
                else
                    System.out.print("city and state not found\n");
                break;
             case 'L':   //List Zipcodes
               System.out.print(office1.listZipCode());
               break;
             case 'O':  // Sort by Zipcode
               office1.sortByZipcode();
               System.out.print("sorted by zipcode\n");
               break;
             case 'P':  // Sort by States and Cities
               office1.sortByCityState();
               System.out.print("sorted by states and cities\n");
               break;
             case 'Q':   //Quit
               break;
             case 'R':  //Remove by Zipcode
              try
               {
                 System.out.print("Please enter zipcode to remove:\n");
                 zipStr = stdin.readLine().trim();
                 zipcode = Integer.parseInt(zipStr);
                 operation=office1.removeZipcode(zipcode);

                 if (operation == true)
                    System.out.print("zipcode removed\n");
                 else
                    System.out.print("zipcode not found\n");
                }
/************************************************************************************
***  Complete the follwing catch statement
***********************************************************************************/
               catch( NumberFormatException e  )
                {
                  System.out.print("Please enter an integer for zipcode. Zipcode not removed\n");
                }
               break;
                case 'S':  //Remove by State and City
                    System.out.print("Please enter a city to remove:\n");
                    city = stdin.readLine().trim();
                    System.out.print("Please enter a state to remove:\n");
                    state = stdin.readLine().trim();
                    operation=office1.removeCityState(city, state);

                    if (operation == true)
                        System.out.print("city and state removed\n");
                    else
                        System.out.print("city and state not found\n");
                    break;
             case 'T':  //Close PostOffice
               office1.closePostOffice();
               System.out.print("post office closed\n");
               break;
             case 'U':  //Write Text to a File
               System.out.print("Please enter a file name to write:\n");
               filename = stdin.readLine().trim();
/************************************************************************************
***  ADD your code to write a text (string) to the specified file. Catch exceptions.
************************************************************************************/
               PrintWriter out = null;
               try {
                 out = new PrintWriter(filename);
                 System.out.print("Please enter a string to write in the file:\n");
                 String output = stdin.readLine().trim() + "\n";
                 out.print(output);
                 System.out.print(filename +" was written\n");
               }
               catch (IOException e) {
                System.out.print("File does not exist and cannot be created.");
               }
               finally {
                out.close();

               }
               break;
             case 'V':  //Read Text from a File
               System.out.print("Please enter a file name to read:\n");
               filename = stdin.readLine().trim();
/************************************************************************************
***  ADD your code to read a text (string) from the specified file. Catch exceptions.
************************************************************************************/
                String in = "";
                Scanner reader = null;
                try {
                  reader = new Scanner(new FileReader(filename));
                  System.out.print(filename + " was read\n");
                  System.out.print("The first line of the file is:\n"+reader.nextLine()+ "\n");
                }
                catch (IOException e) {
                  System.out.print(filename + " was not found\n");
                }
                finally {
                  if (reader!=null)
                    reader.close();
                }
               break;
             case 'W':  //Serialize PostOffice to a File
               System.out.print("Please enter a file name to write:\n");
               filename = stdin.readLine().trim();
/************************************************************************************
***  ADD your code to write the post office bject to the specified file. Catch exceptions.
************************************************************************************/
                FileOutputStream fileOut = null;
                ObjectOutputStream objOut = null;
                try {
                  fileOut = new FileOutputStream(filename);
                  objOut = new ObjectOutputStream(fileOut);
                  objOut.writeObject(office1);
                  System.out.print(filename + " was written\n");
                }
                catch (IOException e) {

                }
                finally {
                  if (objOut!=null)
                    objOut.close();
                  if (fileOut!=null)
                    fileOut.close();
                }
               break;
              case 'X':  //Deserialize PostOffice from a File
               System.out.print("Please enter a file name to read:\n");
               filename = stdin.readLine().trim();
/************************************************************************************
***  ADD your code to read a post office object from the specified file. Catch exceptions.
***********************************************************************************/
               FileInputStream filein = null;
               ObjectInputStream objIn = null;
               try {
                 filein = new FileInputStream(filename);
                 objIn = new ObjectInputStream(filein);
                 office1 = (PostOffice) objIn.readObject();
                 System.out.print(filename + " was read\n");
               }
               catch (IOException e) {
                System.out.print(filename + " was not found\n");
               }
               catch (ClassNotFoundException c) {

               }
               finally {
                if (filein!=null)
                  filein.close();
                if (objIn!=null)
                  objIn.close();
               }
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
                      "A\t\tAdd Zipcode\n" +
                      "D\t\tSearch for Zipcode\n" +
                      "E\t\tSearch for City and State\n" +
                      "L\t\tList Zipcode\n" +
                      "O\t\tSort by Zipcode\n" +
                      "P\t\tSort by City and State\n" +
                      "Q\t\tQuit\n" +
                      "R\t\tRemove by Zipcode\n" +
                      "S\t\tRemove by City and State\n" +
                      "T\t\tClose PostOffice\n" +
                      "U\t\tWrite Text to File\n" +
                      "V\t\tRead Text from File\n" +
                      "W\t\tSerialize PostOffice to File\n" +
                      "X\t\tDeserialize PostOffice from File\n" +
                      "?\t\tDisplay Help\n\n");
  }
} // end of Assignment8 class

