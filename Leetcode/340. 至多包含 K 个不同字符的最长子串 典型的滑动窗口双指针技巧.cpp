#include "iostream"
#include "stack"
#include "string"
#include "algorithm"
#include "unordered_map"
#include "vector"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0;
        int n = s.size();
        unordered_map<char,int> hashmap;
        for(int i=0,j=0;i<n;++i){
            hashmap[s[j]]++;
            while(i < n && hashmap.size() > k){
                hashmap[s[i]]--;
                if(hashmap.count(s[i]) && hashmap[s[i]] == 0) hashmap.erase(s[i]);
                ++i;
            }

            res = max(res,j-i+1);
        }

        return res;
    }
};