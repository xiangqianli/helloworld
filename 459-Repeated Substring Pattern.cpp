//
//  459-Repeated Substring Pattern.cpp
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

bool repeatedSubstringPattern(string str) {
    if (str=="" || str.size() == 1) {
        return false;
    }
    int font=0;
    bool panduan = false;
    long strsize = str.size();
    for (int next = 1; next <= strsize/2; next++) {
        if (str[font] == str[next]) {
            int p = font+1;
            int q = next+1;
            while (str[p] == str[q] && q< strsize) {
                p++;
                q++;
            }
            //注意考虑没有循环完的情况
            if (q == strsize && p%(next - font)==0 ) {
                panduan = true;
                break;
            }
        }
    }
    return panduan;
}
int main(){
    string str = "abcabcabc";
    bool result = repeatedSubstringPattern(str);
    cout<<result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}

