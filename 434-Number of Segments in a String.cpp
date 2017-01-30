//
//  434-Number of Segments in a String.cpp
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
int countSegments(string s) {
    int count = 0;
    bool startanother = false;
    for (long i=0; i<s.size(); i++) {
        //注意考虑好边界条件，这个题是i == s.size()-1的情况
        if ((s[i] == ' ' || i==s.size()-1) && startanother) {
            count++;
            startanother = false;
        }else if(s[i] != ' ' && !startanother){
            startanother = true;
            if (i==s.size() - 1) {
                count++;
            }
        }
    }
    return count;
}
int main(){
    string s = "";
    int result = countSegments(s);
    cout<<result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
