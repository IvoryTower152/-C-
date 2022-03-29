#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ans = 0;

void loop(int x, int y, int& m, int& n){
    if(x == m && y == n){
        ans++;
        ans = ans % 1000000007;
        return;
    }
    else{
        if (x-2>=0 && y+1<=n){
            loop(x-2, y+1, m, n);
        }
        if (x+2<=m && y+1<=n){
            loop(x+2, y+1, m, n);
        }
        if (x-1>=0 && y+2<=n){
            loop(x-1, y+2, m, n);
        }
        if (x+1<=m && y+2<=n){
            loop(x+1, y+2, m, n);
        }
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    loop(0, 0, m, n);
    cout << ans << endl;
    return 0;
}

/*
问题描述：
在那个过河卒逃过了马的控制以超级超级多的走法走到终点之后，这匹马表示它不开心了
于是，终于有一天，它也过河了
由于过河马积累了许多的怨念，所以这次它过了河之后，再也没有什么东西可以限制它，它可以自由地在棋盘上奔驰
一开始，它在一个n行m列棋盘的左下角(1,1)的位置，它想要走到终点右上角(n,m)的位置
众所周知，马是要走日字格的，但这匹马不想走回头路，也就是说，它指挥朝向上的方向跳，不会网向下的方向跳
那么，马想从起点跳到终点，一共有多少种走法呢

输入格式：
第一行两个数n，m，表示一个n行m列的棋盘，起点为(1,1)，终点位于(n,m)

输出格式：
输出一行，一个数表示走法数，由于答案可能很大，故输出答案除以1000000007所得的余数

样例输入：4 4
样例输出：2
数据规模：n,m <= 100
*/