class LRUCache {
public:
    unordered_map<int, list<pair<int,int>>::iterator> cache;  // cache[key] = iterator
    list<pair<int,int>> pairs;      // {value, key}
    int size_;
    
    LRUCache(int capacity) {
        size_ = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it != cache.end()) {
            pairs.splice(pairs.begin(), pairs, it->second);
            return it->second->first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        
        // key found
        if(it != cache.end()) {
            pairs.splice(pairs.begin(), pairs, it->second);
            it->second->first = value;
            return;
        }
        
        // key not found
        // size limit exceeded
        if(cache.size() == size_) {
            auto lru_node = pairs.back();
            cache.erase(lru_node.second);
            pairs.pop_back();
        }
        pairs.push_front({value, key});
        cache[key] = pairs.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */