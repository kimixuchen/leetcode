/**
LeetCode-282-Expression Add Operators
19/10/16 21:03:20
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

class Solution {
private:
    void search(vector<string> &ret, string num, string path, int pos, 
            int target, long long cur, long long mul)
    {
        if(pos == num.length())
        {
            if(cur==target)
            {
                ret.push_back(path);
            }
            return;
        }
        
        long long tmp = 0;
        for(int i=pos; i<num.length(); ++i)
        {
            tmp *= 10;
            tmp += num[i] - '0';
            
            if(i>pos && num[pos]=='0')
                break;
            if(pos==0)
                search(ret, num, num.substr(pos, i-pos+1), i+1, target, 
                        tmp, tmp);
            else
            {
                search(ret, num, path+'+'+num.substr(pos, i-pos+1), i+1, target,
                        cur+tmp, tmp);
                search(ret, num, path+'-'+num.substr(pos, i-pos+1), i+1, target, 
                        cur-tmp, -tmp);
                search(ret, num, path+'*'+num.substr(pos, i-pos+1), i+1, target,
                        cur+mul*tmp-mul, mul*tmp);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        search(ret, num, "", 0, target, 0, 0);
        return ret;
    }
};
