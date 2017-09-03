/**
LeetCode-669-Maximum Swap
2017年9月3日
xuchen
**/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
#include <stdlib.h>
#include <cstring>
#include <unordered_map>
#include <set>
#include <sstream>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
		vector<int> resMax;
		vector<int> digits;

		while(num > 0) {
			digits.push_back(num%10);
			resMax.push_back(0);
			num /= 10;
		}
		reverse(digits.begin(), digits.end());
		
		int _max = 0;
		for(int i = digits.size()-1; i>=0; i--) {
			resMax[i] = _max;
			_max = max(digits[i], _max);
		}
		
		bool swaped = false;
		for(int i=0; i<digits.size(); i++) {
			if(digits[i] < resMax[i]) {
				for(int j=digits.size()-1; j>i; j--) {
					if(digits[j] == resMax[i]) {
						swap(digits[i], digits[j]);
						swaped = true;
						break;
					}
				}
			}
			if(swaped)
				break;
		}

		int ret = 0;
		for(int i : digits) {
			ret *= 10;
			ret += i;
		}

		return ret;
    }
};












