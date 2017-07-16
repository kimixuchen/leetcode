/*
 * Leetcode 636-Exclusive Time of Functions
 */
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

const int START = 0;
const int END = 1;

struct funcType {
    int id;
    int timing;
    int timestamp;
    funcType(int a, int b, int c) {
        id = a;    timing = b;    timestamp = c;
    }
};

class Solution {
private:
    funcType getFuncType(string s) 
    {
        int id = 0;
        int timing = START;
        int time = 0;
        int i = 0;
        for(i=0; i<s.length() && s[i]!=':'; i++) {
            id *= 10;
            id += s[i]-'0';
        }
        i++;
        for( ;i<s.length() && s[i]!=':'; i++) {
            if(s[i] == 'e') {
                timing = END;
            }
        }
        i++;
        for( ; i<s.length(); i++) {
            time *= 10;
            time += s[i]-'0';
        }
        
        return funcType(id, timing, time);
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> exctime(n, 0);
        stack<int> funcstack;
        
        int curtime;
        int pos = 0;
        bool isPureFun = false;
        int preid;
        int pretiming = -1;
        while(pos < logs.size())
        {
            funcType fun = getFuncType(logs[pos]);
            pos++;
            if(pos > 1) {
                if(fun.id == preid && pretiming==START && fun.timing==END) {
                    isPureFun = true;
                }
                else{
                    isPureFun = false;
                }
            }
            if(funcstack.empty()) {
                curtime = fun.timestamp;
                funcstack.push(fun.id);
            }
            else {
                if(fun.timing == START) {
                    if(pretiming == END) {
                        exctime[funcstack.top()] += fun.timestamp - curtime - 1;
                    }
                    else {
                        exctime[funcstack.top()] += fun.timestamp - curtime;
                    }
                    funcstack.push(fun.id);
                    curtime = fun.timestamp;
                }
                else {
                    if(isPureFun) {
                        exctime[funcstack.top()] += fun.timestamp - curtime + 1;
                    }
                    else{
                        exctime[funcstack.top()] += fun.timestamp - curtime;
                    }
                    curtime = fun.timestamp;
                    funcstack.pop();
                }
            }
            preid = fun.id;
            pretiming = fun.timing;
        }
        
        return exctime;
    }
};
