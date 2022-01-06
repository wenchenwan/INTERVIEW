/**
 * HJ5 进制转换
 * @file HJ5.cpp
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
    int res;
    string s;
    while (cin >> s)
    {
        res = 0;
        for(int i=2;i<s.size();i++){
            if('A'<=s[i] && s[i]<='F'){
                res = res*16 + s[i] - 'A' + 10;
            }else{
                res = res*16 + s[i]-'0';
            }
        }
        cout << res << endl;
    }
    

    return 0;
}