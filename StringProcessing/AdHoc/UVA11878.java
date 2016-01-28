import java.util.*;
import java.io.*;

public class UVA11878 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int ans = 0;
		while(sc.hasNextLine()) {
			String s = sc.nextLine().trim();
			boolean add = s.indexOf("+")!=-1;
			String[] tokens = s.split("[=+-]");
			int a = Integer.parseInt(tokens[0]);
			int b = Integer.parseInt(tokens[1]);
			if(tokens[2].equals("?")) continue;
			int c = Integer.parseInt(tokens[2]);
			if(add&&a+b==c) ans++;
			else if(!add&&a-b==c) ans++; 
		} 
		System.out.println(ans);
	}
}
