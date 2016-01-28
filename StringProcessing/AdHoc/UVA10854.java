import java.util.*;
import java.io.*;

public class UVA10854 {
	public static Scanner sc;
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();

		while(T-->0) {
			System.out.println(solve());
		}
	}

	public static int solve() {
		String s;
		int result = 1;
		int count;
		while(sc.hasNextLine()) {
			s = sc.nextLine().trim();
			if(s.equals("ENDPROGRAM")) break;
			if(s.equals("IF")) {
				count = count_if();
				count += count_else();
				result *= count;
			}
		}
		return result;
	}

	public static int count_if() {
		String s;
		int result = 1;
		int count;
		while(sc.hasNextLine()) {
			s = sc.nextLine().trim();
			if(s.equals("ELSE")) break;
			if(s.equals("IF")) {
				count = count_if();
				count += count_else();
				result *= count;
			}
		}
		return result;
	}

	public static int count_else() {
		String s;
		int result = 1;
		int count;
		while(sc.hasNextLine()) {
			s = sc.nextLine().trim();
			if(s.equals("END_IF")) break;
			if(s.equals("IF")) {
				count = count_if();
				count += count_else();
				result *= count;
			}
		}
		return result;
	}
}
