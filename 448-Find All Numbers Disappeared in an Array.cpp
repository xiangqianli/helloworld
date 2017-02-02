//
//  448-Find All Numbers Disappeared in an Array.cpp
//  leecode
//  时间复杂度更低的方法，可以参考2ms的那个java解法，把出现的数字（绝对值）转换概念为下标，把该下标的数值置为负数
//  Created by lixiangqian on 17/2/2.
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

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;
    for (int i =0 ; i<nums.size(); i++) {
        int j = i;
        while (nums[j] != nums[nums[j]-1]) {
            swap(nums[j], nums[nums[j]-1]);
        }
    }
    for (int i =0 ; i<nums.size(); i++) {
        if (nums[i] != i+1) {
            result.push_back(i+1);
        }
    }
    return result;
}

int main(){
    vector<int> nums(8);
    nums[0] = 4;
    nums[1] = 3;
    nums[2] = 2;
    nums[3] = 7;
    nums[4] = 8;
    nums[5] = 2;
    nums[6] = 3;
    nums[7] = 1;
    vector<int> result = findDisappearedNumbers(nums);
    for (long i = 0; i < result.size(); i++) {
        cout<<result[i]<<endl;
    }
    cout<<"hello world!"<<endl;
    return 0;
}
