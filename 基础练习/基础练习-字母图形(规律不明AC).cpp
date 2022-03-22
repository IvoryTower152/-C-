#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    if (m == 1){
        for (int i = 0; i < n; i++){
            char ans_ = 'A' + i;
            cout << ans_ << endl;
        }
        return 0;
    }
    vector<char> ans(m, 'A');
    for (int i = 0; i < m; i++){
        ans[i] = ans[i] + i;
        cout << ans[i];
    }
    cout<<endl;
    int i = 1;
    while (i < n){
        for (int j = 0; j < i; j++) ans[j] = ans[j] + 1;
        for (int j = i; j < m; j++) ans[j] = ans[j] - 1;
        for (int j = 0; j < m; j++){
            cout << ans[j];
        }
        cout<<endl;
        i += 1;
    }
    return 0;
}
