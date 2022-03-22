#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

double strategy = 0;
vector<int> cell;

void loop(int n, int m, vector<int>& state){
    if(cell.size() == m){
        bool is_ans = true;
        for (int i = 0; i < n; i++){
            if(state[i]==0){
                is_ans = false;
                break;
            }
        }
        if (is_ans) strategy++;
        return;
    }
    for (int i = 0; i < n; i++){
        cell.push_back(i);
        state[i]++;
        loop(n, m, state);
        cell.pop_back();
        state[i]--;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> state(n, 0);
    loop(n, m, state);
    double sum = 1;
    for (int i = 0; i < m; i++){
        sum = sum * n;
    }
    double ans = strategy / sum;
    printf("%.4f", ans);
    return 0;
}
