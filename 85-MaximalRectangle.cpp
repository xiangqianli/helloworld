//
//  85-MaximalRectangle.cpp
//  leecode
//
//  Created by lixiangqian on 16/11/21.
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
int maximalRectangle(vector<vector<char>>& matrix) {
    int i , j;
    int r = 0;
    if(matrix.size() ==0){
        return r;
    }
    vector<char> m = matrix[0];
    if(m.size() == 0){
        return r;
    }
    long wsize = m.size();
    long hsize = matrix.size();
    for(int m=0; m<hsize;m++){
        for(int k=0; k<wsize; k++){
            if(matrix[m][k] =='1'){
                r = 1;
                break;
            }
        }
    }
    int yy[hsize][wsize][2];
    memset(yy, 0, sizeof(yy));
    
    //先横向右移，再竖向下移
    for (j=0; j<hsize; j++){
        for (i=0; i<wsize; i++) {
            if(matrix[j][i]=='1')
            {
                int tempy,tempx,ttempy,ttempx;
                int temparea=r;
                if(j>0 && i>0){
                    yy[j][i][0] = yy[j][i-1][0] + 1;
                    yy[j][i][1] = yy[j-1][i][1] + 1;
                    //竖向最小
                    tempy = min(yy[j][i][0],yy[j-1][i][0]);
                    ttempy = tempy;
                    tempx = min(yy[j][i][1],yy[j][i-1][1]);
                    ttempx = tempx;
                    for(int k = 2; k<tempy; k++){
                        tempx = min(tempx,yy[j][i-k][1]);
                    }
                    for(int k = 2; k<ttempx; k++){
                        ttempy = min(ttempy,yy[j-k][i][0]);
                    }
                    temparea = max(max(max(ttempx*ttempy,tempx*tempy),yy[j][i][0]),yy[j][i][1]);
//                    cout<<tempx<<endl;
//                    cout<<tempy<<endl;
                }else if(j==0 && i>0){
                    yy[j][i][1] = 1;
                    yy[j][i][0] = yy[j][i-1][0] + 1;
                    tempx = max(yy[j][i][0],yy[j][i-1][0]);
                    temparea = tempx;
//                    cout<<tempx<<endl;
                }else if(i==0 && j>0){
                    yy[j][i][0] = 1;
                    yy[j][i][1] = yy[j-1][i][1] + 1;
                    tempy = max(yy[j][i][1],yy[j-1][i][1]);
                    temparea = tempy;
//                    cout<<tempy<<endl;
                }else if(i==0 && j==0){
                    yy[j][i][0]=yy[j][i][1]=1;
                }
//                cout<<"===================="<<endl;
//                cout<<yy[j][i][0]<<endl;
//                cout<<yy[j][i][1]<<endl;
//                
//                cout<<temparea<<endl;
                r = max(temparea,r);
            }
        }
    }
    return r;
}
int main(){
    vector<vector<char>> matrix;
    for(int i=0; i<3;i++){
        vector<char> m(5);
        m[0]='1';
        m[1]='1';
        m[2]='1';
        m[3]='1';
//        m[3]='0';
//        m[4]='0';
//        if(i==1){
//            m[3]='1';
//            m[4]='1';
//        }else if(i==2){
//            m[1]='1';
//            m[3]='1';
//            m[4]='1';
//        }else if(i==3){
//            m[2]='0';
//            m[3]='1';
//        }
        matrix.push_back(m);
    }
    int r = maximalRectangle(matrix);
    cout<<"hello world!"<<endl;
    cout<<r<<endl;
    return 0;
}
