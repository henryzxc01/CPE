//https://zerojudge.tw/ShowProblem?problemid=d387
import java.util.*;

public class UVA10235 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		boolean prime[] = new boolean[1000010];
		Arrays.fill(prime, true);
		
		prime[1] = false;
		for (int i = 2; i <= 1000000; i++) {
			if (prime[i]) {
				for (int j = i; (long)i*j <= 1000000; j++) 
					prime[i * j] = false;
			}
		}
		
		while (sc.hasNext()) {
			int N = sc.nextInt();
			System.out.print(N + " ");
			int oN = N;
			if (prime[N]) {
				int rN = 0;
				while (N > 0) {
					rN *= 10;
					rN += N%10;
					N /= 10;
				}

				if (oN == rN)
					System.out.println("is prime.");
				else
					System.out.println(prime[rN] ? "is emirp." : "is prime.");
			}
			else
				System.out.println("is not prime.");
		}
	}
}
