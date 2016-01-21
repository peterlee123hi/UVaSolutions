import java.util.*;
import java.math.*;
import java.io.*;

public class UVA10235 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			StringBuilder a = new StringBuilder(sc.next());
			StringBuilder b = (new StringBuilder(a)).reverse();
			boolean prime = BI(a).isProbablePrime(10);
			boolean emirp = BI(b).isProbablePrime(10);
			boolean p = a.toString().equals(b.toString());
			if(!prime) System.out.println(a + " is not prime.");
			else if(!p&&emirp) System.out.println(a + " is emirp.");
			else System.out.println(a + " is prime.");
		}
	}

	public static BigInteger BI(StringBuilder s) {
		return new BigInteger(s.toString());
	}

	public static BigInteger BI(String s) {
		return new BigInteger(s);
	}

	public static BigInteger BI(int i) {
		return new BigInteger(i+"");
	}
}
