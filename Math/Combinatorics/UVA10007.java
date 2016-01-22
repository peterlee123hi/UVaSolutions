import java.util.*;
import java.math.*;
import java.io.*;

public class UVA10007 {
	static BigInteger[] c = new BigInteger[320];

	public static void generateCat() {
		c[0]=BigInteger.ONE;
		BigInteger two=BigInteger.ONE.add(BigInteger.ONE);
		for(int i = 1; i < 320; i++) {
			BigInteger n = BI(i);
			c[i]=two.multiply(two.multiply(n).subtract(BigInteger.ONE))
					.multiply(c[i-1])
					.divide(n.add(BigInteger.ONE));
		}
	}

	public static BigInteger fact(BigInteger n) {
		BigInteger ans = BigInteger.ONE;
		while(n.compareTo(BigInteger.ZERO)>0) {
			ans = ans.multiply(n);
			n = n.subtract(BigInteger.ONE);
		} return ans;
	}

	public static BigInteger BI(int n) { return new BigInteger(n+""); }

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		generateCat();
		while(n!=0) {
			System.out.println(c[n].multiply(fact(BI(n))));
			n = sc.nextInt();
		} System.exit(0);
	}
}
