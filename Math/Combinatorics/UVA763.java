import java.util.*;
import java.io.*;
import java.math.*;

public class UVA763 {
	static BigInteger[] fib = new BigInteger[110];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		generate();
		int CN = 1;
		while(sc.hasNextBigInteger()) {
			if(CN>1) System.out.println();
			BigInteger a = sc.nextBigInteger();
			BigInteger b = sc.nextBigInteger();
			BigInteger c = biToDec(a).add(biToDec(b));
			System.out.println(decToBi(c)); CN++;
		}
	}

	public static BigInteger decToBi(BigInteger n) {
		String bi="";
		for(int i=108;i>=0;i--) {
			if(fib[i].compareTo(n)<=0) {
				bi=bi+"1";
				n=n.subtract(fib[i]);
			} else {
				bi=bi+"0";
			}
		} return new BigInteger(bi);
	}

	public static BigInteger biToDec(BigInteger n) {
		BigInteger sum = BigInteger.ZERO;
		int i=0;
		while(n.compareTo(BigInteger.ZERO)>0) {
			if(n.mod(BigInteger.TEN).compareTo(BigInteger.ONE)==0) {
				sum = sum.add(fib[i]);
			} i++; n = n.divide(BigInteger.TEN);
		} return sum;
	}

	public static void generate() {
		BigInteger prev = BigInteger.ONE,cur=prev.add(BigInteger.ONE);
		for(int i=0;i<110;i++) {
			fib[i]=prev;
			BigInteger temp = new BigInteger(prev.toString());
			prev = new BigInteger(cur.toString());
			cur = cur.add(temp);
		}
	}
}
