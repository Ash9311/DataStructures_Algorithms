//https://leetcode.com/problems/prefix-and-suffix-search/description/
// You just need basic trie operations (search, insert) to solve this question.
// Using trie you can easily tell whether a word of given prefix is available or not (same with suffix, by making a reverse trie). So the first issue which arises is that you need to check for both suffix prefix of a same word because you can't just independently search the two tries as that may give wrong results.
// So to curb this, since the length of each word is not more that 10, I created all possible suffixes of that word and appended them ahead the word, separated by '#". Like for apple: e#apple, le#apple,......apple#apple.
// Now when a search query comes up, I will just concatenate the suffix with prefix separated by a '#' and then simply search the trie. E.g. If it was "ap" and "e" then just search for "e#ap".
// To get the most recent word (with largest index) out of many possible options, I am maintaining an idx variable for each node, which will get updated if a newer word arrives in that path so that we return the most recent word.

class TrieNode{
    public:
    char data;
    unordered_map<char,TrieNode*> child;
    int idx; //it says about the index of word
    TrieNode(char c){
        data = c;
        idx = -1;
    }
};

class WordFilter {
public:

TrieNode* root = new TrieNode('/0');

void insert(string s,int i){
    TrieNode *curr = root;
    for(char &ch:s){
        if(curr->child.count(ch)==0){
            TrieNode *temp = new TrieNode(ch);
            temp->idx = i;  //map the idx to the respective index of the word
            curr->child[ch] = temp;
            curr= curr->child[ch];
        }
        else{
            curr->child[ch]->idx = i; //map the idx to the respective index of the word
            curr = curr->child[ch];
        }
    }

}


    WordFilter(vector<string>& words) { //place where the actual list of words are being inserted
        for(int i=0;i<words.size();i++){
            string s = words[i];//compute all possible suffix for each word
            string temp = "#";
            temp+=s;
            for(int j=s.size()-1;j>=0;j--){ //insert all possible suffix and the word separated by # into the trie
                char ch = s[j];
                temp = ch+temp;
                insert(temp,i); //ex will insert("le#","apple")
            }
        }
    }
    
    int f(string pref, string suff) { //where pref,suff is given and the stored word is fetched
        string s = suff+"#"+pref;
        int ans = -1;
        TrieNode* curr = root;
        for(char &ch:s){
            if(curr->child.count(ch)==0) return -1;
            ans = curr->child[ch]->idx;
            curr = curr->child[ch];
        }
        return ans;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
