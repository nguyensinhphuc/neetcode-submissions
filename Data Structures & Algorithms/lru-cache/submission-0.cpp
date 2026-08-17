class LRUCache {
private:
    int capacity;

    // {key, value}
    // front = recently used
    // back  = least recently used
    list<pair<int, int>> cache;

    // key -> vị trí của key trong list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Lấy node hiện tại
        auto it = mp[key];

        int value = it->second;

        // Đưa node lên đầu vì vừa được sử dụng
        cache.splice(cache.begin(), cache, it);

        return value;
    }

    void put(int key, int value) {
        // Key đã tồn tại
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];

            // Cập nhật value
            it->second = value;

            // Đưa lên đầu vì vừa được sử dụng
            cache.splice(cache.begin(), cache, it);

            return;
        }

        // Key mới
        cache.push_front({key, value});
        mp[key] = cache.begin();

        // Vượt quá capacity
        if (cache.size() > capacity) {
            auto last = cache.back();

            // Xóa key khỏi hashmap
            mp.erase(last.first);

            // Xóa node cũ nhất
            cache.pop_back();
        }
    }
};