import java.util.*;
import java.io.*;

public class UVA494 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextLine()) {
			Scanner s = new Scanner(sc.nextLine().replaceAll("[^a-zA-Z]"," "));
			int count = 0;
			while(s.hasNext()) {
				s.next();
				count++;
			} System.out.println(count);
		}
	}
}
