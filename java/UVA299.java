import java.util.Scanner;

public class UVA299{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		
		int cases=sc.nextInt();
		for(int i=0;i<cases;i++){
			int L=sc.nextInt();
			int arr[]=new int[L];
			for(int j=0;j<L;j++){
				arr[j]=sc.nextInt();
			}
			//L=4 j=0 k<3 3421 3241 3214
			//j=1 k<2 2314 2134 
			//j=2 k<1 1234
			//使用氣泡排序法去計算需交換幾次。
			int count=0;
			for(int j=0;j<L-1;j++){
				for(int k=0;k<L-j-1;k++){
					if(arr[k]>arr[k+1]){
						int temp=arr[k];
						arr[k]=arr[k+1];
						arr[k+1]=temp;
						count++;
					}
				}
			}
			
			//Output
			System.out.println("Optimal train swapping takes "+count+" swaps.");
		}
	}
} 