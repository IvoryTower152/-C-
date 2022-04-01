#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<bool> student(n, true);
    vector< vector<int> > opt;
    for(int i = 0; i < n - 1; i++){
        vector<int> opt_(2, 0);
        cin >> opt_[0] >> opt_[1];
        opt.push_back(opt_);
    }

    for(int i = 0; i < n - 1; i++){
        int start = opt[i][0], step = opt[i][1];
        while(step > 0){
            start++;
            if(start >= n) start -= n;
            if(student[start] == false){
                continue;
            }
            else{
                step--;
            }
        }
        student[start] = false;
    }
    //唯一true的就是2255
    for(int i = 0; i < n; i++){
        if(student[i]) cout << i << endl;
    }

    //特殊法：其实最后一次操作只会剩下2个人, 一般操作者应该就是2255
    //不过要考虑操作操作步数, 但大部分答案应该是对的
    return 0;
}

/*
问题描述：
腿铮找2255有点事，但2255太丑了，所以腿铮不知道他的长相。
正愁不知道到如何找他的时候，他突然看见计33班围成了一个圈在领微积分试卷。
计33班有n个人，其中班长编号为0，其余同学依次按顺时针方向编号。
只听见计33小导说“x号同学顺时针方向往后数的第k个的神犇出列（不包括x号同学），领取满分试卷！”。
剩下的人继续围成一个小圈。这样一个过程持续了n-1次，
那么显然，最后只剩下了一个人。
众所周知，2255是个大傻子，门门挂科，不符合满分试卷这一前提条件。通过这样一个过程，腿铮终于找到了2255并血虐了他。
求2255的编号是多少。

输入格式：
第一行一个n，表示计33班的人数。
接下来n-1行，表示小导说话中的x和k。

输出格式：
一个数字，表示2255的编号。

样例输入：
3
1 1
0 1

样例输出：
0
*/