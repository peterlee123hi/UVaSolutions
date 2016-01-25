import java.util.*;
import java.math.*;
import java.io.*;

public class UVA374 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextBigInteger()) {
			BigInteger b = sc.nextBigInteger();
			BigInteger p = sc.nextBigInteger();
			BigInteger m = sc.nextBigInteger();
			System.out.println(b.modPow(p,m));
		}
	}
}
