//
//  13-RomantoInteger.cpp
//  leecode
//
//  Created by lixiangqian on 16/12/27.
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
int getnum(char num);
int romanToInt(string s){
    int result = 0;
    long ss = s.size();
    for(long i=0; i<ss; i++){
        int tx = getnum(s[i]);
        int ty = getnum(s[i+1]);
        if((tx==1 || tx==10 || tx==100)&&(tx<ty)){
            result += ty-tx;
            i++;
        }else{
            result += tx;
        }
    }
    return result;
}
int getnum(char num){
    if (num == 'I') {
        return 1;
    }else if (num == 'V'){
        return 5;
    }else if (num == 'X'){
        return 10;
    }else if (num == 'L'){
        return 50;
    }else if (num == 'C'){
        return 100;
    }else if(num == 'D'){
        return 500;
    }else if (num == 'M'){
        return 1000;
    }else
        return 0;
}
int main(){
    string ss = "CD";
    int result = romanToInt(ss);
    cout<<result<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
