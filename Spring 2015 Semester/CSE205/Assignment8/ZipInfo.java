// Assignment #: 8
//         Name: Joel Christiansen
//    StudentID: 1207242943
//      Lecture: TTh 4:30
//  Arizona State University CSE205 Spring 2015
//  Description: ZipInfo represents a combination of city, state, and zip code

import java.io.*;

public class ZipInfo implements Serializable
 {
  private String city, state;
  private int zipcode;
  private static final long serialVersionUID = 1L;

  //Constructor to initialize parameter values
  public ZipInfo(String city1, String state1, int zip1)
     {
      zipcode = zip1;
      city = city1;
      state = state1;
     }

    //Accessor method for city
    public String getCity()
     {
         return city;
     }

    //Accessor method for state
    public String getState()
     {
         return state;
     }
 
    //Accesor method for zipcode
    public int getZipcode()
     {
         return zipcode;
     }

    //The toString method return a string containing
    //the city, state, and zip code
    public String toString()
     {
      return (city + " in " + state + " with zipcode of " + zipcode + "\n");
     }

} //end of ZipInfo class
