#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n == 1) cout<<1<<endl;
    if (n >= 2){
        cout<<1<<endl;
        cout<<1<<' '<<1<<endl;
    }
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(1);
    n -= 2;
    while(n>0){
        vector<int> temp;
        temp.push_back(ans[0]);
        for (int i = 0; i < ans.size()-1; i++) temp.push_back(ans[i] + ans[i+1]);
        temp.push_back(ans[ans.size()-1]);
        for(int i = 0; i < temp.size(); i++){
            cout << temp[i];
            if (i != temp.size()-1){
                cout << ' ';
            }
            else{
                cout<<endl;
            }
        }
        ans = temp;
        n -= 1;
    }
    return 0;
}
