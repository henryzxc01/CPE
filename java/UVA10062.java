//https://zerojudge.tw/ShowProblem?problemid=c012
import java.util.*;

public class UVA10062 {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int newline = 0;
        while (sc.hasNext()) {
            String str = sc.nextLine();
            if (newline++ != 0) {
                System.out.println();
            }
            int[] freq = new int[127];
            int max = 0;
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                if (++freq[c] > max) {
                    max = freq[c];
                }
            }
            for (int i = 1; i <= max; i++) {
                for (int j = 126; j >= 0; j--) {
                    if (freq[j] == i) {
                        System.out.printf("%d %d\n", j, i);
                    }
                }
            }
        }
    }
};
