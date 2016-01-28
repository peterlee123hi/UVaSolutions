import java.util.*;
import java.io.*;

public class UVA10252 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextLine()) {
			char[] a = sc.nextLine().toCharArray();
			char[] b = sc.nextLine().toCharArray();
			Arrays.sort(a);
			Arrays.sort(b);
			String ans = "";
			int i = 0, j = 0;
			while(i<a.length&&j<b.length) {
				if(a[i]==b[j]) {
					ans+=a[i];
					i++; j++;
				} else if(a[i]<b[j]) i++;
				else j++;
			}
			System.out.println(ans);
		}
	}
}
