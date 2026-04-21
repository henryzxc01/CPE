import java.util.Scanner;

public class UVA490 {

	public static void main(String[] args) {
		Scanner sc=new Scanner (System.in);
		char arr[][]=new char[100][100];
		int count=0,max=0;
		while(sc.hasNext()){
			String str=sc.nextLine();
			arr[count++]=str.toCharArray();
			if(str.length()>max)
				max=str.length();
		}
		for(int i=0;i<max;i++){
			for(int j=count-1;j>=0;j--){
				if(arr[j].length<=i)
					System.out.print(" ");
				else
					System.out.print(arr[j][i]);
			}
			System.out.println();
		}
		
	}
}