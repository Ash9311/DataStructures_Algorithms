
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(map(jewels.count,stones))

-----------------------------------------------------------------------------
    String removeDups(String S) {
		

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
    
    import java.util.*;

public class Main{

     void permutation(String str){
            permutation(str,"");
        }

        void permutation(String str, String prefix){
            if(str.length()==0){
                System.out.println(prefix);
            }
            else{
            }
                for(int i=0;i<str.length();i++){
                    String rem = str.substring(0,i) + str.substring(i+1);
                    permutation(rem,prefix + str.charAt(i));
            }
        }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Main m = new Main();
        m.permutation("ashu");
    }
}

-------------------------------------------------------------------------
    
    public static void FrequentWord(String array[]) 
	{ 
		// Insert all unique strings and update count if a string is not unique.
		Map<String,Integer> hshmap = new HashMap<String, Integer>(); 
		for (String str : array) 
		{ 
			if (hshmap.keySet().contains(str)) // if already exists then update count. 
				hshmap.put(str, hshmap.get(str) + 1); 
			else
				hshmap.put(str, 1); // else insert it in the map.
		} 
    	// Traverse the map for the maximum value.
		String maxStr = ""; 
    	int maxVal = 0; 
		for (Map.Entry<String,Integer> entry : hshmap.entrySet()) 
		{ 
			String key = entry.getKey(); 
			Integer count = entry.getValue(); 
			if (count > maxVal) 
			{ 
				maxVal = count; 
				maxStr = key+" "; 
			} 
			
			else if (count == maxVal) 
			{ 
				maxVal = count; 
				maxStr += key+" "; 
			} 
			
      		// Condition for the tie.
			else if (count == maxVal){ 
				if (key.length() < maxStr.length())
					maxStr = key; 
			}
		} 
		System.out.println("Most frequent word: "+ maxStr);
		System.out.println("Count: "+ maxVal); 
	}

----------------------------------------------------------------------------------------------
	
	class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        t = iter(t)
        return all(i in t for i in s)
		
	def isSubsequence(self, s, t):
    remainder_of_t = iter(t)
    for letter in s:
        if letter not in remainder_of_t:
            return False
    return True
-----------------------------------------------------------------------

nt best = Arrays.stream(b).min().getAsInt();
        int worst = Arrays.stream(b).max().getAsInt();
String b=String.valueOf(a);
Len=String.valueOf(a).length();

-------------------------------------------------------------------
	class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        return (String.join("",word1).equals(String.join("",word2)));
    }
}


const data = {
  "users": [
    {
      "id": 1,
      "name": "John",
      "age": 25,
      "hobbies": ["reading", "gaming"],
      "address": {
        "street": "123 Main St",
        "city": "Anytown",
        "state": "CA",
        "zip": "12345"
      }
    },
    {
      "id": 2,
      "name": "Jane",
      "age": 30,
      "hobbies": ["hiking", "photography"],
      "address": {
        "street": "456 Oak St",
        "city": "Someville",
        "state": "NY",
        "zip": "54321"
      }
    },
    {
      "id": 3,
      "name": "Bob",
      "age": 35,
      "hobbies": ["cooking"],
      "address": {
        "street": "789 Elm St",
        "city": "Othercity",
        "state": "FL",
        "zip": "67890"
      }
    }
  ]
};

// Filter users ov…
In this example, we have a JSON object with an array of users. We use the filter() method to filter the users over the age of 30, and then the map() method to return an array of objects containing only the user's name and hobbies. The resulting filteredUsers array will contain two objects representing users Jane and Bob:
[  {    "name": "Jane",    "hobbies": ["hiking", "photography"]
  },
  {
    "name": "Bob",
    "hobbies": ["cooking"]
  }
]
data.users.filter(user => user.hobbies.includes("gaming"));  //user whose hobbies include gaming
