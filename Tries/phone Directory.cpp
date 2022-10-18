//https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//construct a Trie, insert all words into the Trie. Implement a get suggestion function and print them.

//T.C->O(n*m*m)  S.C->O(n*m)
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

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
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
            root->children[index] = child;
        }
        //recursion
        insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }
    
    vector<vector<string>> getSuggestions(string &str){
    TrieNode* prev = root; //need previous pointer to keep track
    vector<vector<string>> output;
    string prefix = "";
    //iterate through each char and recursively get suggested words
    for(int i=0;i<str.length();i++){
        char lastch = str[i];
        prefix.push_back(lastch);
        
        //check for last char
        TrieNode* curr = prev->children[lastch - 'a'];
        
        //if not found
        if(curr==NULL){
            break;
        }
      //if found
        vector<string> temp;
        printSuggestions(curr,temp,prefix);
        output.push_back(temp); //backtrack and explore other combinations
        temp.clear();
        prev = curr; //move forward
    }
    return output;
}
    
    void printSuggestions(TrieNode* curr,vector<string> &temp,string prefix){
    if(curr->isTerminal){
        temp.push_back(prefix);
    }
    for(char ch='a';ch<='z';ch++){
        TrieNode* next = curr->children[ch-'a'];
        if(next!=NULL){
            prefix.push_back(ch);
            printSuggestions(next,temp,prefix);
            prefix.pop_back();
        }
    }
}
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie *t = new Trie(); //creation of Trie
    
    //insert all contact into the trie
    for(int i=0;i<contactList.size();i++){
        string str = contactList[i];
        t->insertWord(str);
    }
    return t->getSuggestions(queryStr);
}
