#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 模拟好过程即可, 限制在5位和6位使问题变得简单, 代码可以更加精简 */

int main(){
    int source;
    cin >> source;
    vector<int> target;
    if (source % 2 == 0){
        if (source > 44){
            // 99899
            int cand = source / 2;
            for (int i = 1; i <= 9; i++){
                for (int j = 0; j <= 9; j++){
                        if (cand - i - j <= 9 && cand - i - j >= 0) target.push_back(i*100000+j*10000+(cand-i-j)*1000+(cand-i-j)*100+j*10+i);
                }
            }
        }
        else if (source == 44){
            target.push_back(99899);
            int cand = source / 2;
            for (int i = 1; i <= 9; i++){
                for (int j = 0; j <= 9; j++){
                        if (cand - i - j <= 9 && cand - i - j >= 0) target.push_back(i*100000+j*10000+(cand-i-j)*1000+(cand-i-j)*100+j*10+i);
                }
            }
        }
        else{
            if (source - 0 >= 2){
                int cand5 = (source-0) / 2;
                for (int i = 1; i <= 9; i++){
                    if (cand5 - i <= 9 && cand5 - i >= 0) target.push_back(i*10000+(cand5-i)*1000+0*100+(cand5-i)*10+i);
                }
            }
            if (source - 2 >= 2){
                int cand5 = (source-2) / 2;
                for (int i = 1; i <= 9; i++){
                    if (cand5 - i <= 9 && cand5 - i >= 0) target.push_back(i*10000+(cand5-i)*1000+2*100+(cand5-i)*10+i);
                }
            }
            if (source - 4 >= 2){
                int cand5 = (source-4) / 2;
                for (int i = 1; i <= 9; i++){
                    if (cand5 - i <= 9 && cand5 - i >= 0) target.push_back(i*10000+(cand5-i)*1000+4*100+(cand5-i)*10+i);
                }
            }
            if (source - 6 >= 2){
                int cand5 = (source-6) / 2;
                for (int i = 1; i <= 9; i++){
                    if (cand5 - i <= 9 && cand5 - i >= 0) target.push_back(i*10000+(cand5-i)*1000+6*100+(cand5-i)*10+i);
                }
            }
            if (source - 8 >= 2){
                int cand5 = (source-8) / 2;
                for (int i = 1; i <= 9; i++){
                    if (cand5 - i <= 9 && cand5 - i >= 0) target.push_back(i*10000+(cand5-i)*1000+8*100+(cand5-i)*10+i);
                }
            }
            int cand6 = source / 2;
            for (int i = 1; i <= 9; i++){
                for (int j = 0; j <= 9; j++){
                        if (cand6 - i - j <= 9 && cand6 - i - j>= 0) target.push_back(i*100000+j*10000+(cand6-i-j)*1000+(cand6-i-j)*100+j*10+i);
                }
            }
        }
    }
    else{
        if (source - 1 >= 2){
            int cand5 = (source-1) / 2;
            for (int i = 1; i <= 9; i++){
                if (cand5 - i <= 9 && cand5 - i >= 0) target.push_back(i*10000+(cand5-i)*1000+1*100+(cand5-i)*10+i);
            }
        }
        if (source - 3 >= 2){
            int cand5 = (source-3) / 2;
            for (int i = 1; i <= 9; i++){
                if (cand5 - i <= 9 && cand5 - i >= 0) target.push_back(i*10000+(cand5-i)*1000+3*100+(cand5-i)*10+i);
            }
        }
        if (source - 5 >= 2){
            int cand5 = (source-5) / 2;
            for (int i = 1; i <= 9; i++){
                if (cand5 - i <= 9 && cand5 - i >= 0) target.push_back(i*10000+(cand5-i)*1000+5*100+(cand5-i)*10+i);
            }
        }
        if (source - 7 >= 2){
            int cand5 = (source-7) / 2;
            for (int i = 1; i <= 9; i++){
                if (cand5 - i <= 9 && cand5 - i >= 0) target.push_back(i*10000+(cand5-i)*1000+7*100+(cand5-i)*10+i);
            }
        }
        if (source - 9 >= 2){
            int cand5 = (source-9) / 2;
            for (int i = 1; i <= 9; i++){
                if (cand5 - i <= 9 && cand5 - i >= 0) target.push_back(i*10000+(cand5-i)*1000+9*100+(cand5-i)*10+i);
            }
        }
    }
    sort(target.begin(), target.end());
    for (int i = 0; i < target.size(); i++){
        cout << target[i] << endl;
    }
    return 0;
}
