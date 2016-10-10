/**
LeetCode-225-Implement Stack using Queues
10/10/16 10:18:58
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

class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        for(int i=0; i<q.size()-1; ++i)
        {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    // Get the top element.
    int top() {
        for(int i=0; i<q.size()-1; ++i)
        {
            q.push(q.front());
            q.pop();
        }
        int ret = q.front();
        q.push(q.front());
        q.pop();
        return ret;
        
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
        
    }
};
