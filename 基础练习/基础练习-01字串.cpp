#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> ans;
vector<char> cell;

void loop(int& num){
    if (cell.size() == num){
        string ans_ = "";
        for (int i = 0; i < num; i++) ans_ += cell[i];
        ans.push_back(ans_);
        return;
    }

    cell.push_back('0');
    loop(num);
    cell.pop_back();

    cell.push_back('1');
    loop(num);
    cell.pop_back();

    return;
}

int main(){
    int num = 5;
    loop(num);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    return 0;
}
