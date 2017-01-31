//
//  53-Maximum Subarray.cpp
//  leecode
//
//  Created by lixiangqian on 17/1/31.
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
int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    int max = nums[0];
    for (long i = 1; i < nums.size(); i++) {
        //dp的递推条件
        if (nums[i-1] > 0 ) {
            nums[i] = nums[i] + nums[i-1];
        }
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

int main(){
    vector<int> nums(9);
    nums[0] = -2;
    nums[1] = 1;
    nums[2] = -3;
    nums[3] = 4;
    nums[4] = -1;
    nums[5] = 2;
    nums[6] = 1;
    nums[7] = -5;
    nums[8] = 4;
    int result = maxSubArray(nums);
    cout<<result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
