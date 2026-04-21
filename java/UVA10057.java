//https://zerojudge.tw/ShowProblem?problemid=e606
import java.util.*;

public class UVA10057 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		int n, mid, mid2, n_mid, count;
		while (sc.hasNext()) {
			n = sc.nextInt();
			int[] num = new int[n];
			for (int i = 0; i < n; i++) 
				num[i] = sc.nextInt();
			
			Arrays.sort(num);
			
			mid = num[(n - 1)/2];
			mid2 = num[n/2];

			count = 0;
			for (int i = 0; i < n; i++) {
				if (num[i] == mid || num[i] == mid2) {
					count++;
				}
			}
			n_mid = mid2 - mid + 1;
			
			System.out.println(mid + " " + count + " " + n_mid);	
		}
	}
}
