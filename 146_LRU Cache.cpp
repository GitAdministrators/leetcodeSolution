class LRUCache {
public:
    LRUCache(int capacity) {
        m_size = capacity;
        m_cursize = 0;
    }
    
    int get(int key) {
        auto it = m_cache.begin();
        while(it!=m_cache.end())
        {
            if(it->first == key)
            {
                int tmpsec = it->second;
                m_cache.erase(it);
                m_cursize--;
                put(key,tmpsec);
                return tmpsec;
            }
            it++;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = m_cache.begin();
        while(it!=m_cache.end())
        {
            if(key == it->first)
            {
                m_cache.erase(it);
                m_cursize--;
                break;
            }
            it++;
        }
        
        if(m_cursize == m_size) 
        {
            m_cache.pop_front();
            m_cursize--;
        }
        
        m_cache.push_back(std::make_pair(key,value));
        m_cursize++;
    }
private:
    list<std::pair<int,int> > m_cache;
    int           m_size;
    int           m_cursize;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
