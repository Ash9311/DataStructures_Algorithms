

class TrieNode{
    public:
    bool isWord;
    TrieNode *child[26];
    TrieNode(){
        isWord = false;
        for(auto &ch:child){
            ch = NULL;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto &ch: word){
            int i = ch-'a'; //will get ascii value
            if(!curr->child[i]) curr->child[i] = new TrieNode(); //create trie if that char not present
            curr = curr->child[i];
        }
        curr->isWord=true;
    }
    
    bool search(string word,bool prefix=false) { //if parameter passed as true then this will b over ridden
        TrieNode* curr = root;
        for(auto &ch: word){
            int i = ch-'a';
            if(!curr->child[i]) return false;
            curr = curr->child[i];
        }
        if(prefix==false) return curr->isWord;//if searching for exact word. make sure last node is terminated
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



----------------
    
//https://www.codingninjas.com/codestudio/problems/implement-trie_631356?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie {
TrieNode* root;
public:
 
    /** Initialize your data structure here. */
    Trie() {
         root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
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
            
            root->children[index] = child;

        }
        //recursion
        insertUtil(root,word.substr(1));

    }
    void insert(string word) {
        insertUtil(root,word);
    }

    /** Returns if the word is in the trie. */
       bool searchUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }

        int index = word[0] - 'a'; //assuming cap letters
        TrieNode *child;

        //present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{//absent
            return false;
        }

        //recursion
        return searchUtil(child,word.substr(1));
    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
       bool prefixUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return true;
        }

        int index = word[0] - 'a'; //assuming cap letters
        TrieNode *child;

        //present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{//absent
            return false;
        }

        //recursion
        return prefixUtil(child,word.substr(1));
    }
    bool startsWith(string prefix) {
        return prefixUtil(root,prefix);
    }
};
