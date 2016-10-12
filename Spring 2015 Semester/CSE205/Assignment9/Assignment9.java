import java.io.*;

public class Assignment9 {

    public static int[] numbers = new int[100];
    public static BufferedReader console = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) {
        int i = 0;
        int j = 0;
        do {
            try {
                j = Integer.parseInt(console.readLine());
                numbers[i] = j;
                i++;
            }
            catch (IOException e) {

            }
            

        } while (i<100 && j!=0);
        System.out.println("The minimum number is " + findMin(numbers, 0, numbers.length));
        System.out.println("The sum of the numbers at even indexes is " + computeSumAtEven(numbers, 0, numbers.length));
        System.out.println("The total count of odd numbers is " + countOdd(numbers, 0, numbers.length));
        System.out.println("The total count of numbers that are same as the first is " + countSameAsFirst(numbers, 1, numbers.length, numbers[0]));

    }

    public static int findMin(int[] numbers, int startIndex, int endIndex) {
        if (numbers[startIndex] == 0 || startIndex==endIndex-1) {
            return numbers[startIndex];
        }
        int minRest = findMin(numbers, startIndex+1, endIndex);
        return numbers[startIndex]<minRest?numbers[startIndex]:minRest;
    }

    public static int computeSumAtEven(int[] numbers, int startIndex, int endIndex) {
        if (startIndex+2>=endIndex-1) {
            return numbers[startIndex];
        }
        return numbers[startIndex] + computeSumAtEven(numbers, startIndex+2, endIndex);
    }

    public static int countOdd(int[] numbers, int startIndex, int endIndex) {
        if (startIndex==endIndex-1) {
            if (numbers[startIndex]%2==0) {
                return 0;
            }
            return 1;
        }
        return numbers[startIndex]%2==0?countOdd(numbers, startIndex+1, endIndex):1+countOdd(numbers, startIndex+1, endIndex);
    }

    public static int countSameAsFirst(int[] numbers, int startIndex, int endIndex, int firstNumber) {
        if (startIndex==endIndex-1) {
            if (numbers[startIndex] == firstNumber) {
                return 1;
            }
            return 0;
        }
        if (numbers[startIndex] == firstNumber) {
            return 1 + countSameAsFirst(numbers, startIndex+1, endIndex, firstNumber);
        }
        return countSameAsFirst(numbers, startIndex+1, endIndex, firstNumber);
    }
}