//https://zerojudge.tw/ShowProblem?problemid=e510
import java.util.Scanner;

class UVA10056 {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		int cases=sc.nextInt();
		int R=36;
		
		while((cases--)>0){
			int n=sc.nextInt();
			double p=sc.nextDouble();
			double q=1-p;
			int k=sc.nextInt();
			
			double a=Math.pow(q,k-1)*p;
			double r=Math.pow(q,n);
			
			if(p==0){
				System.out.println("0.0000");
			}else{
				System.out.printf("%.4f\n",a*(1-Math.pow(r,R))/(1-r));
			}
		}
	}
}
