//
//  81-Search in Rotated Sorted Array II.cpp
//  leecode
//
//  Created by lixiangqian on 17/3/1.
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

bool search332(vector<int>& nums, int target){
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
            if (nums[mid] >= nums[low] && nums[mid] > target && target >= nums[low]) {
                high = mid - 1;
            }else if(nums[mid] <= nums[high] && (target >= nums[low] || target < nums[mid])){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            low ++ ;
        }
    }
    if (nums.size() > 0 && nums[low] == target) {
        result = low;
    }
    return result==-1?false:true;
}

int main(){
    vector< int> nums(6);
    nums[0] = 1;
    nums[1] = 1;
    nums[2] = 1;
    nums[3] = 2;
    nums[4] = 1;
    nums[5] = 1;
    bool result = search332(nums, 2);
    cout<<result<<endl;
    return 0;
}
