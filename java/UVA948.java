import java.util.*;

public class UVA948 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int times = sc.nextInt();
		int A = 0;
		
		//建費氏數列表		
		int arr[] = new int[50];
		arr[0] = 1;
		arr[1] = 2;
		for (int i = 2; i < 43; i++)
			arr[i] = arr[i - 1] + arr[i - 2];

		while (times-- > 0) {
			A = sc.nextInt();
			StringBuilder sb = new StringBuilder(A + " = ");
			
			int i = 42;
			while (A < arr[i])
				i--;
	
			while (i >= 0) {
				if (A >= arr[i]) {
					A -= arr[i];
					sb.append("1");
				}

				else 
					sb.append("0");
				i--;
			}
			
			sb.append(" (fib)");
			System.out.println(sb.toString());
		}
	}
}