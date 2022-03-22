#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> source(n, 0);
    for (int i = 0; i < n; i++) cin >> source[i];
    int target;
    cin >> target;
    int ans = -1;
    for (int i = 0; i < n; i++){
        if (source[i] == target){
            ans = i + 1;
        break;
        }
    }
    cout << ans << endl;
    return 0;
}
