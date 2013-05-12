import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static BigInteger factorial(int n) {
        if (n <= 1) {
            return(new BigInteger("1"));
        } else {
            BigInteger bigN = new BigInteger(String.valueOf(n));
            return(bigN.multiply(factorial(n - 1)));
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while(scan.hasNextBigInteger()) {
            int input = scan.nextInt();
            BigInteger fact = factorial(input);
            System.out.format("%d!\n%d\n",input,fact);
        }
    }
}

