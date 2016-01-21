import java.util.*;
import java.math.*;
import java.io.*;

public class UVA10551 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int b = sc.nextInt();
		while(b>0) {
			BigInteger p = new BigInteger(sc.next(), b);
			BigInteger m = new BigInteger(sc.next(), b);
			System.out.println(p.mod(m).toString(b));
			b = sc.nextInt();
		}
	}
}
