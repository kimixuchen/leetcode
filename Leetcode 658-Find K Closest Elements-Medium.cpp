/*
 * Leetcode 658-Find K Closest Elements
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

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int closestPos = -1;
        int minDiff = INT_MAX;
        int n = arr.size();
        
        for(int i=0; i<n; i++) {
            if(abs(arr[i]-x) < minDiff) {
                minDiff = abs(arr[i] - x);
                closestPos = i;
            }
        }
        
        int lpos = closestPos;
        int rpos = closestPos+1;
        vector<int> smalls;
        vector<int> larges;
        while((smalls.size() +larges.size())< k) {
            if(lpos < 0) {
                larges.push_back(arr[rpos]);
                rpos++;
            }
            else if(rpos >= n) {
                smalls.push_back(arr[lpos]);
                lpos--;
            }
            else {
                if(x-arr[lpos] <= arr[rpos]-x) {
                    smalls.push_back(arr[lpos]);
                    lpos--;
                }
                else {
                    larges.push_back(arr[rpos]);
                    rpos++;
                }
            }
        }
        
        reverse(smalls.begin(), smalls.end());
        vector<int> ret;
        ret.insert(ret.end(), smalls.begin(), smalls.end());
        ret.insert(ret.end(), larges.begin(), larges.end());
        
        return ret;
    }
};




















