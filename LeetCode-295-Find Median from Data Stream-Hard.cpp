/**
LeetCode-295-Find Median from Data Stream
20/10/16 10:07:03
xuchen
**/

#include <iostream>
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
using namespace std;

class MedianFinder {
private:
    priority_queue<int> smallq;
    priority_queue<int> largeq;

public:

    // Adds a number into the data structure.
    void addNum(int num) {
        smallq.push(num);
        if(largeq.size() > 0 && smallq.top() > -largeq.top())
        {
            smallq.pop();
            smallq.push(-largeq.top());
            largeq.pop();
            largeq.push(-num);
        }
        if(smallq.size()-largeq.size()>1)
        {
            largeq.push(-smallq.top());
            smallq.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(smallq.size()>largeq.size())
            return smallq.top();
        else
            return (smallq.top()-largeq.top())*1.0/2;
        
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
