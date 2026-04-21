//https://zerojudge.tw/ShowProblem?problemid=e545
import java.util.*;

public class UVA10019 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		String BM;
		int N = sc.nextInt();
		while (N-- > 0) {
			int  Bin = 0, Hex = 0;
			int M = sc.nextInt();
			BM = Integer.toBinaryString(M);
			
			for (int i = 0; i < BM.length(); i++)
				if (BM.charAt(i) == '1')
					Bin++;
			
			while (true) {
				int t = M % 10;
				while (true) {
					if (t % 2 == 1)
						Hex++;
					
					if (t == 1)
						break;
					t /= 2;
				}
    			
				if (M < 10)
					break; 
				M /= 10;
			}
			System.out.println(Bin + " " + Hex);
		}
	}
}
