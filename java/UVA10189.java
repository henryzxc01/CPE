//https://zerojudge.tw/ShowProblem?problemid=e605
import java.util.Scanner;

class UVA10189{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		
		int cases=sc.nextInt();
		for(int i=0;i<cases;i++){
			String st1=sc.next();
			String st2=sc.next();
			
			//binary to integer
			int st1N=0;
			int st2N=0;
			for(int j=st1.length()-1;j>=0;j--){
				if(st1.charAt(j)!='0') st1N=st1N+(int)Math.pow(2,st1.length()-1-j);
			}
			for(int j=st2.length()-1;j>=0;j--){
				if(st2.charAt(j)!='0') st2N=st2N+(int)Math.pow(2,st2.length()-1-j);
			}
			
			//gcd
			while(st2N!=0){
				int temp=st2N;
				st2N=st1N%st2N;
				st1N=temp;
			}
			//output
			if(st2N==0 && st1N!=1)System.out.println("Pair #"+(i+1)+": All you need is love!");
			else System.out.println("Pair #"+(i+1)+": Love is not all you need!");
		}
	}
}
