//
//  221-MaximalSquare.cpp
//  leecode
//
//  Created by lixiangqian on 16/11/17.
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
#include <sstream>
using namespace std;
int maximalSquare(vector<vector<char>>& matrix) {
    int i = 1, j = 1;
    int r = 0;
    if(matrix.size() ==0){
        return 0;
    }
    vector<char> m = matrix[0];
    if(m.size() == 0){
        return 0;
    }
    bool hasone = false;
    long wsize = m.size();
    long hsize = matrix.size();
    for(int m=0; m<hsize;m++){
            for(int k=0; k<wsize; k++){
                if(matrix[m][k] =='1'){
                    r= 1;
                    break;
                }
            }
    }
    vector<int> xx(wsize,0);
    vector<vector<int>> yy;
    for(int k = 0; k< hsize; k++){
        yy.push_back(xx);
    }
    
    //先横向右移，再竖向下移
    for (; j<hsize; j++){
        for (i=1; i<wsize; i++) {
            //判定条件 重要
            if(matrix[j][i] == '1' && matrix[j-1][i-1] == '1' && matrix[j-1][i] =='1' && matrix[j][i-1]=='1')
            {
                yy[j][i] = min(min(yy[j-1][i],yy[j][i-1]),yy[j-1][i-1])+1;
                hasone = true;
                r = max(yy[j][i],r);
            }else{
                yy[j][i] = 0;
            }
        }
    }
    return r==0?0:(hasone?pow(r+1, 2):1);
}
int main(){
    vector<vector<char>> matrix;
    for(int i=0; i<2;i++){
        vector<char> m(2);
        m[0]='1';
        m[1]='0';
        matrix.push_back(m);
    }
    int r = maximalSquare(matrix);
    cout<<"hello world!"<<endl;
    cout<<r<<endl;
    return 0;
}
