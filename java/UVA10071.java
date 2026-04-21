//https://zerojudge.tw/ShowProblem?problemid=d226
import java.util.Scanner;

public class UVA10071{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		
		while(sc.hasNext()){
			int v=sc.nextInt();
			int t=sc.nextInt();
			
			System.out.println(v*t*2);
		}
	}
}
