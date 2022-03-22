#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    //n*n数组
    vector< vector<int> > dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) cin >> dp[i][j];
    }
    for(int i = 1; i < n; i++){
        dp[0][i] += dp[0][i-1];
        dp[i][0] += dp[i-1][0];
    }
    //DP
    int ans = max(dp[0][n-1], dp[n-1][0]);
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
            if (dp[i][j] > ans) ans = dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}

/*
金币

问题描述：
有一个N*N的方格，每一个格子都有一些金币，只要站在格子里就能拿到里边的金币。
你站在最左上的格子里，每次可以从一个格子走到它右边或下边的格子里。
请问如何走才能拿走最多的金币。

输入格式：
第一行输入一个正整数n
以下n行描述该方格，金币数保证是不超过1000的正整数

输出格式：
能得到的最大金币数

输入样例：
3
1 3 3
2 2 2
3 1 2

样例输出：
11

这是其实是机器人走路问题的一个变种，也就是一个动态规划问题
由于我们只能向右或向下走，因此dp[i][j]来自于两种状态：dp[i-1][j]以及dp[i][j-1]
要求取最大金币数量，就需要比较两种状态的最大值，因此状态转移公式就是 dp[i][j]=max(dp[i-1][j],dp[i][j-1])+dp[i][j]
因为站着就能获得金币，所以是不断叠加的状态
最终dp[n][n]将会是金币最大的状态
*/