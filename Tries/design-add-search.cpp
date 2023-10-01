//https://leetcode.com/problems/design-add-and-search-words-data-structure/
class WordDictionary {
public:
    vector<WordDictionary*> child;
    bool isEndOfWord;

    // Initialize your data structure here. 
    WordDictionary(){
        isEndOfWord = false;
        child = vector<WordDictionary*>(26, nullptr);
    }

    void addWord(string word) {
        WordDictionary* curr = this;
        for(auto &ch:word){
            int i = ch - 'a';
            if(curr->child[i]==NULL) curr->child[i]=new WordDictionary();
            curr = curr->child[i];
        }
        curr->isEndOfWord = true;

    }
    
    bool search(string word) {
          WordDictionary* curr = this;
         
        for(int i=0;i<word.length();++i){
            char c = word[i];
            if(c=='.'){   // If the current character is a '.', it's a wildcard, so we need to search all child nodes
               for(auto ch: curr->child)
                   if(ch && ch->search(word.substr(i+1))) return true; // Recursively search the rest of the word with the current child node
                return false;
               }
            
        
            if(curr->child[c-'a']==NULL) return false;
            curr = curr->child[c-'a'];
        }
         return curr && curr->isEndOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
