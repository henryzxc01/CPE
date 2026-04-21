//https://zerojudge.tw/ShowProblem?problemid=a737
import java.util.*;

public class UVA10041 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while (T-- > 0) {
			int r = sc.nextInt();
			int arr[] = new int[r];
			for (int i = 0; i < r; i++) 
				arr[i] = sc.nextInt();
			
			Arrays.sort(arr);
			int sum = 0;
            for (int i = 0; i < arr.length; i++) {
                sum += Math.abs(arr[r/2] - arr[i]);
            }
			System.out.println(sum);
		}
	}
}