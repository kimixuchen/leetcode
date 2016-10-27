/*
LeetCode-316-Remove Duplicate Letters
27/10/16 09:31:55
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
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        int counts[26];
        int used[26];
        memset(counts, 0, sizeof(counts));
        memset(used, 0, sizeof(used));
        for(char c : s)
            counts[c-'a']++;
        
        string ret;
        for(int i=0; i<s.length(); ++i)
        {
            counts[s[i]-'a']--;
            if(used[s[i]-'a']==1)
                continue;
            
            while(!st.empty() && st.top()>=s[i] && counts[st.top()-'a']>0)
            {
                used[st.top()-'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            used[s[i]-'a'] = 1;
        }
        while(!st.empty())
        {
            ret = st.top() + ret;
            st.pop();
        }
        
        return ret;
    }
};

