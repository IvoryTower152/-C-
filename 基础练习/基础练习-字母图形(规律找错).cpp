#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    if (m == 1){
        for (int i = 0; i < n; i++) cout << 'A' << endl;
        return 0;
    }
    vector<char> ans(m + (m - 2), 'A');
    for (int i = 0; i < m; i++){
        ans[i] += i;
    }
    for (int i = m; i < ans.size(); i++){
        ans[i] = ans[i-1] - 1;
    }
    int start = 0;
    for (int i = 0; i < n; i++){
        int step = m;
        int idx = start;
        while(step > 0){
            cout << ans[idx];
            idx = idx+1 == ans.size() ? 0 : idx+1;
            step--;
        }
        cout << endl;
        start = start-1 == -1 ? ans.size()-1 : start-1;
    }
    return 0;
}

/*
ABCD
BABC
CBAB
DCBA
CDCB
BCDC
ABCD
环状序列: ABCDCB
*/
