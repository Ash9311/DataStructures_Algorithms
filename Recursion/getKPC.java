import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println(getKPC(str));

    }
    
    public static String[] codes = {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

    public static ArrayList<String> getKPC(String str) {
        if(str.length()<=0){
            ArrayList<String> nullCase = new ArrayList<>();
            nullCase.add("");
            return nullCase;
        }
        
       char ch = str.charAt(0);
       String remaining = str.substring(1);
       
       ArrayList<String> remainingList = getKPC(remaining);
       ArrayList<String> ans = new ArrayList<String>();
       
     String codeforch = codes[ch - '0'];       
        
        for(int i=0;i<codeforch.length();i++){
            char chcode = codeforch.charAt(i);
            for(String val: remainingList){
                ans.add(chcode + val);
            }
        }
        return ans;
        
    }

}
