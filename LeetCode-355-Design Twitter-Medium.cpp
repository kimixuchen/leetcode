/*
LeetCode-355-Design Twitter
17/11/16 09:46:56
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

class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> tweetsList;   //include timestamp
    unordered_map<int, vector<int>> followList;
    int timestamp;

public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweetsList[userId].push_back(make_pair(tweetId, timestamp));
        timestamp++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        //add self
        followList[userId].push_back(userId);
        
        int counter = 10;
        vector<int> ret;
        int n = followList[userId].size();
        vector<int> posList(n);
        for(int i=0; i<n; ++i)
        {
            posList[i] = tweetsList[followList[userId][i]].size()-1;
        }
        
        while(counter>0)
        {
            int user = -1;
            int pos = -1;
            int time = -1;
            int index = -1;
            for(int i=0; i<n; ++i)
            {
                if(posList[i]>=0)
                {
                    int t = tweetsList[followList[userId][i]][posList[i]].second;
                    if(time < t)
                    {
                        time = t;
                        index = i;
                        pos = posList[i];
                        user = followList[userId][i];
                    }
                }
            }
            if(time > -1)
            {
                ret.push_back(tweetsList[user][pos].first);
                --counter;
                posList[index]--;
            }
            else
            {
                break;
            }
        }
        
        //remove self
        followList[userId].pop_back();
        
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        for(int i : followList[followerId])
            if(i == followeeId)
                return;
        
        followList[followerId].push_back(followeeId);
        
        return;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        for(auto it = followList[followerId].begin(); 
                it != followList[followerId].end(); ++it)
        {
            if(*it == followeeId)
            {
                followList[followerId].erase(it);
                break;
            }
        }
        
        return;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
