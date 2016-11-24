/*
LeetCode-385-Mini Parser
24/11/16 09:57:40
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
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s[0]!='[')
        {
            return NestedInteger(stoi(s));
        }
        
        stack<NestedInteger> st;
        int pos = 0;
        int num;
        int flag = 1;
        while(pos < s.length())
        {
            if(s[pos] == '[')
            {
                st.push(NestedInteger());
                num = 0;
                flag = 1;
            }
            else if(s[pos]=='-')
            {
                flag = -1;
            }
            else if(s[pos]>='0' && s[pos]<='9')
            {
                num *= 10;
                num += s[pos]-'0';
            }
            else if(s[pos] == ',')
            {
                if(s[pos-1] != ']')
                {
                    st.top().add(flag*num);
                    num = 0;
                    flag = 1;
                }
            }
            else if(s[pos] == ']')
            {
                NestedInteger tmp  = st.top();
                if(s[pos-1]!=']' && s[pos-1]!='[')
                {
                    tmp.add(flag*num);
                    num = 0;
                    flag = 1;
                }
                st.pop();
                if(!st.empty())
                    st.top().add(tmp);
                else
                    st.push(tmp);
            }
            ++pos;
        }
        return st.top();
    }
};
