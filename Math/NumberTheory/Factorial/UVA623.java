import java.util.*;
import java.math.*;
import java.io.*;

public class UVA623 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextBigInteger()) {
			BigInteger n = sc.nextBigInteger();
			System.out.println(n+"!");
			System.out.println(fact(n));
		}
	}

	public static BigInteger fact(BigInteger n) {
		BigInteger ans = BigInteger.ONE;
		while(n.compareTo(BigInteger.ZERO)>0) {
			ans=ans.multiply(n);
			n=n.subtract(BigInteger.ONE);
		} return ans;
	}
}
