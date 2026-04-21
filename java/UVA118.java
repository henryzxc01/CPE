//https://zerojudge.tw/ShowProblem?problemid=c082
import java.util.*;

public class UVA118 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String nwse = "NWSE";
		
		String s[] = sc.nextLine().split(" ");
		int x = Integer.valueOf(s[0]);
		int y = Integer.valueOf(s[1]);
		boolean scent[][] = new boolean[x+1][y+1];
		
		while (sc.hasNext()) {
			boolean lost = false;
			String s2[] = sc.nextLine().split(" ");
			int rx = Integer.valueOf(s2[0]);
			int ry = Integer.valueOf(s2[1]);
			int dir = Integer.valueOf(nwse.indexOf(s2[2]));
			
			String ins = sc.nextLine();
			for (int i = 0; i < ins.length() && !lost; i++) {
				switch(ins.charAt(i)) {
					case 'R':
						dir = (dir-1 < 0) ? 3 : (dir-1);
						break;
					case 'L':
						dir = (dir+1 > 3) ? 0 : (dir+1);
						break;
					case 'F':
						if (dir == 0) { //N
							if ((ry+1 > y) && !scent[rx][ry]) {
								scent[rx][ry] = true;
								System.out.println(rx + " " + ry + " " + nwse.charAt(dir) + " LOST");
								lost = true;
							}
							else
								ry = (ry == y) ? ry : ry+1;
						}
						else if (dir == 1) { //W
							if ((rx == 0) && !scent[rx][ry]) {
								scent[rx][ry] = true;
								System.out.println(rx + " " + ry + " " + nwse.charAt(dir) + " LOST");
								lost = true;
							}
							else
								rx = (rx == 0) ? rx : rx-1;
						}
						else if (dir == 2) { //S
							if ((ry == 0) && !scent[rx][ry]) {
								scent[rx][ry] = true;
								System.out.println(rx + " " + ry + " " + nwse.charAt(dir) + " LOST");
								lost = true;
							}
							else
								ry = (ry == 0) ? ry : ry-1;
						}
						else //E
							if ((rx+1 > x) && !scent[rx][ry]) {
								scent[rx][ry] = true;
								System.out.println(rx + " " + ry + " " + nwse.charAt(dir) + " LOST");
								lost = true;
							}
							else
								rx = (rx == x) ? rx : rx+1;
						break;
				}
				if (i == ins.length()-1)
					System.out.println(rx + " " + ry + " " + nwse.charAt(dir));
			}
		}
	}
}