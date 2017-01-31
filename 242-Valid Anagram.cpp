//
//  242-Valid Anagram.cpp
//  leecode
//  还可以将空间复杂度优化一半，就一个辅助数组，s里的增加，t里的减少，判断数组里的元素是否是0
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

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    vector<int> ss(26,0), st(26,0);
    for (long i = 0; i < s.size(); i++) {
        ss[s[i]-'a']++;
        st[t[i]-'a']++;
    }
    return ss==st;
}

int main(){
    string s = "a";
    string t = "n";
    bool result = isAnagram(s, t);
    cout<<result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
