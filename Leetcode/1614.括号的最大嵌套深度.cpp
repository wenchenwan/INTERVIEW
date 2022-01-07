/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start

#include "iostream"
#include "stack"
#include "string"
#include "algorithm"
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        stack<char> st;
        for(char& ch : s){
            if(ch == '('){
                st.push('(');
                int n = st.size();
                res = max(res,n);
                
            }
            if(ch == ')'){
                st.pop();
            }
        }

        return res; 
    }
};
// @lc code=end

