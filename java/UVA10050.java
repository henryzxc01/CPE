//https://zerojudge.tw/ShowProblem?problemid=e579
import java.util.Scanner;

public class UVA10050 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCaseCount = sc.nextInt();
        for (int testCase=0;testCase<testCaseCount;testCase++) {
            int N = sc.nextInt();
            int P = sc.nextInt();
            int [] h=new int [P];
            for (int i=0;i<P;i++) {
                h[i] = sc.nextInt();
            }
            
            // 0 = sat, 1 = sun, ... 6 = friday
            int daysCount=0;
            for (int i=1;i<=N;i++) {
                if (i%7!=6 && i%7!=0) {
                    for (int i2=0;i2<h.length;i2++) {
                        if (i%h[i2]==0) {
                            daysCount++;
                            break;
                        }
                    }
                } 
            }
            System.out.println(daysCount);
        }
    }
}
