//https://zerojudge.tw/ShowProblem?problemid=d492
import java.util.*;

public class UVA10226 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		int T = Integer.valueOf(sc.nextLine());
		sc.nextLine();
		
		for (int t = 0; t < T; t++) {
			float total = 0.0f;
			HashMap<String, Integer> hm = new HashMap<String, Integer>();
			ArrayList<String> tree = new ArrayList<String>();
			String input;
			
			while (sc.hasNext()) {
				input = sc.nextLine();
				if (input.length() == 0)
					break;
				
				if (!hm.containsKey(input)) {
					hm.put(input, 1);
					tree.add(input);
				}
				else
					hm.put(input, hm.get(input) + 1);
				
				total++;
			}
			
			Collections.sort(tree);

			for (String s: tree)
				System.out.printf("%s %.4f\n", s, (float)hm.get(s)/total * 100);

			if (t != T - 1)
				System.out.println();
		}
	}
}
