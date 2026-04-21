//https://zerojudge.tw/ShowProblem?problemid=c044
import java.util.*;

public class UVA10008 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int c[] = new int[300];
		int len = 0;
		int n = Integer.parseInt(sc.nextLine());
		
		while (n-- > 0) {
			String s = sc.nextLine();
			len += s.length();
			s = s.toUpperCase();
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')
					c[(int)s.charAt(i)]++;
			}
		}
		
		while (len-- > 1) {
			for (int i = 'A'; i <= 'Z'; i++)
				if (c[i] == len)
					System.out.println((char)i + " " + len);
		}
	}
}
