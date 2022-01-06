/**
 * 
 * @file HJ6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"iostream"
#include"math.h"
using namespace std;
// int  main(){

//     int n;
//     while(cin >> n){
        
        
//         while(n!=1){
//             int m = n;
//             int i = 2;
//             while (i <= sqrt(m))
//             {
//                 if(n%i == 0){
//                     n = n/i;
//                     cout << i << ' ';
//                 }else{
//                     i++;
//                 }
//             }
//             if(m == n) cout << m;
//         }
//     }

//     while(1);

//     return 0;    
// }
/* 超时 */

int main() 
{
    long n, old_n=0; 
    cin >> n;
    while (n != 1)
    {
        for (int i = 2; i <=sqrt(n); i++) //不要忽视“=”符号，很重要！
        {
            old_n = n;
            while (n % i == 0) {
                cout << i << " ";
                n /= i;
            }
        }
        if (old_n == n) 
        {
            cout << n << ' ';
            break;
        }
    }
return 0;
}