#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    while (step > 0){
        // (n * m) % p = n % p * m % p
        ans = ans % 5218 * 3;
        step--;
    }
    ans = ans % 5218;
    cout << ans << endl;
    return 0;
}
