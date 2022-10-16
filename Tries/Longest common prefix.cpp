//https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//construct a Trie data structure. insert all words into the Trie keep incrementing the child count
//while calculating LCP. push the elements into the ans only if childcount is 1 and then update index and root
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        childCount = 0;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie{
    public:
    TrieNode *root;
    Trie(char ch){
        root = new TrieNode(ch);   
    }
    
    //O(l) l->size of word
    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        //assumption, word will be in caps
        int index = word[0] - 'a';
        TrieNode* child;

        //if present
        if(root->children[index] !=NULL){
            child = root->children[index];    
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;

        }
        //recursion
        insertUtil(child,word.substr(1));

    }
    void insertWord(string word){
        insertUtil(root,word);
    }
    
    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(root->childCount==1){
                ans.push_back(ch);
                //move forward
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0'); 
    //insert all strings to trie
    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }
    string first = arr[0];
    string ans = "";
    
    t->lcp(first,ans);
    return ans; 
}


