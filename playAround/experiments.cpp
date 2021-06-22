
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(map(jewels.count,stones))

    
-----------------------------------------------------------------------------
    String removeDups(String S) {
        // code here
        
        LinkedHashSet<Character> lhs = new LinkedHashSet<>(); 
        String ans="";
        for(int i=0;i<S.length();i++) 
            lhs.add(S.charAt(i)); 
          
        // print string after deleting duplicate elements 
        for(Character ch : lhs) {
            ans+=ch+"";
        }
      
      return ans;  
    }
------------------------------------------------------------------------------
    
    //replacing num
    
    class Solution:
    def maximum12Number (self, num: int) -> int:
        return int(str(num).replace('1','2',1))
            
            public int maximum69Number (int num) {
        return Integer.parseInt(("" + num).replaceFirst("1", "2"));
    }
--------------------------------------------------------------------
