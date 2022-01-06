/*
1705. 吃苹果的最大数目
有一棵特殊的苹果树，一连 n 天，每天都可以长出若干个苹果。在第 i 天，树上会长出 apples[i] 个苹果，这些苹果将会在 days[i] 天后（也就是说，第 i + days[i] 天时）腐烂，变得无法食用。也可能有那么几天，树上不会长出新的苹果，此时用 apples[i] == 0 且 days[i] == 0 表示。

你打算每天 最多 吃一个苹果来保证营养均衡。注意，你可以在这 n 天之后继续吃苹果。

给你两个长度为 n 的整数数组 days 和 apples ，返回你可以吃掉的苹果的最大数目。

 

示例 1：

输入：apples = [1,2,3,5,2], days = [3,2,1,4,2]
输出：7
解释：你可以吃掉 7 个苹果：
- 第一天，你吃掉第一天长出来的苹果。
- 第二天，你吃掉一个第二天长出来的苹果。
- 第三天，你吃掉一个第二天长出来的苹果。过了这一天，第三天长出来的苹果就已经腐烂了。
- 第四天到第七天，你吃的都是第四天长出来的苹果。
示例 2：

输入：apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
输出：5
解释：你可以吃掉 5 个苹果：
- 第一天到第三天，你吃的都是第一天长出来的苹果。
- 第四天和第五天不吃苹果。
- 第六天和第七天，你吃的都是第六天长出来的苹果。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-eaten-apples
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



#include<iostream> 
#include<vector>
#include "queue"
using namespace std;

class Solution {
public:
struct cmp{
    bool operator()(pair<int,int> a,pair<int,int> b){
        if(a.second > b.second){
            return true;
        }
        return false;
    }
};
    int eatenApples(vector<int>& apples, vector<int>& days) {
        vector<pair<int,int>> vec;
        int res = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> que;
        int n = apples.size();
        int i=1;
        int k=1;
        while(!que.empty() || k<=n){

            if(k <= n){
                que.push({apples[i-1],i+days[i-1]});
                k++;
            }
            pair<int,int> temp = que.top();
            que.pop();
            while((temp.first <= 0 || temp.second <= i)){
                if(que.empty()) break;
                temp = que.top();
                que.pop();
            }
            
            if(temp.first > 0 && temp.second > i){
                res++;
                temp.first--;
                if(temp.first > 0 && temp.second > i+1)que.push(temp);    
            }
            i++;
        }
        
            
        return res;
    }
};




int main(){
    vector<int> a = {1,2,3,5,2};
    vector<int> b = {1,2,1,4,2};
    Solution s1;
    cout << s1.eatenApples(a,b) << endl;

    //while(1);
    
    return 0;
}