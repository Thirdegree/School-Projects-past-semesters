// Assignment #: 11
//         Name: Joel Christiansen
//    StudentID: 1207242942
//  Lab Lecture: TTH 4:30
//  Arizona State University CSE205
//  Description: solver, need to be made working.
import java.util.Stack;

public class MazeSolver
 {
  private char[][] originalMaze;
  private char[][] maze;
  private int mazeSize;
  private Stack<Position> stackSoln;

  //Constructor to initialize the mazeSize,
  //initializes two 2-dimensional character arrays.
  public MazeSolver(String[] mazeInfo)
   {
     mazeSize = 10;
     setupMaze(mazeInfo);
     stackSoln = new Stack<Position>();
   }

  //the setupMaze method initializes
  //two character arrays, using the input array of strings.
  public void setupMaze(String[] mazeInfo)
   {
     maze = new char[mazeSize][mazeSize];
     originalMaze = new char[mazeSize][mazeSize];
     for (int i=0; i<mazeSize; i++)
      {
      for (int j=0; j<mazeSize; j++)
       {
          originalMaze[i][j] = mazeInfo[i].charAt(j);
          maze[i][j] = originalMaze[i][j];
       }
      }
   }


  //The displayPath methods returns a string describing
  //how to go from the starting position to the goal position
  public String displayPath()
   {
     String result = "";

     while (stackSoln.isEmpty() == false)
      {
        result = stackSoln.pop() + result;
      }
     return "\nSolution Path:\n" + result+"\n\n";
   }


  //the displaySoln method returns a string containing
  //a solution of the maze
  public String displaySoln()
   {
    String result = "\nThe maze content:\n";

     for (int i = 0; i < maze.length; i++)
      {
       for (int j = 0; j < maze[i].length; j++)
        {
            result += maze[i][j];
        }
       result += "\n";
      }

     return result +"\n";
   }


  //The findSolution will return true if a solution is found,
  //false otherwise. Please see the pseudo-code of the assignment 11 statement
  public boolean findSolution()
   {
    boolean finish = false; //finish should become true when a solution is found or it is determined that there is no solution
    boolean success = false;  //success should become true when a solution is found

    //The following can be used to compute each of 8 directions
    //one can move from their current position (row,column).
    int[][] offset ={
                        {1,0},   //Down
                        {1,-1},  //DownLeft
                        {0,-1},  //Left
                        {-1,-1}, //UpLeft
                        {-1,0},  //Up
                        {-1,1},  //UpRight
                        {0,1},   //Right
                        {1,1}    //DownRight
                    };


    //Push information onto the stack indicating the first choice
    //is the position of row 0 and column 9. The last value is face, put -1 as default
    Position nextPosition = new Position(0, 9, -1);
    stackSoln.push(nextPosition);


    while (finish == false && stackSoln.isEmpty( ) == false)
     {
        //check the last position
        int currentRow = stackSoln.peek().getRow();
        int currentCol = stackSoln.peek().getColumn();
        int nextRow = 0;
        int nextCol = 0;
        int face = -1;

        System.out.println("Trying the position of row "
                           + currentRow
                           + " and column "
                           + currentCol);

  /************************************************************************
  Check the most recent position from the stack, and check which of eight adjacent positions to move from the recent position,
  in the order of 'down', 'down left', 'left', 'up left', 'up', 'up right', 'right', and 'down right'.
  This part requires another nested loop to repeat at most 8 times to check eight adjacent positions.
  If such adjacent position is not outside of the maze range,
  row and column being greater than or equals to 0 or less than or equals to 9, and being able to move into
  (it needs to contain 'x' or '<' the goal position),
  then we found a position to move to.
  As soon as we find a position to move to, save its direction to 'face' variable and get out of the loop
  ('face' can contain 0,1,2,3,4,5,6, and 7 representing the direction of
  'down', 'down left', 'left', 'up left', 'up', 'up right', 'right', and 'down right' respectively).


  row and column of adjacent positions can be written as:

  currentRow+offset[k][0]
  and
  currentCol+offset[k][1]

  where k ranges from 0 to 7.
  *************************************************************************/
        for (int i = 0;i<8;i++){

          nextRow = currentRow+offset[i][0];
          nextCol = currentCol+offset[i][1];
          //if it will be out of range of the maze
          if (nextRow > 9 || nextRow< 0 || nextCol > 9 || nextCol < 0) {
            continue;
          }
          //if the next spot is valid
          if ((maze[nextRow][nextCol]=='.') || (maze[nextRow][nextCol]=='<')){
            face = i;
            break;
          }
        }

  /************************************************************************
  If we cannot find any adjacent position to move to, then set the current position to 'O', if it was 'x'.
  Then pop the solution stack, which means not including this position in the solution path.
  ************************************************************************/
        //if there is no valid next move (dead end)
        if (face == -1) {
          stackSoln.pop();
          if (maze[currentRow][currentCol] != '>') {
            maze[currentRow][currentCol] = 'O';
          }
          continue;
        }

  /************************************************************************
  If the found adjacent position to move to is the goal position (contains '<'),
  then we found a solution path, and set 'success' to true and 'finish' to true.
  Also set the face of the current position to 'face' value obtained by the above loop.
  ************************************************************************/
        //if next move is end
        if (maze[nextRow][nextCol]=='<') {
          success = true;
          finish = true;
          stackSoln.peek().setFace(face);
        }

  /************************************************************************
  If the found adjacent position to move to is not the goal position,
  then push the object of such adjacent position onto the stack, and set the adjacent position to 'x'.
  Also set the face of the current position to 'face' value obtained by the above loop.
  ************************************************************************/
        //if next move is valid
        if (maze[nextRow][nextCol]=='.'){
          nextPosition = new Position(nextRow, nextCol, -1);
          stackSoln.peek().setFace(face);
          stackSoln.push(nextPosition);
          maze[nextRow][nextCol] = 'x';
        }

  

  /************************************************************************
  If the stack is empty at this time, then there is no other place to back track, thus the maze does not have a solution.
  Set 'success' to false and 'finish' to true.
  ************************************************************************/
        //if all paths fail
        if (stackSoln.isEmpty()) {
          success = false;
          finish = true;
        }
     } //end of while loop

     return success;

   }//end of findSolution method

}//end of the MazeSolver class

