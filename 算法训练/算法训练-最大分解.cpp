#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    while(n > 1){
        for (int i = n-1; i >= 1; i--){
            if(n % i == 0){
                ans += i;
                n = i;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
问题描述：
给出一个正整数n，求一个和的最大序列a0、a1、a2...ap
满足n=a0>a1>a2...>ap，且ai+1是ai的约数，输出a1+a2+...+ap的最大值

输入格式：
输入一行，包含正整数n

输出格式：
输出一个正整数，表示最大的序列和

样例输入：10
样例输出：6 (a1=10,a2=5,a3=1 故5+1=6)
数据规模：1<n<=10^6

本样例说明，当约数达到1时，序列就应该终止，因此，不断由最大数开始遍历，就能达到最大序列和
*/