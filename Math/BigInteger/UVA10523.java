import java.util.*;
import java.math.*;
import java.io.*;

public class UVA10523 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextBigInteger()) {
			int n=sc.nextInt(),a=sc.nextInt();
			BigInteger ans = BigInteger.ZERO;
			while(n>0) {
				BigInteger b = BI(n).multiply(BI(a).pow(n));
				ans=ans.add(b);
				n--;
			} System.out.println(ans);
		}
	}

	public static BigInteger BI(int n) {
		return new BigInteger(n+"");
	}
}
