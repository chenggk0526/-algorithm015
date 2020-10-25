struct CacheNode {
    int key_, value_;
    CacheNode *pre_, *next_;

    CacheNode(int key = 0, int value = 0) : 
        key_(key), value_(value), pre_(nullptr), next_(nullptr) {}
};


class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity), head_(new CacheNode()), tail_(head_) {}
    
    ~LRUCache() {
        auto pCurr = head_;
        while (pCurr != nullptr) {
            auto next = pCurr->next_;
            delete pCurr;
            pCurr = next;
        }
    }

    int get(int key) {
        auto it = cache_.find(key);
        if (it == cache_.end()) return -1;
        moveToTail(it->second);
        return it->second->value_;
    }
    
    void put(int key, int value) {
        auto it = cache_.find(key);

        if (it != cache_.end()) {
            it->second->value_ = value;
            moveToTail(it->second);
        } else if ((int)cache_.size() < capacity_) {
            auto node = new CacheNode(key, value);
            addToTail(node);
            cache_[key] = node;
        } else {
            while (head_ == nullptr || head_->next_ == nullptr) return;
            cache_.erase(head_->next_->key_);
            moveToTail(head_->next_);
            tail_->key_ = key;
            tail_->value_ = value;
            cache_[key] = tail_;
        }
    }

private:
    const int capacity_;
    CacheNode *const head_, *tail_;
    unordered_map<int, CacheNode*> cache_;

    void moveToTail(CacheNode *node) {
        while (node == nullptr || node->next_ == nullptr) return;
        if (node == tail_) return;

        node->pre_->next_ = node->next_;
        node->next_->pre_ = node->pre_;

        addToTail(node);
    }

    void addToTail(CacheNode *node) {
        node->next_ = tail_->next_;
        tail_->next_ = node;
        node->pre_ = tail_;
        tail_ = node;
    }


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */