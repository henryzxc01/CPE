//https://zerojudge.tw/ShowProblem?problemid=c014
import java.util.*;

public class UVA10035 {

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            int times = 0;
            int carry = 0;
            int A = input.nextInt();
            int B = input.nextInt();

            if (A == 0 && B == 0) {
                break;
            }

            while (A != 0 || B != 0) {
                if (A % 10 + B % 10 + carry >= 10) {
                    times++;
                    carry = 1;
                } else {
                    carry = 0;
                }

                A /= 10;
                B /= 10;
            }

            if (times == 0) {
                System.out.println("No carry operation."); 
            }else {
                if (times == 1) {
                    System.out.println("1 carry operation."); 
                }else {
                    System.out.println(times + " carry operations.");
                }
            }
        }
    }
}
