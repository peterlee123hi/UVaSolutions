import java.util.*;
import java.math.*;
import java.io.*;

public class UVA324 {
	static BigInteger n,m;
	static int[] d = new int[10];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextBigInteger()) {
			for(int i=0;i<10;i++) d[i]=0;
			n = sc.nextBigInteger();
			if(n.compareTo(BigInteger.ZERO)==0) break;
			m = new BigInteger(n.toString());
			n = fact(n);
			String s=n.toString();
			for(int i=0;i<s.length();i++) d[s.charAt(i)-'0']++;
			printAns();
		}
	}

	public static void printAns() {
		System.out.println(m+"! --");
		for(int i=0;i<5;i++)
			System.out.printf("%s   (%d)%5d",(i==0)?"":" ",i,d[i]);
		System.out.println();
		for(int i=5;i<10;i++)
			System.out.printf("%s   (%d)%5d",(i==5)?"":" ",i,d[i]);
		System.out.println();
	}

	public static BigInteger fact(BigInteger n) {
		BigInteger ans = BigInteger.ONE;
		while(n.compareTo(BigInteger.ZERO)>0) {
			ans=ans.multiply(n);
			n=n.subtract(BigInteger.ONE);
		} return ans;
	}
}
