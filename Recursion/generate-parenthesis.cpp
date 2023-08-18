//https://leetcode.com/problems/generate-parentheses/description/
//         			   	(0, 0, '')
					// 			 	    |	
					// 				(1, 0, '(')  
					// 			   /           \
					// 		(2, 0, '((')      (1, 1, '()')
					// 		   /                 \
					// 	(2, 1, '(()')           (2, 1, '()(')
					// 	   /                       \
					// (2, 2, '(())')                (2, 2, '()()')
					// 	      |	                             |
					// res.append('(())')             res.append('()()')
   
class Solution {
public:
vector<string> ans;

    void solve(int n,int open,int close,string str){
        if(str.length()==n*2){ //we reached the limit
            ans.push_back(str);
            return;
        }
        if(open<n){ //make sure its less than what is given
            solve(n,open+1,close,str+"(");
        }
        if(open>close){ //we can have closed bracked only when open is balanced
        solve(n,open,close+1,str+")");
        }
    }

    vector<string> generateParenthesis(int n) { //declare variables for open,close brackets
        int open =0;
        int close = 0;
        solve(n,open,close,""); //with balancing open,close and lmit 'n' .recursively we can compute all possible valid combinations
        return ans;
    }
};
