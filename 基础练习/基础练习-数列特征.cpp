#include <iostream>

using namespace std;

int main(){
    int sum = 0, max_ = -999999, min_ = 999999;
    int n, cur;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> cur;
        if (max_ < cur) max_ = cur;
        if (min_ > cur) min_ = cur;
        sum += cur;
    }
    cout << max_ << endl;
    cout << min_ << endl;
    cout << sum << endl;
    return 0;
}
