//
//  375-Guess Number Higher or Lower II.cpp
//  leecode
//
//  Created by lixiangqian on 17/2/3.
//  Copyright © 2017年 lixiangqian. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <stdlib.h>

using namespace std;
int dp(vector<vector<int>> & tes, int start, int end){
    int count = INT_MAX;
    if (start >= end) {
        return 0;
    }else if(tes[start][end]!=0){
        return tes[start][end];
    }else{
        for (int i = start; i <= end; i++) {
            int tmp = i+max(dp(tes, start, i-1) , dp(tes, i+1, end));
            count = min(count, tmp);
        }
        tes[start][end] = count;
        return count;
    }
}
int getMoneyAmount(int n) {
    int count = 0;
    vector<vector<int>> tes;
    for (int i = 0; i < n+1; i++) {
        vector<int> t(n+1,0);
        tes.push_back(t);
    }
    count = dp(tes, 1, n);
    return count;
}

int main(){
    int result = getMoneyAmount(100);
    cout<< result <<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
