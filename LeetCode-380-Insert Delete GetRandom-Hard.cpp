/*
LeetCode-380-Insert Delete GetRandom
22/11/16 12:16:27
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val)!=map.end())
            return false;
        
        nums.emplace_back(val);
        map[val] = nums.size()-1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val)==map.end())
            return false;
        
        int id = map[val];
        int last = nums.back();
        map[last] = id;
        nums[id] = last;
        map[last] = id;
        map.erase(val);
        nums.pop_back();
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int id = rand()%(nums.size());
        return nums[id];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
