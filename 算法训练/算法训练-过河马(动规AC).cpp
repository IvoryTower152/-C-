#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector< vector<long> > ans(105, vector<long>(105, 0));
    ans[1][2] = 1;
    ans[2][1] = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i==1&&j==2) continue;
            if (i==2&&j==1) continue;
            if (i-2>=0&&j-1>=0){
                ans[i][j] += (ans[i-2][j-1]%1000000007);
                ans[i][j] %= 1000000007;
            }
            if (i-1>=0&&j-2>=0){
                ans[i][j] += (ans[i-1][j-2]%1000000007);
                ans[i][j] %= 1000000007;
            }
            if (i-2>=0&&j+1<m){
                ans[i][j] += (ans[i-2][j+1]%1000000007);
                ans[i][j] %= 1000000007;
            }
            if (i-1>=0&&j+2<m){
                ans[i][j] += (ans[i-1][j+2]%1000000007);
                ans[i][j] %= 1000000007;
            }
        }
    }
    cout << ans[n-1][m-1] << endl;
    return 0;
}
