//
//  278-First Bad Version.cpp
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
bool isBadVersion(int version){
    if (version >=2) {
        return true;
    }else{
        return false;
    }
}

int firstBadVersion(int n) {
    int low = 1, high = n;
    int mid;
    while(low < high){
        mid = low + (high-low)/2;
        if(low == mid && isBadVersion(mid)){
            break;
        }else if(isBadVersion(mid)){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    return low;
}
int main(){
    int result = firstBadVersion(8);
    cout<< result <<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
