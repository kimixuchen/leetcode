/*
LeetCode-394-Decode String
27/11/16 10:03:43
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

class Solution {
private:
    bool isNumber(string s)
    {
        for(char c : s)
        {
            if(!isdigit(c))
                return false;
        }
        return true;
    }
public:
    string decodeString(string s) {
        stack<string> st;
        string ret;
        
        int pos = 0;
        while(pos < s.length())
        {
            if(s[pos]>='1' && s[pos]<='9')
            {
                int num = 0;
                while(s[pos]>='0' && s[pos]<='9')
                {
                    num *= 10;
                    num += s[pos]-'0';
                    ++pos;
                }
                st.push(to_string(num));
                //skip '['
                ++pos;
            }
            else if(s[pos]==']')
            {
                string cur;
                while(!st.empty() && !isNumber(st.top()))
                {
                    cur = st.top()+cur;
                    st.pop();
                }
                //cout<<cur<<endl;
                if(!st.empty())
                {
                    int num = stoi(st.top());
                    //printf("%d\n", num);
                    st.pop();
                    string newcur;
                    for(int i=0; i<num; ++i)
                        newcur += cur;
                    st.push(newcur);
                }
                ++pos;
            }
            else
            {
                st.push(string(1, s[pos]));
                ++pos;
            }
        }
        while(!st.empty())
        {
            ret = st.top()+ret;
            st.pop();
        }
        return ret;
        
    }
};
