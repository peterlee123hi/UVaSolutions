import java.util.*;
import java.math.*;
import java.io.*;

public class UVA10814 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T-->0) {
			BigInteger p = sc.nextBigInteger();
			sc.next();
			BigInteger q = sc.nextBigInteger();
			BigInteger c = p.gcd(q);
			String num = (p.divide(c)).toString();
			String den = (q.divide(c)).toString();
			System.out.println(num + " / " + den);
		}
	}
}
