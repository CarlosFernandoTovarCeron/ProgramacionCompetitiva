import java.math.BigInteger;
import java.util.Scanner;
public class Main {
	
	static BigInteger[][] dp = new BigInteger[10005][10005] ;
	static String a , b;
	public static BigInteger c(int i, int j){
	    if(j==0)
	        return new BigInteger("1");
	        
	    if(i==0)
	        return new BigInteger("0");
	        
	    if(!dp[i][j].equals(new BigInteger("-1")))
	        return dp[i][j];
	
	    if(a.charAt(i) == b.charAt(j)){
	        BigInteger iz = c(i-1, j);
	        dp[i-1][j] = iz;
	        BigInteger der = c(i-1, j-1);
	        dp[i-1][j-1] = der;
	        dp[i][j] = iz.add(der);
	        return iz.add(der);
	    }else{
	        BigInteger nodo = c(i-1, j);
	        dp[i-1][j] = nodo;
	        dp[i][j] = nodo;
	        return nodo;
	    }
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();

		for ( int n = 0 ; n < N ; n ++ ) {
			
			a = scanner.next();
			b = scanner.next();
			for(int i=0; i<=a.length(); i++){
				for(int j=0; j<=b.length(); j++){
					dp[i][j] = new BigInteger("-1");	
				}	
			}
			a = "X" + a;
			b = "X" + b;
			System.out.println(c(a.length()-1, b.length()-1));
		}
	}
}
