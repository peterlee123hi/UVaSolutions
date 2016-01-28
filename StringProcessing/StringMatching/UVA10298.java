import java.util.*;
import java.io.*;

public class UVA10298 {
	static String t,p;
	static int[] b;
	static int n,m,count;

	static void kmpPreprocess() {
		int i=0,j=-1;
		b[0]=-1;
		while(i<m) {
			while(j>=0&&p.charAt(i)!=p.charAt(j)) j=b[j];
			i++; j++;
			b[i]=j;
		}
	}

	static void kmpSearch() {
		int i=0,j=0;
		while(i<n) {
			while(j>=0&&t.charAt(i)!=p.charAt(j)) j=b[j];
			i++; j++;
			if(j==m) {
				count++;
				j=b[j];
			}
		}
	}

	public static void main(String[] args) throws IOException {
		//Scanner sc=new Scanner(new File("input.txt"));
		Scanner sc=new Scanner(System.in);
		p=sc.nextLine();
		while(!p.equals(".")) {
			count=-1;
			t=p+p;
			n=t.length();
			m=p.length();
			b=new int[m+1];

			kmpPreprocess();
			kmpSearch();

			System.out.println(count);

			p=sc.nextLine();
		} System.exit(0);
	}
}
