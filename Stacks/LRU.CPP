//https://leetcode.com/problems/lru-cache/submissions/
//first design a doubly LL and then initialize maps. while performing get and put, dnt just get and put, we have to insert and front and make it as recently used and modify
//other parameters
class LRUCache {
public:
    map<int,int> mp;
    map<int,list<int>::iterator> address; //using this so that i need not iterate LL to find
    list<int> ls; //list acts like doubly-linked list
    int cap;
    int size;
    LRUCache(int capacity) {
        cap = capacity;
        size=0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        //delete it wherever its in between and insert at the front
        list<int>::iterator it = address[key]; //get the address , delete it and insert at the front
        ls.erase(it);
        address.erase(key);
        ls.push_front(key);
        address[key]=ls.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            //remove the old one if exists completely
            ls.erase(address[key]);
            address.erase(key);
            mp.erase(key);
            size--;
        }
        //need to check if size exceeds capacity, if does remove oldest one
        if(size==cap){
            int k = ls.back();
            ls.pop_back();
            address.erase(k);
            mp.erase(k);
            size--;
        }
        //insert the new one at front
        size++;
        ls.push_front(key);
        address[key]=ls.begin();
        mp[key]=value;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
