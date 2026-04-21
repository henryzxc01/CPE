//https://zerojudge.tw/ShowProblem?problemid=c007
import java.util.*;

public class UVA272 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		boolean first = true;

		while(sc.hasNext()) {
			String s = sc.nextLine();
			for (int index = 0; index < s.length(); index++){
				if(s.charAt(index)=='"'){
					if(first){
						System.out.print("``");
						first = false;
					}
					else{
						System.out.print("''");
						first = true;
					}
				}
				else{
					System.out.print(s.charAt(index));
				}
			}
			System.out.println();
		}
	}
}
