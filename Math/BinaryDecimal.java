/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
   static Scanner sc = new Scanner(System.in);
    static void solve(){
       
         int n =sc.nextInt();
		  int ans=-1;
		  int temp = n;
		  int digit=0;
		  while(temp>0){
		      digit = temp%10;
		      ans= Math.max(ans,digit);
		      temp = temp/10;
		  }
		  System.out.println(ans);
    }
    
    
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		
		int t = sc.nextInt();
		while(t-->0){
		 solve();
		}
	}
}
