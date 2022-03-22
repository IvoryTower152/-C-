#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int nums;
    cin >> nums;
    vector<int> numList(nums, 0);
    for (int i = 0; i < numList.size(); i++){
        cin >> numList[i];
    }
    sort(numList.begin(), numList.end());
    for (int i = 0; i < numList.size(); i++){
        cout << numList[i];
        if (i != numList.size()-1) cout << ' ';
    }
    return 0;
}

/*
问题描述：
给定一个长度为n的数列，将这个数列按从小到大的顺序排列。 (1<=n<=200)

输入格式：
第一行为一个整数n
第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000

输出格式：
输出一行，按从小到大的顺序输出排序后的数列

输入样例：
5
8 3 6 4 9

样例输出：
3 4 6 8 9
*/