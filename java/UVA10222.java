//https://zerojudge.tw/ShowProblem?problemid=e578
import java.util.Scanner;

class UVA10222{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		String st="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"; //建立對照的表
		while(sc.hasNextLine()){
			String s=sc.nextLine().toLowerCase();
			//進行字元比較，並輸出隊的字元
			for(int i=0;i<s.length();i++){
				if(s.charAt(i)==' '){
					System.out.print(" ");
				}else{
					for(int j=0;j<st.length();j++){
						if(s.charAt(i)==st.charAt(j)){
							if(j-2>0) System.out.print(st.charAt(j-2));
							else System.out.print(s.charAt(i));
							break;
						}
					}
				}
			}
			System.out.println("");
		}
	}
}