/**
 * 1078. Bigram 分词
 * 
 * @file Leecode1078.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include"vector"
#include"string"
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        int n = text.size();
        string target = first+' '+second;
        for(int i=0;i<n;i++){
            if(i==1) target = " " + target;
            int j = i,k = 0;
            while(text[j] == target[k] && k<target.size() && j<n){
                j++;
                k++;
            }
            if(k==target.size() && text[j++] == ' '){
                string temp = "";
                while(text[j] != ' ' && j<n){
                    temp += text[j];
                    j++;
                }
                res.push_back(temp);
            }
        }

        return res;
    }
};