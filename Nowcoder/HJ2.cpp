/**
 * HJ2 计算某字符出现次数
 * @file HJ2.cpp
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
    char c;
    while(cin)
    cin >> s; 
    cin >> c;
    if('a'<=c && c <= 'z'){
        c = c - 'a' + 'A';
    }
    int count = 0;
    char ch;
    while((ch = getchar()) != '\n'){
        if('a'<=ch && ch <= 'z'){
            ch = ch - 'a' + 'A';
        }        
        if(ch == c){
            ++count;
        }

    }
    cout << count << endl;

    while(1);
    return 0;
}