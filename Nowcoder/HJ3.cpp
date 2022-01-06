/**
 * HJ3 明明的随机数
 * @file HJ3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
using namespace std;
int main() {
    int N, n;
    while (cin >> N) {
        int a[1001] = { 0 };
        while (N--) {
            cin >> n;
            a[n] = 1;
        }
        for (int i = 0; i < 1001; i++)
            if (a[i])
                cout << i << endl;
    }
    return 0;
}