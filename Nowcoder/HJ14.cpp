#include<iostream>
#include<vector>
#include "algorithm"
using namespace std;

int main(){
    vector<string> vec;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        vec.push_back(s);
    }
    sort(vec.begin(),vec.end());

    for(auto & c : vec){
        cout << c << endl;
    }
    

    return 0;
}