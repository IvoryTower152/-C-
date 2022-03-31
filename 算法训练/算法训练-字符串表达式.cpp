#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string source;
    cin >> source;
    vector<int> nums;
    vector<char> opt;
    vector<int> cell;
    for(int i = 0; i < source.length(); i++){
        if(source[i]=='+' || source[i]=='-' || source[i]=='='){
            int num = 0;
            for(int j = 0; j < cell.size(); j++) num = num * 10 + cell[j];
            nums.push_back(num);
            if(source[i] != '=') opt.push_back(source[i]);
            cell.clear();
        }
        else{
            cell.push_back(source[i] - '0');
        }
    }
    int ans = nums[0];
    for(int i = 0; i < opt.size(); i++){
        if(opt[i]=='+') ans += nums[i+1];
        if(opt[i]=='-') ans -= nums[i+1];
    }
    cout<<ans<<endl;
    return 0;
}

/*
问题描述：
编写一个字符串表达式求解程序，输入一个字符串表达式，返回它的结果。
表达式的长度不会超过100，表达式最少有一项，且以等号'='结束。
表达式中只包含解法和减法，且运算均在整数范围之内。

样例输入：
2+2345+913-3=
样例输出：
3257
*/