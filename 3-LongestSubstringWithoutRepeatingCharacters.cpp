//
//  43multiplyStrings.cpp
//  leecode
//
//  Created by lixiangqian on 16/10/24.
//  Copyright © 2016年 lixiangqian. All rights reserved.
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

int longestSubstringWithoutRepeatingCharacters(string s){
    int arr[100];
    int index=0;
    if(s=="")
        return 0;
    int findex=0,fmaxlength=1;
    int maxLength;
    bool conti;
    for(int j=0; j<s.size(); j++){
        maxLength=0;
        memset(arr, 0, sizeof(arr));
        conti=true;
        int i=j;
        index = i;
        while(conti && i<s.size()){
            if(arr[s[i]-' ']==0){
                arr[s[i]-' ']=1;
                maxLength++;
                i++;
            }else{
                conti=false;
            }
        }
        if(maxLength > fmaxlength){
            findex = j;
            fmaxlength = maxLength;
        }
    }
    return fmaxlength;
}

int main(){
    string a = "abca !09a23";
    int result = longestSubstringWithoutRepeatingCharacters(a);
    cout<<"helloworld"<<endl;
    cout<<result<<endl;
}
