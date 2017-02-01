//
//  349-IntersectionofTwoArrays.cpp
//  leetcode
//  erase会从set/map/vector里把那个迭代器指向的空间销掉，后面的元素都要往前移一位；返回下一个元素的迭代地址(c++11 时set才返回后一位，c++ 98无返回值
//  find相比erase是主要耗时间的操作 
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
    if (nums1.size() == 0 || nums1.size() == 0) {
        return result;
    }
    set<int> e(nums1.begin(), nums1.end());
    for (int j = 0; j < nums2.size(); j++) {
        if (e.erase(nums2[j])) {
            result.push_back(nums2[j]);
            
        }
    }
    return result;
}

int main(){
    vector<int> nums1(2);
    nums1[0] = 1;
    nums1[1] = 2;
    vector<int> nums2(1);
    nums2[0] = 1;
    vector<int> result = intersection(nums1, nums2);
    for (long i =0; i<result.size(); i++) {
        cout<<result[i]<<endl;
    }
    cout<<"hello world!"<<endl;
    return 0;
}
