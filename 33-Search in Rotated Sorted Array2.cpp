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
    while (low < high) {
        mid = low + (high - low)/2;
        if (nums[mid] == target) {
            result = mid;
            break;
        }else if(nums[low] < nums[high]) {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }else if(nums[low] > nums[high]){
            if (nums[mid] > nums[low] && nums[mid] > target && target >= nums[low]) {
                high = mid - 1;
            }else if(nums[mid] < nums[high] && (target >= nums[low] || target < nums[mid])){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
    }
    if (nums.size() > 0 && nums[low] == target) {
        result = low;
    }
    return result;
}

int main(){
    vector< int> nums(3);
    nums[0] = 3;
    nums[1] = 1;
    nums[2] = 2;
    int result = search33(nums, 3);
    cout<<result<<endl;
    return 0;
}
