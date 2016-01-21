import java.util.*;
import java.io.*;
import java.math.*;

public class UVA1230 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T-->0) {
			BigInteger x = sc.nextBigInteger();
			BigInteger y = sc.nextBigInteger();
			BigInteger n = sc.nextBigInteger();
			System.out.println(x.modPow(y,n));
		} sc.next();
		System.exit(0);
	}
}
