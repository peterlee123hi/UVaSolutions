import java.util.*;
import java.io.*;
import java.math.*;

public class UVA713 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T-->0) {
			StringBuilder s1 = new StringBuilder(sc.next());
			StringBuilder s2 = new StringBuilder(sc.next());
			BigInteger n1 = new BigInteger(s1.reverse().toString());
			BigInteger n2 = new BigInteger(s2.reverse().toString());
			StringBuilder ans = (new StringBuilder(n1.add(n2).toString())).reverse();
			System.out.println(new BigInteger(ans.toString()));
		}
	}
}
