import java.util.Scanner;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;


class P1 {

    private static String w = "CSE465";
    private static int n = 5;
    static MessageDigest md;
    private static int current_pass_index = 0;

    public static void main(String[] args) throws NoSuchAlgorithmException{
        md = MessageDigest.getInstance("SHA");

        //PART 1
        String[] passwords = new String[n];
        passwords[0] = generateHash(w);
        for (int i = 1; i < n; i++) {            
            passwords[i] = generateHash(passwords[i-1]);
        }
        printPasswords(passwords);
        for (int i = 0; i < n-1; i++) {
            passwords[i] = "";
        }
        printPasswords(passwords);

        //PART 2
        current_pass_index = n-2;
        while (current_pass_index+1 >=n-2) {
            System.out.format("Please input the %1$s password: ", current_pass_index+1);
            Scanner scanner = new Scanner(System.in);
            String pass = scanner.next();

            if (checkAnswer(pass, passwords, current_pass_index)) {
                passwords[current_pass_index] = pass;
                current_pass_index--;
            }
            printPasswords(passwords);
        }
    }

    public static String generateHash(String seed) {
        md.update(seed.getBytes());
        BigInteger bigInt = new BigInteger(1, md.digest());
        return bigInt.toString(32);

    }

    public static void printPasswords(String[] passwords) {
        System.out.println("--------------------------------");
        for (String pass : passwords) {
            if (!pass.equals("")){
                System.out.println(pass);
            }
        }
        System.out.println("--------------------------------");
    }
    public static Boolean checkAnswer(String answer, String[] passwords, int current_pass_index) {
        return generateHash(answer).equals(passwords[current_pass_index+1]);
    }
}