/*
                    h( AAB , -1 , 0 )              LEVEL=0 ie 0 length substring
                    /               \
            h('A'AB,0,1)           h('B'AA,6,1)    LEVEL=1 ie 1 length substrings ("A","B")
            /         \              /
        h('AA'B,1,2) h('AB'A,4,2) h('BA'A,7,2)     LEVEL=2 ie 2 length substrings ("AB","BA","AA")
        /            /             /
    h('AAB',2,3)    h('ABA',5,2)  h('BAA',8,3)     LEVEL=3 ie 3 length substrings 
                                                   ("AAB", "ABA", "BAA")
*/
//sort the string first, and then use swapping and recursive approach to find all permutation
class Solution {
public:
    
    void solve(string tiles,int i,int &count){
        count++;
        for(int j=i;j<tiles.length();j++){ //no base condition bcoz condition is in for loop
            if(tiles[i]==tiles[j] and i!=j){
                continue;   //to avoid swapping same char
            }
            swap(tiles[i],tiles[j]);
            solve(tiles,i+1,count);
        }
    }
    
    int numTilePossibilities(string tiles) {
       int count = -1;
        sort(tiles.begin(),tiles.end());
        solve(tiles,0,count);
        return count;
    }
};
