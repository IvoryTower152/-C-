#include <iostream>

using namespace std;

int main(){
    for (int i = 1; i < 10; i++){
        for (int j = 0; j < 10; j++){
            int ans = i * 1000 + j * 100 + j * 10 + i;
            cout << ans << endl;
        }
    }
    return 0;
}
