#include <iostream>
#include <vector>

using namespace std;

int ans = 1;
vector<int> cell;

void loop(int start, vector<bool>& state, int deep){
    if (cell.size() == deep){
        ans++;
        return;
    }
    for(int i = start; i < state.size(); i++){
        for(int j = 0; j < state.size(); j++){
            if (state[j]){
                cell.push_back(j);
                state[j] = false;
                //进入下一行放入新的小车，这样可以放置重复的排列出现
                loop(i+1, state, deep);
                cell.pop_back();
                state[j] = true;
            }
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<bool> state(n, true);
    for (int deep = 1; deep <= n; deep++){
        loop(0, state, deep);
    }
    cout << ans << endl;
    return 0;
}

/*
问题描述：
在n*n的棋盘中，每个格子中至多放置一个车，且要保证任何两个车不能互相攻击，有多少种不同的放法(车与车没有差别)

输入格式：
包含一个正整数n

输出格式：
一个整数，表示放置车的方法数

样例输入： 2
样例输出： 7 (解释：不放车有1种方法，放1辆车有4种方法，2辆车有2种方法)

这道题天克不会象棋的人，车的规则是走直线，也就是说，放下车后，车所在的那一行和那一列不能有别的车
同时本题对车的数量没有限制，可知在n*n的棋盘中，车的上限应该是n，下限应该是0
使用回溯搜索方法就可以完成，是一个DFS操作，我们可以设置深度，应该是1-n的情况均考虑，初始化直接用1就可以考虑到0车的情况
车数==n时，所有的行都能占满不用考虑行的选择
车数<n时，就需要考虑到行的选择，使用全排列思想得到所有的行数组合就可以减少搜索次数同时去重
*/