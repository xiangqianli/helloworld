//
//  344-Reverse String.cpp
//  leecode
//
//  Created by lixiangqian on 17/1/29.
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

string reverseString(string s) {
    long ss = s.size();
    if (s == "") {
        return "";
    }
    //用swap方法，不要另外开辟空间，否则可能会内存溢出
    for (long i = 0, j = ss-1; i < j;) {
        swap(s[i++], s[j--]);
    }
    return s;
}

int main(){
    string s = "IbanezOEM";
    string result = reverseString(s);
    cout<<result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}

