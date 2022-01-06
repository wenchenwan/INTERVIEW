/**
 * @file HJ21.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-24
 * 
 * @copyright Copyright (c) 2021
 * 
 * HJ21 简单密码
 */

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
 
int main() {
    string s;
    unordered_map<char, char> map;
    map['a'] = '2'; map['b'] = '2'; map['c'] = '2';
    map['d'] = '3'; map['e'] = '3'; map['f'] = '3';
    map['g'] = '4'; map['h'] = '4'; map['i'] = '4';
    map['j'] = '5'; map['k'] = '5'; map['l'] = '5';
    map['m'] = '6'; map['n'] = '6'; map['o'] = '6';
    map['p'] = '7'; map['q'] = '7'; map['r'] = '7'; map['s'] = '7';
    map['t'] = '8'; map['u'] = '8'; map['v'] = '8';
    map['w'] = '9'; map['x'] = '9'; map['y'] = '9'; map['z'] = '9';


    while(getline(cin,s)){
        int len = s.size();
        for(int i=0;i<len;i++){
            if(s[i] >= 'A' && s[i] < 'Z'){
                s[i] = s[i] - 'A' + 'a' + 1;
            }else if(s[i] == 'Z'){
                s[i] = 'a';
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] = map[s[i]];
            }
        }
        cout << s;
    }

    

    return 0;
}