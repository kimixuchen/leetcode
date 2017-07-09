/*
 * Leetcode 635
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

struct mylog{
    int id;
    string time;
    mylog(int i, string t)
    {
        id = i;
        time = t;
    }
    
    bool operator<(const struct mylog & right) const
    {
        return this->time < right.time;
    }
};
    
class LogSystem {
private:
set<mylog> logs;
map<string, int> gras;
public:
    LogSystem() {
        gras["Year"] = 0;
        gras["Month"] = 1;
        gras["Day"] = 2;
        gras["Hour"] = 3;
        gras["Minute"] = 4;
        gras["Second"] = 5;
    }
    
    void put(int id, string timestamp) {
        mylog l(id, timestamp);
        logs.insert(l);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        int g = gras[gra];
        switch(g)
        {
        case 0:
            s[5]='0'; s[6]='0';
            e[5]='1'; e[6]='2';
        case 1:
            s[8]='0'; s[9]='0';
            e[8]='3'; e[9]='1';
        case 2:
            s[11]='0'; s[12]='0';
            e[11]='2'; e[12]='3';
        case 3:
            s[14]='0'; s[15]='0';
            e[14]='5'; e[15]='9';
        case 4:
            s[17]='0'; s[18]='0';
            e[17]='5'; e[18]='9';
        }
        vector<int> ret;
        
        for(auto iter=logs.begin(); iter!=logs.end(); iter++) {
            if(iter->time >= s && iter->time <= e)
                ret.push_back(iter->id);
            if(iter->time > e)
                break;
        }
        return ret;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */