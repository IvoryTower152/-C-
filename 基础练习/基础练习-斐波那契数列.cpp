#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n <= 2){
        cout << 1 << endl;
        return 0;
    }
    vector<int> ans(n, 1);
    for (int i = 2; i < n; i++){
        ans[i] = (ans[i-2] + ans[i-1]) % 10007;
    }
    cout << ans[n-1] << endl;
    return 0;
}
