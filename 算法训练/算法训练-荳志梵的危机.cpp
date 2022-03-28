#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long n;
    //n一定是偶数
    cin >> n;
    vector<long long> table(n, 0);
    for (int i = 0; i < n; i++) cin >> table[i];
    long long ans = 0, left = 0, right = n-1;
    while(left < right){
        //DZF先手
        ans += max(table[left], table[right]);
        if(table[left]>=table[right]){
            left++;
        }
        else{
            right--;
        }
        //小妹后手
        if(table[left]>=table[right]){
            left++;
        }
        else{
            right--;
        }
    }
    cout << ans << endl;
    return 0;
}

/*
问题描述：
逗志芃又一次面临了危机。逗志芃的妹子是个聪明绝顶的人，相比之下逗志芃就很菜。
现在她妹子要和他玩一个游戏，每个游戏是这样的：一共有n个数(n是偶数)写成一行，然后两个人轮流取数，
每次只能从最前面或者最后面取走一个数，取完则游戏结束，之后每个人取走的数的和就是每个人的得分。
由于逗志芃妹子很厉害，但他又不想输，所以只能找到你了，你要告诉他最多可以得到多少分。
(妹子不会犯错，每次的策略必然是最优的，而且逗志芃是先手)

输入格式：
第一行1个数n，表示有n个数
第二行就是进行游戏的n个数

输出格式：
一个数，最高得分

数据规模和约定：0<n,m<=1000，每个数不超过10000

本题未AC
主要是逗志芃如果按照最优策略每次都从两边取最大的，可能会忽略未来会遇到的大数
*/