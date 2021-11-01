import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        printIncreasing(1,n);
    }

    public static void printIncreasing(int i,int n){
        if(i>n){
            return;
        }
        System.out.println(i);
        printIncreasing(i+1,n);
    }

}
