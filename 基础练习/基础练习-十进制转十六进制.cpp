#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<char> cands;
    cands.push_back('0');
    cands.push_back('1');
    cands.push_back('2');
    cands.push_back('3');
    cands.push_back('4');
    cands.push_back('5');
    cands.push_back('6');
    cands.push_back('7');
    cands.push_back('8');
    cands.push_back('9');
    cands.push_back('A');
    cands.push_back('B');
    cands.push_back('C');
    cands.push_back('D');
    cands.push_back('E');
    cands.push_back('F');

    long long source;
    cin >> source;
    if (source == 0) cout << "0";
    string target = "";
    while (source > 0){
        target = target + cands[source % 16];
        source = source / 16;
    }
    reverse(target.begin(), target.end());
    cout << target;
    return 0;
}

/*
问题描述：
十六进制是在程序设计时经常要使用的一种整数的表示方式
它有0、1、2、3、4、5、6、7、8、9、A、B、C、D、E、F共16个符号，分别表示十进制的0-15
给出一个非负整数，将它表示成十六进制的形式

输入格式：
输入包含一个非负整数a，表示要转换的数

输出格式：
输出所给整数的16进制形式

样例输入：
30

样例输出：
1E
*/
