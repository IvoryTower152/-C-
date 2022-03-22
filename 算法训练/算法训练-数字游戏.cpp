#include <iostream>
#include <vector>

using namespace std;

bool is_find = false;
vector<int> solution;
vector<int> cell;
void loop(int sum, int n, vector<bool>& state, vector<int>& ans){
    if (cell.size() == ans.size() && !is_find){
        int cur = 0;
        for(int i = 0; i < ans.size(); i++){
            cur += cell[i] * ans[i];
        }
        if (sum == cur){
            solution = cell;
            is_find = true;
        }
        return;
    }
    if(!is_find){
        for(int i = 1; i <= n; i++){
            if (state[i]){
                state[i] = false;
                cell.push_back(i);
                loop(sum, n, state, ans);
                state[i] = true;
                cell.pop_back();
            }
        }
    }
    return;
}

int main(){
    int n, sum;
    cin >> n >> sum;
    if (n == 1){
        cout << sum << endl;
        return 0;
    }
    if (n == 2){
        cout << 1 << ' ' << 2 << endl;
        return 0;
    }
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(1);
    //通过杨辉三角形获得系数
    for(int i = 3; i <= n; i++){
        vector<int> temp;
        temp.push_back(1);
        for(int j = 0; j < ans.size()-1; j++) temp.push_back(ans[j]+ans[j+1]);
        temp.push_back(1);
        ans = temp;
    }
    //回溯搜索
    vector<bool> state(n+1, true);
    loop(sum, n, state, ans);
    if (is_find){
        for (int i = 0; i < n; i++){
            cout << solution[i];
            if (i != n-1) cout << ' ';
        }
    }
    return 0;
}

/*
数字游戏

问题描述：
给定一个1-n的排列(指数列一定由1-n组成且无重复元素)
每次将相邻的两个数相加，得到新序列，再对新序列重复这样的操作
每一次得到的新序列都会比上一次序列的长度少1，最终只剩下1个数字
如：3 1 2 4 > 4 3 6 > 7 9 > 16
如果现在知道n以及得到的最后数字sum，请求出最初的序列
若有多种答案，则输出字典序最小的那个，数据保证有解(结果发现用例里有无解的)

输入格式：1行2个正整数，表示n以及sum

输出格式：一个1-n的排列

样例输入：4 16

样例输出：3 1 2 4

Note：1<=n<=10

首先，由于数列的规模不大，暴力搜索是可行的
也可以尝试先模拟一下过程：
1、n=2，显然只能是1、2
2、n=3，如果用a1、a2、a3表示变量，按照规则相加的结果是a1+2a2+a3
3、n=4，如果用a1、a2、a3、a4表示变量，按照规则相加的结果是a1+3a2+3a3+a4
4、n=5，结果为a1+4a2+6a3+4a4+a5
看看系数：
11
121
1331
14641
......
这其实是一个杨辉三角形，也就是说，在已知数列长度的情况下，各元素的系数可以通过杨辉三角形推断得到
这样直接得到系数可以简化运算流程，再搭配上回溯搜索全排列就可以很快得到字典序最小的解
需要注意的是要处理无解的情况
*/