//https://zerojudge.tw/ShowProblem?problemid=a012
import java.util.Scanner;

public class UVA10055 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			System.out.println(Math.abs(A-B));
        }
    }
}
