import java.util.*;
import java.io.*;

public class UVA11385 {
	public static ArrayList<Integer> fib;

	public static Scanner sc;
	public static int n;
	public static int[] fibI;
	public static String cipher;
	public static ArrayList<Character> msg;

	public static void genFib() {
		fib = new ArrayList<Integer>();
		fib.add(1);
		fib.add(2);
		int n=2;
		while(true) {
			int f=fib.get(n-1)+fib.get(n-2);
			if(f<0) break;
			fib.add(f);
			n++;
		}
	}

	public static void readInput() {
		n = sc.nextInt();
		fibI = new int[n];
		for(int i=0;i<n;i++)
			fibI[i]=sc.nextInt();
		sc.nextLine();
		cipher = sc.nextLine().replaceAll("[^A-Z]","");
	}

	public static void output() {
		String ans="";
		for(Character c : msg)
			ans+=c;
		System.out.println(ans);
	}

	public static void main(String[] args) {
		genFib();
		sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T-->0) {
			readInput();
			msg = new ArrayList<Character>();
			for(int i=0;i<n;i++) {
				int index=Collections.binarySearch(fib,fibI[i]);
				//System.out.println(i+"->"+index);
				while(msg.size()<=index) msg.add(' ');
				msg.set(index,cipher.charAt(i));
			}
			output();
		}
	}
}
