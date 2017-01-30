//
//  438-Find All Anagrams in a String.cpp
//  leecode
//  用两个指针的方法来比较，时间复杂度O(n).
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
vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    vector<int> ns(26,0), np(26,0);
    //还是要注意边界条件的判断
    if (s.size() < p.size()) {
        return result;
    }
    for (int i = 0; i < p.size(); i++) {
        ns[s[i]-'a']++;
        np[p[i]-'a']++;
    }
    if (ns == np) {
        result.push_back(0);
    }
    for (long si = p.size(); si < s.size(); si++) {
        ns[s[si]-'a']++;
        ns[s[si-p.size()]-'a']--;
        if (ns == np) {
            result.push_back((int)(si-p.size()+1));
        }
    }
    return result;
}

int main(){
    string s = "abcbcabcabc";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);
    for (int i = 0; i<result.size(); i++) {
      cout<<result[i]<<endl;
    }
    cout<<"hello world!"<<endl;
    return 0;
}
