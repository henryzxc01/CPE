//https://zerojudge.tw/ShowProblem?problemid=c039
import java.util.*;

public class UVA00100 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<String> results = new ArrayList<>();
        while (sc.hasNextInt()) {
            int i = sc.nextInt();
            int j = sc.nextInt();
            int from = Math.min(i, j);
            int to = Math.max(i, j);
            int maxCycle = 0;
            for (int n = from; n <= to; n++) {
                int count = 1;
                int temp = n;
                while (temp != 1) {
                    if (temp % 2 == 1) {
                        temp = 3 * temp + 1;
                    } else {
                        temp = temp / 2;
                    }
                    count++;
                }
                if (count > maxCycle) {
                    maxCycle = count;
                }
            }
            results.add(String.format("%d %d %d", i, j, maxCycle));
        }
        for (String res : results) {
            System.out.println(res);
        }
    }
}
