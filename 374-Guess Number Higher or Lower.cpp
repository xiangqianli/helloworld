//
//  374-Guess Number Higher or Lower.cpp
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
int guess(int num){
    int n = 7;
    if (num == n) {
        return 0;
    }else if(num > n){
        return -1;
    }else
        return 1;
}

int guessNumber(int n) {
    int low = 1, high= n, mid ;
    while (low < high) {
        //不要用mid = (low + high)/2 会溢出
        mid = low + (high-low)/2;
        //把需要两次用到的接口请求提出来，大大节省时间
        int t = guess(mid);
        if (t==0) {
            return mid;
        }else if(t > 0){
            low = mid +1;
        }else{
            high = mid -1;
        }
    }
    return low;
}

int main(){
    int result = guessNumber(10);
    cout<< result <<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
