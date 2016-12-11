/*
LeetCode-468-Validate IP Address
11/12/16 11:07:44
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
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.length()==0)
            return "Neither";
        
        int pos = 0;
        int category = 0;
        int leadingzero = 0;
        bool nozero = false;
        int len = 0;
        int splitCount = 0;
        int ipv4Num = 0;
        while(pos < IP.length())
        {
            if(IP[pos]>='0' && IP[pos]<='9')
            {
                if(!nozero && IP[pos]=='0')
                {
                    leadingzero++;
                }
                else
                {
                    nozero = true;
                }
                ipv4Num *= 10;
                ipv4Num += IP[pos]-'0';
                len++;
            }
            else if((IP[pos]>='a' && IP[pos]<='f') || 
                    (IP[pos]>='A' && IP[pos]<='F'))
            {
                category = 6;
                nozero = true;
                len++;
            }
            else if(IP[pos]=='.')
            {
                if(len==0 || len>3 || (leadingzero>0 && nozero) || category==6 || 
                        ipv4Num>255 || leadingzero>1)
                {
                    category = -1;
                    break;
                }
                category = 4;
                nozero = false;
                len = 0;
                leadingzero = 0;
                ipv4Num = 0;
                splitCount++;
            }
            else if(IP[pos]==':')
            {
                if(len==0 || len>4 || category==4)
                {
                    category = -1;
                    break;
                }
                category = 6;
                nozero = false;
                len = 0;
                leadingzero = 0;
                ipv4Num = 0;
                splitCount++;
            }
            else
            {
                category = -1;
                break;
            }
            ++pos;
        }
        //printf("%d\n", category);
        if(pos>=IP.length())
        {
            if(splitCount==3 && category==4)
            {
                //printf("%d\n", category);
                if(len==0 || len>3 || (leadingzero>0 && nozero) || ipv4Num>255
                        || leadingzero>1)
                {
                    category = -1;
                }
            }
            else if(splitCount==7 && category==6)
            {
                if(len==0 || len>4 || category==4)
                {
                    category = -1;
                }
            }
            else
                category = -1;
        }
        else
        {
            category = -1;
        }
        
        if(category==4)
            return "IPv4";
        else if(category==6)
            return "IPv6";
        else
            return "Neither";
        
    }
};
