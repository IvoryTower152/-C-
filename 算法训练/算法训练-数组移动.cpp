#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> opts(m, 0);
    for(int i = 0; i < m; i++) cin >> opts[i];
    queue<int> que;
    for(int i = 1; i <= n; i++){
        que.push(i);
    }
    for(int i = 0; i < m; i++){
        int top = que.front();
        while(top != opts[i]){
            que.pop();
            que.push(top);
            top = que.front();
        }
        que.pop();
        que.push(top);
    }
    for(int i = 0; i < n; i++){
        cout << que.front();
        que.pop();
        if(i != n-1){
            cout << ' ';
        }
        else{
            cout << endl;
        }
    }
    return 0;
}

/*
问题描述：
初始数组A[N]中为1,2,...,N共计N个数字
现要进行M次操作，每次操作给定一个数字i，记其在数组中的位置Bi，将A[1]...A[Bi]移到数组末尾

输入格式：
输入的第一行包含两个整数N，M，接下来M行，每行一个正整数，表示给定的数字i

输出格式：
一行，输出M次操作后的A数组

样例输入：
5 2
3
2

样例输出：
3 4 5 1 2

其实是考察队列这一数据结构的利用
*/