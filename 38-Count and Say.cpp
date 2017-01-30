//
//  38-Count and Say.cpp
//  leecode
//
//  Created by lixiangqian on 17/1/30.
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

string countAndSay(int n) {
    string s="1";
    string st;
    for (int i=0 ; i < n-1 ; i++) {
        st = "";
        long ss = s.size();
        long j = 0;
        int count = 1;
        while (j < ss) {
            if (j+1 < ss && s[j] == s[j+1]) {
                count ++;
            }else{
                st = st + to_string(count) + s[j] ;
                count = 1;
            }
            j++;
        }
        s = st;
    }
    return s;
}

int main(){
    int n = 4;
    string result = countAndSay(n);
    cout<<result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
