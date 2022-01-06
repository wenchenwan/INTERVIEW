/**
 * 846. 一手顺子
 * @file Leetcode846.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream> 
#include<vector>
#include "queue"
#include"map"
#include"unordered_map"
#include"algorithm"

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        unordered_map<int,int> mp;
        for(int& h:hand){
            ++mp[h];
        }
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;++i){
            if(mp[hand[i]]==0) continue;
            for(int j=0;j<groupSize;++j){
                if(mp[hand[i]+j]==0){
                    return false;
                }else {
                    --mp[hand[i]+j];
                }
            }
        }
        
        return true;
    }
};