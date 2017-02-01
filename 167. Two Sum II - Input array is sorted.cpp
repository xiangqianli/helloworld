//
//  167. Two Sum II - Input array is sorted.cpp
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

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = (int)numbers.size()-1;
    vector<int> result(2,0);
    while (i < j) {
        if(numbers[i] + numbers[j] > target){
            j--;
        }else if(numbers[i] + numbers[j] < target){
            i++;
        }else{
            result[0] = i+1;
            result[1] = j+1;
            break;
        }
    }
    return result;
}

int main(){
    vector<int> numbers(4);
    numbers[0] = 2;
    numbers[1] = 7;
    numbers[2] = 11;
    numbers[3] = 15;
    
    vector<int> result = twoSum(numbers, 9);
    for (long i =0; i<result.size(); i++) {
        cout<<result[i]<<endl;
    }
    cout<<"hello world!"<<endl;
    return 0;
}
