/**
 * HJ4 字符串分隔
 * @file HJ4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"iostream"

using namespace std;

int main(){
    string s;
    while(cin >> s){
        if(s.size() < 8){
            cout << s << string(8-s.size(),'0') << endl;
        }
        if(s.size() == 8){
            cout << s << endl;
        }
        if(s.size() > 8){
            while (s.size() > 8){
                cout << s.substr(0,8) << endl;
                s = s.substr(8,s.size()-8);
            }
            cout << s << string(8-s.size(),'0') << endl;
        } 
    }


    return 0;
}