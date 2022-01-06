/*
HJ50 四则运算 
https://www.nowcoder.com/practice/9999764a61484d819056f807d2a91f1e?tpId=37&&tqId=21273&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
*/

#include<iostream>

using namespace std;
int caulate(string s);
int main(){
    string s;
    while(cin >> s){
        cout << caulate(s) << endl;
    }
    return 0;
}
bool isDigit(char c){
    if(c >= '0' && c<= '9'){
        return true;
    }
    return false;
}
int caulate(string s){
    int n = s.size();
    int num = 0;
    int curRes = 0;
    int res = 0;
    char op = '+';
    for(int i=0;i<n;i++){
        char c = s[i];
        if(isDigit(c)){
            num = num * 10 + c - '0';
        }else if(c == '(' || c == '{' || c == '['){
            int j=i,cnt = 0;
            for(;i<n;++i){
                if(s[i] == '{' || s[i] == '[' || s[i]=='(') ++cnt;
                if(s[i] == '}' || s[i] == ']' || s[i]==')') --cnt;
                if(cnt == 0) break;
            }
            
            num = caulate(s.substr(j+1,i-j-1));
        }
        
        if(c=='+' || c == '-' || c == '/' || c == '*' || i == n-1){
            switch(op){
                case '+': curRes += num;break;
                case '-': curRes -= num;break;
                case '*': curRes *= num;break;
                case '/': curRes /= num;break;
            }
            if(c=='+' || c=='-' || i == n-1){
                res += curRes;
                curRes = 0;
            }
            
            op = c;
            num = 0;
        }
    }
    return res;
}