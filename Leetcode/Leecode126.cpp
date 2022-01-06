/**
 * 126. 单词接龙 II
 * 
 * @file Leecode126.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream> 
#include<vector>
#include "queue"
#include "unordered_map"
#include "unordered_set"
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict;
        for(int i=0;i<wordList.size();++i){
            dict.insert(wordList[i]);
        }
        if(!dict.count(endWord)) return ans;

        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{beginWord},q2{endWord};
        unordered_map<string,vector<string>> next;

        bool revese = false,found = false;
        while(!q1.empty()){
            unordered_set<string> q;
            for(auto& w:q1){
                string s = w;
                for(int i=0;i<s.size();++i){
                    char ch = s[i];//暂时保存s[i]
                    for(int j=0;j<26;++j){//改变每一个字符26次
                        s[i] = j+'a';
                        //q1{beginWord},q2{endWord};
                        if(q2.count(s)){
                            revese ? next[s].push_back(w) : next[w].push_back(s);
                            found = true;
                        }
                        if(dict.count(s)){
                            revese ? next[s].push_back(w) : next[w].push_back(s);
                            q.insert(s);
                        }
                    }

                    s[i] = ch;
                }
            }

            if(found) break;

            for(auto& w : q){
                dict.erase(w);
            }

            if(q.size() <= q2.size()){
                q1 = q;
            }else{
                revese = !revese;
                q1 = q2;
                q2 = q;
            }
        }
        if(found){
            vector<string> path = {beginWord};
            backtracking(beginWord,endWord,next,path,ans);
        }

        return ans;

    }

    void backtracking(const string &src, const string &dst, unordered_map<string, vector<string>> &next, vector<string> &path, vector<vector<string>> &ans) { 
        if (src == dst) {
            ans.push_back(path); 
            return;
        }
        for (const auto &s: next[src]) { 
            path.push_back(s); 
            backtracking(s, dst, next, path, ans); 
            path.pop_back();
        }
    }

};