/**
LeetCode-146-LRU Cache
13/09/16 12:54:35
xuchen
**/

#include <iostream>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class LRUCache{
private:
    int capcity;
    list<int> used;
    typedef pair<int, list<int>::iterator> PI;
    unordered_map<int, PI> cache;
    
public:
    LRUCache(int capacity):capcity(capcity){
        this->capcity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        
        int value = cache[key].first;
        touch(key);
        
        return value;
    }
    
    void set(int key, int value) {
        if(cache.find(key) == cache.end())
        {
            if(cache.size() == capcity)
            {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        else
        {
            touch(key);
        }
        cache[key] = {value, used.begin()};
    }
    
    void touch(int key)
    {
        auto it = cache[key].second;
        used.erase(it);
        used.push_front(key);
        cache[key].second = used.begin();
        
        return;
    }
};
