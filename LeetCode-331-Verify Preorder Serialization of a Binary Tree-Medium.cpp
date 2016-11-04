/*
LeetCode-331-Verify Preorder Serialization of a Binary Tree
04/11/16 10:11:11
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
private:
    struct Node{
        int val;
        int visitednum;
        Node(int v, int n)
        {
            val = v;
            visitednum = n;
        }
    };

public:
    bool isValidSerialization(string preorder) {
        stack<Node> s;
        vector<string> nodes;
        stringstream sstr(preorder);
        string token;
        
        while(getline(sstr, token, ','))
            nodes.push_back(token);
        
        //only a null node
        if(nodes.size()==1 && nodes[0]=="#")
            return true;
        
        int pos = 0;
        while(pos < nodes.size())
        {
            if(nodes[pos]!="#")
            {
                int v = stoi(nodes[pos]);
                Node tmp(v, 0);
                s.push(tmp);
            }
            else
            {
                if(s.empty())
                    return false;
                s.top().visitednum++;
                while(!s.empty() && s.top().visitednum==2)
                {
                    s.pop();
                    if(!s.empty())
                        s.top().visitednum++;
                }
            }
            ++pos;
            if(s.empty())
                break;
        }
        
        if(!s.empty() || pos<nodes.size())
            return false;
        else
            return true;
    }
};
