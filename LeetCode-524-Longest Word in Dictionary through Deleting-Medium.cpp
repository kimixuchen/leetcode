#include <iostream>
#include <alogrithm>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
	static bool cmp(const string& s1, const string& s2)
	{
		if(s1.length()==s2.length())
		{
			return s1 < s2;
		}
		else
		{
			return s1.length()>s2.length();
		}
	}

	bool canGen(string& s1, string& s2)
	{
		int pos1 = 0;
		int pos2 = 0;
		while(pos1<s1.length() && pos2<s2.length())
		{
			if(s1[pos1]==s2[pos2])
			{
				++pos1;
				++pos2;
			}
			else
			{
				++pos2;
			}
		}
		return pos1 == s1.length();
	}
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), cmp);


        string ret;

        if(s.length()==0)
        	return ret;
        for(int i=0; i<d.size(); ++i)
        {
        	if(canGen(d[i], s))
        	{
        		ret = d[i];
        		break;
        	}
        }
        return ret;
    }
};