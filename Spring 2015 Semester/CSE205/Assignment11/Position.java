// Assignment #: 11
//         Name: Joel Christiansen
//    StudentID: 1207242942
//  Lab Lecture: TTH 4:30
//  Arizona State University CSE205
//  Description: position in a maze. do not touch

public class Position
 {
  private int row;
  private int col;
  private int face; //which direction it is going next

  //Initializes the position object using three parameters
  public Position(int row, int col, int face)
   {
     this.row = row;
     this.col = col;
     this.face = face;
   }

  //Accessor method for the row number
  public int getRow()
   {
     return row;
   }

  //Accessor method for the column number
  public int getColumn()
   {
     return col;
   }

  //Mutator method for the face (direction)
  public void setFace(int face)
   {
       this.face = face;
   }

   //Accessor method for the face
   public int getFace()
    {
        return face;
    }

   //toString() returns a string containing
   //the current row, col, and face
   public String toString()
   {
    String result =  "From row " + row + ", col " + col + ", go to ";
    switch(face){
    case 0:
        result += "Down";
        break;
    case 1:
        result += "DownLeft";
        break;
    case 2:
        result += "Left";
        break;
    case 3:
        result += "UpLeft";
        break;
    case 4:
        result += "Up";
        break;
    case 5:
        result += "UpRight";
        break;
    case 6:
        result += "Right";
        break;
    case 7:
        result += "DownRight";
        break;
    default:
        result += "Error incorrect direction";
        break;
    } //end of switch

      result += "\n";
      return result;

   } //end of toString method

 } //end of Position class
