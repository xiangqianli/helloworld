//
//  376-WiggleSubsequence.cpp
//  leecode
//
//  Created by lixiangqian on 16/11/1.
//  Copyright © 2016年 lixiangqian. All rights reserved.
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
//动态规划，二维数组
int wiggleMaxLength(vector<int>& nums) {
    long size = nums.size();
    if(size==0)
        return 0;
    int dp[size][2];
    int maxx=1;
    memset(dp, 0, sizeof(dp));
    dp[0][0]=dp[0][1]=1;
    for(int i=1;i<size;i++){
        int mmax = 0;
        int mmin = 0;
        for(int j=i-1;j>=0;j--){
            if(nums[j]>nums[i]){
                mmax = max(mmax,dp[j][1]);
            }else if(nums[j]<nums[i]){
                mmin = max(mmin,dp[j][0]);
            }
        }
        //这样最后赋值可以使得dp中的值至少为1
        dp[i][1]=mmin+1;
        dp[i][0]=mmax+1;
        maxx = max(max(dp[i][0], dp[i][1]),maxx);
    }
    return maxx;
}
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(17);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(13);
    nums.push_back(15);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(16);
    nums.push_back(8);
    int r = wiggleMaxLength(nums);
    cout <<"hello world!"<<endl;
    cout <<r<<endl;
    return 0;
}
