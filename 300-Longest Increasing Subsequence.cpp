//
//  300-LIS.cpp
//  leecode
//
//  Created by lixiangqian on 16/10/29.
//  Copyright © 2016年 lixiangqian. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    long size = nums.size();
    if(size==0)
        return 0;
    int d[size+1];
    int maxl=1;
    memset(d, 0, sizeof(d));
    d[1]=1;
    for(int i=2;i<=size;i++){
        for(int j=1;j<i;j++){
            if(nums[j-1]<nums[i-1]){
                d[i]=max(d[i],d[j]+1);
            }
        }
        if(d[i]<1){d[i]=1;}
        if(d[i]>maxl){maxl=d[i];}
    }
    return maxl;
}
int main(){
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(101);
    nums.push_back(18);
    int length= lengthOfLIS(nums);
    cout<<"hello world!"<<endl;
    cout<<length<<endl;
    return 0;
}
