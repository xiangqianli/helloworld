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
int * stringToNumberList(string a, long al);
string multiplyStrings(string num1, string num2){
    string r;
    if(num1=="0"||num2=="0")
        return "0";
    long al = num1.size();
    long bl = num2.size();
    int * rr = new int[al+bl+1];
    memset(rr, 0, (al+bl+1)*4);
    
    int * aa = stringToNumberList(num1, al);
    int * bb = stringToNumberList(num2, bl);
    for(int i=0;i<bl;i++){
        int *temp= new int[al+1];
        memset(temp, 0, (al+1)*4);
        int add = 0;
        for (int j=0; j < al; j++){
            *(temp+j) = (*(aa+j) * *(bb+i) + add)%10;
            add = ((*(aa+j)) * (*(bb+i)) +add)/10;
        }
        *(temp+al)=add;
        for(int xx=0;xx<al+1;xx++){
            cout<<*(temp+xx)<<endl;
        }
        add=0;
        for(int j=0; j<=al;j++){
            int temprr = *(rr+i+j);
            *(rr+i+j) = (temprr+ *(temp+j)+add)%10;
            add =  (temprr+ (*(temp+j))+add)/10;
        }
        if(add>0){
            *(rr+i+al+1) = add;
        }
    }
    
    for(long k=al+bl-2; k>=0 ;k--){
        r +=to_string(*(rr+k));
    }
    if(*(rr+al+bl-1)>0 && *(rr+al+bl-1)<10){
        r =to_string(*(rr+al+bl-1))+r;
    }
    return r;
}
int * stringToNumberList(string a, long al){
    int *aa = new int[al];
    for(int i=0;i<al;i++){
        *(aa+i)=a[al-i-1]-'0';
    }
    return aa;
}
int main(){
    string a = "12345";
    string b = "31";
    string result = multiplyStrings(a,b);
    cout<<"helloworld"<<endl;
    cout<<result<<endl;
}
