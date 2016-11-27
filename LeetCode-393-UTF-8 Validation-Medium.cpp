/*
LeetCode-393-UTF-8 Validation
27/11/16 09:31:42
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
    int getN(vector<int> &data, int pos)
    {
        int n = 0;
        int model[8] = {128, 64, 32, 16, 8, 4, 2, 1};
        for(int i=pos; i<data.size(); ++i)
        {
            int j = 0;
            for(j=0; j<8; ++j)
            {
                if((data[i] & model[j]) > 0)
                {
                    ++n;
                }
                else
                    break;
            }
            if(j<8)
                break;
        }
        
        return n;
    }
public:
    bool validUtf8(vector<int>& data) {
        
        int pos = 0;
        bool isvalid = true;
        while(pos < data.size())
        {
            int n = getN(data, pos);
            //printf("n=%d\n", n);
            
            if(n==0)
            {
                isvalid = pos<data.size() && data[pos] <= 127;
                ++pos;
            }
            else if(n==1)
            {
                isvalid = false;
            }
            else
            {
                int pre = (n+1)/8;
                if((n+1) % 8 != 0)
                    pre++;
                
                if(data.size() < pos+pre+n-1)
                    isvalid = false;
                else
                {
                    for(int i=pre; i<pre+n-1; ++i)
                    {
                        if(data[pos+i]<128 || data[pos+i]>191)
                        {
                            isvalid = false;
                            break;
                        }
                    }
                }
                pos += pre+n-1;
            }
            
            //printf("isvalid=%d\n", isvalid);
            
            if(!isvalid)
                break;
        }
        
        return isvalid;
    }

};
