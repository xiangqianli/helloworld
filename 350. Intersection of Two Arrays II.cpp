//
//  350. Intersection of Two Arrays II
//  leecode
//
//  Created by lixiangqian on 17/2/1.
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
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    if (nums1.size() == 0 || nums2.size() == 0) {
        return result;
    }
    if (nums1.size() < nums2.size()){
        swap(nums1,nums2);
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for (long j = 0, k = 0; j < nums1.size() && k < nums2.size();) {
        if (nums1[j] == nums2[k]) {
            result.push_back(nums2[k]);
            j++;
            k++;
        }else if(nums1[j] < nums2[k]){
            j++;
        }else if(nums1[j] > nums2[k]){
            k++;
        }
    }
    return result;
}

int main(){
    vector<int> nums1(2);
    nums1[0] = 1;
    nums1[1] = 2;
    vector<int> nums2(1);
    nums2[0] = 2;
    vector<int> result = intersection(nums1, nums2);
    for (long i =0; i<result.size(); i++) {
        cout<<result[i]<<endl;
    }
    cout<<"hello world!"<<endl;
    return 0;
}
