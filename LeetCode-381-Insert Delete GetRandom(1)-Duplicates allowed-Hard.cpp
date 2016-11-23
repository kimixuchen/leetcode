/*
LeetCode-381-Insert Delete GetRandom(1)-Duplicates allowed
23/11/16 09:28:05
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

class RandomizedCollection {
private:
    struct Ele{
        int val;
        int pre;
        int next;
        Ele(int v, int p, int n)
        {
            val = v;
            pre = p;
            next = n;
        }
    };
    
    unordered_map<int, int> map;
    vector<Ele> nums;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        nums.emplace_back(Ele(val, -1, -1));
        if(map.find(val)!=map.end())
        {
            int pos = map[val];
            nums[pos].next = nums.size()-1;
            nums.back().pre = pos;
            map[val] = nums.size()-1;
            
            return false;
        }
        else
        {
            map[val] = nums.size()-1;
            
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val)==map.end())
            return false;
        
        int id = map[val];
        int isvalonly = nums[id].pre == -1;
        if(!isvalonly)
        {
            nums[nums[id].pre].next = -1;
            map[val] = nums[id].pre;
        }
        
        Ele last = nums.back();
        if(last.pre != -1)
        {
            nums[last.pre].next = id;
        }
        
        if(last.next != -1)
        {
            nums[last.next].pre = id;
        }
        else
        {
            map[last.val] = id;
        }
        
        if(isvalonly)
            map.erase(val);
        
        nums[id] = last;
        nums.pop_back();
        
        return true;
    }
    
    /** Get a random element from the Collection. */
    int getRandom() {
        int id = rand()%(nums.size());
        return nums[id].val;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
