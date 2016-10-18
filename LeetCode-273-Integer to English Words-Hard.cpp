/**
LeetCode-273-Integer to English Words
18/10/16 09:28:28
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
    string ntow(int num) //num is between 1 and 999
    {
        string ret;
        string m1[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine"};
        string m2[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
        "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string m3[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
        "Eighty", "Ninety"};
        
        int n1, n2, n3;
        n1 = num/100;
        n2 = (num/10)%10;
        n3 = num%10;
        
        if(n1 != 0)
        {
            ret += m1[n1];
            ret += " Hundred";
        }
        
        if(n2==1)
        {
            if(ret != "")
                ret += " ";
            ret += m2[n3];
        }
        else
        {
            if(n2 != 0)
            {
                if(ret != "")
                    ret += " ";
                ret += m3[n2];
            }
            if(n3 != 0)
            {
                if(ret != "")
                    ret += " ";
                ret += m1[n3];
            }
        }
        
        return ret;
    }
public:
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        unordered_map<int, string> m;
        string ret;
        
        m[0] = "";
        m[1] = "Thousand";
        m[2] = "Million";
        m[3] = "Billion";
        
        int n = 0, t = num;
        while(t>0)
        {
            t /= 10;
            ++n;
        }
        
        bool isFirst = true;
        for(int i=3; i>=0; --i)
        {
            t = num;
            if(n>i*3)
            {
                t /= pow(1000, i);
                t %= 1000;
                string tmp = ntow(t);
                if(tmp != "" && !isFirst)
                    ret += " ";
                ret += tmp;
                if(tmp != "" && i>0)
                {
                    ret += " ";
                    ret += m[i];
                }
                isFirst = false;
            }
        }
        return ret;
        
    }
};
