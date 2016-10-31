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
    vector<int> d;
    d.push_back(nums[0]);
    for(int i=0;i<size;i++){
        int left=0,right=(int)d.size()-1;
        if(nums[i]>d[right]){
            //只有它才是增长结点的所在
            d.push_back(nums[i]);
        }else{
            //二分查找
            while(left<=right){
                //记得mid的公式
                int mid  = left+(right-left)/2;
                if(nums[i]==d[mid]){
                    left=mid;
                    break;
                }else if(nums[i]>d[mid]){
                    left=mid+1;
                }else if(nums[i]<d[mid]){
                    right=mid-1;
                }
            }
            d[left]=nums[i];
        }
    }
    return (int)d.size();
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
