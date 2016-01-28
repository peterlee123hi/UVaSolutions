import java.util.*;
import java.io.*;

public class UVA488 {
	public static int a,f;

	public static void drawWave() {
		int x=1;
		boolean increasing=true;
		for(int r=0;r<a*2-1;r++) {
			String l="";
			for(int c=0;c<x;c++) l+=x;
			System.out.println(l);
			if(x==a) increasing=false;
			if(increasing) x++;
			else x--;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T-->0) {
			a = sc.nextInt();
			f = sc.nextInt();
			for(int i=0;i<f;i++) {
				if(i>0) System.out.println();
				drawWave();
			}
			if(T>0) System.out.println();
		}
	}
}
