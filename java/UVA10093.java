//https://vjudge.net/problem/UVA-10093
import java.util.*;
 
public class UVA_10093{
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    while(sc.hasNextLine())
    {
    	String str = sc.nextLine();
    	int sum = 0;
    	int max = 1;
    	int r = 0;
    	for(int i =0; i < str.length(); i++)
    	{
    		char c = str.charAt(i);
    		if(c >= '0' && c <= '9')
    			r =  c - '0';
    		else if(c >= 'A' && c <= 'Z')
    			r = c - 'A' + 10;
    		else if(c >= 'a' && c <= 'z')
    			r = c - 'a' + 36;
    		sum += r;
    		if(r > max)
    			max = r;
    	}
    	for(int i = max; i <= 62; i++)
    	{
    		if(sum % i == 0)
    		{
    			System.out.println(i+1);
    			break;
    		}
    		else if(i == 62)
    			System.out.println("such number is impossible!");
    	}	
    }
  }
}
