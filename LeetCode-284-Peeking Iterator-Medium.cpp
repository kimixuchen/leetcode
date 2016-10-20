/**
LeetCode-284-Peeking Iterator
20/10/16 08:14:37
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

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool ispeeked;
    int peeknum;
    
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        ispeeked = false;
        peeknum = 0;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!ispeeked)
        {
            if(Iterator::hasNext())
            {
                peeknum = Iterator::next();
                ispeeked = true;
            }
            else
            {
                peeknum = -1;
            }
        }
        return peeknum;
        
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(ispeeked)
        {
            ispeeked = false;
            return peeknum;
        }
        return Iterator::next();
	    
	}

	bool hasNext() const {
        if(ispeeked)
            return true;
        
        return Iterator::hasNext();
	    
	}
};
