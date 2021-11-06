import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        ArrayList<String> ans = gss(str);
        System.out.println(ans);
        
    }

    public static ArrayList<String> gss(String str) {
        if(str.length()==0){
            ArrayList<String> nulll = new ArrayList<String>();
                ArrayList<String> finall = new ArrayList<String>();
            nulll.add("");
            return nulll;
        }
        
        char ch = str.charAt(0);
        String ros = str.substring(1);
        
        ArrayList<String> temp = gss(ros);
        ArrayList<String> finall = new ArrayList<String>();
        
        for(String itr: temp){
            finall.add("" + itr);
        }
        
          for(String itr: temp){
            finall.add(ch + itr);
        }
        
        return finall;
        
    }

}
