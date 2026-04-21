//https://zerojudge.tw/ShowProblem?problemid=a741
import java.util.*;

public class UVA10101 {
	public static void calculate(long num) {
		if (num == 0) 
			return;
		
		if (num >= 10000000) {	
			calculate(num/10000000);
			System.out.print(" kuti");
			calculate(num%10000000);
		}
    
		else if (num >= 100000) {
			System.out.print(" " + num/100000 + " lakh");
			calculate(num%100000);
		}
    
		else if (num >= 1000) {
			System.out.print(" " + num/1000 + " hajar");
			calculate(num%1000);
		}
    
		else if (num >= 100) {
			System.out.print(" " + num/100 + " shata");
			calculate(num%100);
		}
    
		else if (num % 100 != 0) 
			System.out.print(" " + num);
	}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int count = 0;
		while (sc.hasNextLine()) {
			count++;
			long num = Long.parseLong(sc.nextLine());
			System.out.printf("%4d.", count);
      
			if (num == 0)
				System.out.printf(" 0");
			else
				calculate(num);
        
			System.out.println();
		}
	}
}
