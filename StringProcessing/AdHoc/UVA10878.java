import java.util.*;
import java.math.*;
import java.io.*;

public class UVA10878 {
	public static int bit(String s,int i) {
		if(i>=3) i++;
		i=9-i;
		return (s.charAt(i)=='o')?1:0;
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		String line="";
		while(sc.hasNextLine()) {
			line=sc.nextLine();
			if(line.equals("___________")) continue;
			char c=0;
			if(line.length()<10) break;
			for(int b=0;b<8;b++) {
				c|=bit(line,b)<<b;
			}
			System.out.print(c);
		}
	}
}
