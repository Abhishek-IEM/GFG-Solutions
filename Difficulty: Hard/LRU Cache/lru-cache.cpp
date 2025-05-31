class LRUCache {
  private:
  int capacity;
  list<pair<int, int>> lruList;
  unordered_map<int, list<pair<int, int>>::iterator> cache;
  
  public:
    LRUCache(int cap) {
        // code here
        capacity = cap;
    }

    int get(int key) {
        //code here
        if (cache.find(key) == cache.end())
            return -1;

        auto it = cache[key];
        int value = it->second;
        lruList.erase(it);
        lruList.push_front({key, value});
        cache[key] = lruList.begin();
        return value;
    }

        
    void put(int key, int value) {
        // code here
        if (cache.find(key) != cache.end()) {
            lruList.erase(cache[key]);
        } else if (lruList.size() == capacity) {
            int lruKey = lruList.back().first;
            lruList.pop_back();
            cache.erase(lruKey);
        }

        lruList.push_front({key, value});
        cache[key] = lruList.begin();

    }
};