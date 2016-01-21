import java.util.*;
import java.io.*;
import java.math.*;

public class UVA10334 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt()) {
			System.out.println(fib(sc.nextInt()));
		} System.exit(0);
	}

	public static BigInteger fib(int n) {
		BigInteger prev = BigInteger.ONE;
		BigInteger cur = BigInteger.ONE;
		while(n-->=0) {
			BigInteger temp = new BigInteger(prev.toString());
			prev = new BigInteger(cur.toString());
			cur = cur.add(temp);
		} return prev;
	}
}
