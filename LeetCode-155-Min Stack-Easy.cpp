/**
LeetCode-155-Min Stack
19/09/16 09:35:12
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
using namespace std;

class MinStack {
private:
    vector<int> s;
    int _min;
public:
    /** initialize your data structure here. */
    MinStack() {
        _min = INT_MAX;
    }
    
    void push(int x) {
        s.push_back(x);
        _min = min(_min, x);
    }
    
    void pop() {
        if(s.empty())
            return;
        s.pop_back();
        _min = INT_MAX;
        for(int i=0; i<s.size(); ++i)
            _min = min(_min, s[i]);
    }
    
    int top() {
        return s.back();
        
    }
    
    int getMin() {
        return _min;
    }
};
