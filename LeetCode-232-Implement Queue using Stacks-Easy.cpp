/**
LeetCode-232-Implement Queue using Stacks
10/10/16 10:41:16
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

class Queue {
private:
    stack<int> s;
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
        
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> ms;
        while(!s.empty())
        {
            ms.push(s.top());
            s.pop();
        }
        ms.pop();
        while(!ms.empty())
        {
            s.push(ms.top());
            ms.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> ms;
        int ret;
        while(!s.empty())
        {
            ms.push(s.top());
            s.pop();
        }
        ret = ms.top();
        while(!ms.empty())
        {
            s.push(ms.top());
            ms.pop();
        }
        
        return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};
