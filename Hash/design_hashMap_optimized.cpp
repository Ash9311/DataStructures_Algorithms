//https://leetcode.com/problems/design-hashmap/submissions/

class MyHashMap {
public:
    vector<list<pair<int,int>>> m;
    int size;
    MyHashMap() {
        size = 1000;
        m.resize(size);
       
    }
    
    int hash(int key){
        return key%size;
    }
    
    list<pair<int,int>> :: iterator search(int key){
        int i = hash(key);
        list<pair<int,int>> :: iterator it = m[i].begin();
        while(it!=m[i].end()){
            if(it->first==key){
                return it;
            }
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int i =hash(key);
        remove(key);
        m[i].push_back({key,value});
    }
    
    int get(int key) {
        int i = hash(key);
        list<pair<int,int>> :: iterator it = search(key);
        if(it==m[i].end()) return -1;
        else return it->second;
    }
    
    void remove(int key) {
        int i = hash(key);
        list<pair<int,int>> :: iterator it = search(key);
        if(it!=m[i].end()){
            m[i].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
