//
//  80-Remove Duplicates from Sorted Array II.cpp
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
int removeDuplicates2(vector<int>& nums) {
    if (nums.size() < 3) {
        return (int)nums.size();
    }
    int i,j;
    //两个指针 一个在前一个在后
    for (i = 1, j = 2; i < nums.size() && j < nums.size(); ) {
        if (nums[j] == nums[i] && nums[i]== nums[i-1]) {
            j ++;
        }else{
            nums[++i] = nums[j++];
        }
    }
    //注意最后return的数值
    return (int)nums.size()-j+i+1;
}

int main(){
    vector<int> nums(6);
    nums[0] = 1;
    nums[1] = 1;
    nums[2] = 1;
    nums[3] = 2;
    nums[4] = 2;
    nums[5] = 3;
    int result = removeDuplicates2(nums);
    cout<<result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
