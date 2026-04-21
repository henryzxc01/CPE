//https://zerojudge.tw/ShowProblem?problemid=e555
import java.util.Scanner;

class Main{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		
		while(sc.hasNext()){
			long S=sc.nextLong();
			long D=sc.nextLong();
			
			long Stemp=S;
			long count=S;
			while(Stemp<D){
				count++;
				Stemp=Stemp+count;
			}
			
			System.out.println(count);
		}
	}
}