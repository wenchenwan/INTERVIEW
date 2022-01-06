/*
HJ37 统计每个月兔子的总数

*/


#include<iostream>
#include<vector>
using namespace std;
  int main(){
      int n;
      while(cin >> n){
          if(n == 1) cout << 1 << endl;
          if(n == 2) cout << 1 << endl; 
          if(n > 2){
              vector<int> f(n,0);
                f[0] = 1;
                f[1] = 1;
                for(int i=2;i<n;i++){
                    f[i] = f[i-1] + f[i-2];
                }
                cout << f[n-1] << endl;
          }
          
      }


      return 0;
  }