#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long qpow(long long a, long long n, long long mod){
    if (n == 1){
        return a;
    }
    else if (n % 2 == 1){
        return qpow(a, n-1, mod) * a % mod;
    }
    else{
        long long temp = qpow(a, n/2, mod) % mod;
        return temp * temp % mod;
    }
}


int main(){
    long long n;
    cin >> n;
    if (n == 1){
        // 1
        cout << 1 << endl;
        return 0;
    }
    if (n == 2){
        // 2
        cout << 2 << endl;
        return 0;
    }
    if (n == 3){
        // 3
        cout << 3 << endl;
        return 0;
    }
    if (n == 4){
        // 2+2
        cout << 4 << endl;
        return 0;
    }
    long long ans = n % 3;
    long long step = n / 3;
    if (ans == 1 && step > 1){
        ans = ans + 3;
        step--;
    }
    if (ans == 0) ans = 1;
    // 快速幂
    long long temp = qpow(3, step, 5218);
    ans = ans * temp % 5218;
    cout << ans << endl;
    return 0;
}

/*
数的潜能

问题描述：
将一个数N分为多个正整数之和，即N=a1+a2+a3+...+ak
将M=a1*a2*a3*...*ak定义为N的潜能
给定N，求它的潜能M
由于M可能过大，只需求M对5218取模的余数

输入格式：
输入共一行，为一个正整数N

输出格式：
输出共一行，为N的潜能M对5218取模的余数

样例输入：
10

样例输出：
36 (3+3+4)
*/