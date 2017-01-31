//
//  88-Merge Sorted Array.cpp
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
void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1;
    int j;
    if (m == 0) {
        nums1 = nums2;
        return;
    }
    /*
     不清楚为什么会出现
     [1,2,3,0,0,0]
     3
     [1]
     1
     这种测试用例，所以才会有下面这段和上面那段代码
     */
    while (m < nums1.size()) {
        nums1.erase(nums1.end()-1);
    }
    for (j = n-1; j >=0 && i>=0;) {
        if (nums2[j] > nums1[i]) {
            int t = nums2[j];
            if (i == m-1) {
                nums1.push_back(t);
            }else{
                nums1.insert(nums1.begin()+i+1, t);
            }
            m++;
            j--;
        }else{
            i--;
        }
    }
    if (i == -1) {
        for (int k = j; k >= 0 ; k--) {
            nums1.insert(nums1.begin(), nums2[k]);
        }
    }
}
int main(){
    vector<int> nums1(3);
    nums1[0] = 1;
    nums1[1] = 0;
    nums1[2] = 0;
    vector<int> nums2(1);
    nums2[0] = 2;
    merge1(nums1, 1, nums2, 1);
    for (long i = 0; i<nums1.size(); i++) {
        cout<<nums1[i]<<endl;
    }
    cout<<"hello world!"<<endl;
    return 0;
}
