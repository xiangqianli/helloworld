//
//  33-Search in Rotated Sorted Array.cpp
//  leecode
//
//  Created by lixiangqian on 17/2/12.
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

int search33(vector<int>& nums, int target) {
    int result = -1;
    int low = 0, high = (int)nums.size()-1, mid;
    while (low <= high) {
        mid = low + (high - low)/2;
        if (nums[mid] == target) {
            result = mid;
            break;
            //判断条件要清楚
        }else if ((nums[mid] > target && (nums[high] > nums[mid] || (nums[low] < nums[mid] && nums[low] <= target))) || (nums[mid] < target && nums[low] > nums[mid] && nums[low] >nums[high] && target > nums[high])) {
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return result;
}

int main(){
    vector< int> nums(3);
    nums[0] = 3;
    nums[1] = 5;
    nums[2] = 1;
    int result = search33(nums, 3);
    cout<<result<<endl;
    return 0;
}
