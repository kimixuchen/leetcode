/**
LeetCode-151-Reverse Words in a String
18/09/16 08:28:41
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
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
private:
    void reverseStr(string &s, int from, int to, int begin)
    {
        char  tmp;
        int left=from, right=to;
        while(left < right)
        {
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            ++left;
            --right;
        }
        int pos1 = begin, pos2 = from;
        while(pos2<=to)
        {
            s[pos1++]=s[pos2++];
        }
    }
public:
    void reverseWords(string &s) {
        int i=0;
        int pos=0;
        int storeindex = 0;
        while(i<s.length())
        {
            if(s[i]!=' ')
            {
                pos = i;
                while(i<s.length() && s[i]!=' ')
                    ++i;
                reverseStr(s, pos, --i, storeindex);
                storeindex += i-pos+2;
                s[storeindex-1] = ' ';
            }
            ++i;
        }
        if(storeindex==0)
            s = "";
        else
            s = s.substr(0, storeindex-1);
        reverseStr(s, 0, s.length()-1, 0);
        
    }
};

int main()
{
    Solution slu;
    string s = "sky   is bule";
    slu.reverseWords(s);
    cout<<s<<endl;

    return 0;
}
