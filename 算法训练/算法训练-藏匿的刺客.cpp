#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool camp(vector<int>& a, vector<int>& b){
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int main(){
    int n;
    cin >> n;
    vector< vector<int> > table(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++){
        cin >> table[i][0] >> table[i][1];
    }
    //首先要对这些区间进行排序
    sort(table.begin(), table.end(), camp);
    //搜索区间
    vector<int> cover = table[0];
    int ans = 1;
    for (int i = 1; i < n; i++){
        if (table[i][0] >= cover[0] && table[i][0] <= cover[1]){
            cover[0] = table[i][0];
            cover[1] = min(table[i][1], cover[1]);
        }
        else{
            ans++;
            cover = table[i];
        }
    }
    cout << ans << endl;
    return 0;
}

/*
问题描述：
强大的kAc建立了强大的帝国，但人民深受其学霸及23文化的压迫，于是勇敢的鹏决心反抗
kAc帝国防守森严，鹏带领着小伙伴躲在城外的草堆叶子中，称为叶子鹏
kAc帝国派出的n个看守员都发现了这一问题，第i个人会告诉你在第li个草堆到第ri个草堆中有人
要求你计算出所有草堆中最少的人数

输入格式：
第一行1个数字n，接下来2到n+1行，每行两个数，表示li以及ri

输出格式：
输出一个数，表示最少人数

样例输入：
5
2 4
1 3
5 7
1 8
8 8

样例输出：3 (表示草堆中最少有3人)

数据规模：所有数字均在int表示范围内

这道题看明白题目的意思就会变得比较清晰
每个探子会告知一个范围内的草堆有人，其实这就是一个区间，找最少的人数就是找最少的不重合子区间
以样例为例，首先我们需要重新对区间由小到大排序，使用sort()以及自定义比较函数就可以完成，得到：
(1,3) (1,8) (2,4) (5,7) (8,8)
寻找这些区间能够达到的最少不重合子区间
(1,3)和(1,8)有人，(1,3)被(1,8)包含，那这个范围就可以缩小到(1,3)有人，得到新的区间：
(1,3) (2,4) (5,7) (8,8)
(1,3)和(2,4)有人，而这两个区间有交集，可以缩小范围到(2,3)中有人
(2,3) (5,7) (8,8)
我们发现剩余的区间均没有交集，因此这就是我们的最终解，也就是最少有3人(3个不重合子区间)
清楚了搜索思路我们就可以完成编程
始终维护一个cover数组来存储当前的子区间，进行是否相交的判断即可
*/