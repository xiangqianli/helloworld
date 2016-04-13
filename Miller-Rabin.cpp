/**
 *利用Miller-Rabin素性测试方法，取底数为2，7，61
 *默认输出所有1993年出生的素数生日，输出其它年份的生日直接改预处理命令
 *原理参考http://www.matrix67.com/blog/archives/234
 *算法参考http://blog.chinaunix.net/uid-21712186-id-1818141.html
 **/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
//  在此将Year修改为相应的年份****
#define Year 1993
using namespace std;
int dayofmonth(int month,int year=1993){
    int day=30;
    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12) {
        day=31;
    }else if (month==2){
        if ((year%100!=0&&year%4==0)||year%400==0)
            day=29;
        else
            day=28;
    }
    return day;
}
long long pow(long long a,long long d,long long n){
    if (d==0)
        return 1;
    else if(d==1)
        return a;
    else if((d&1)==0)
        return pow((a*a)%n,d/2,n)%n;
    else
        return (pow((a*a)%n,d/2,n)*a)%n;
}
bool isprime(long long a,long long data){
    bool judge=false;
    if (data==2)//2是素数
        return true;
    else if (data==0||(data&1)==0||data==1)//偶数、0、1一定不是素数
        return false;
    long long d=data-1;
    while((d&1)==0)
        d=d>>1;//d是奇数，找到a^(d*2^r)中的d
    long long t=pow(a,d,data);//一直往下找
    if(t==1||t==data-1) return true;//最后指数中的2用完了得到的a^d mod data=1或=date-1
    else{
        while(d!=data-1){
            t=(t*t)%data;
            if (t==data-1)//某个i满足a^(d * 2^i) mod data = data-1
                return true;
            d=d<<1;
        }
    }
    return judge;
}
//求****年出生的人中，所有生日日期为素数的生日
int main() {
    long long date;
    long long tempdate;
    int month;
    int day;
    vector<long long> resultList;
    for (month=1; month<=12; month++) {
        date=Year*10000;
        date+=month*100;
        for (day=1; day<dayofmonth(month); day++) {
            tempdate=date+day;
            if(isprime(2,tempdate)&&isprime(7, tempdate)&&isprime(61, tempdate))
                resultList.push_back(tempdate);
        }
    }
    for (int i=0; i<resultList.size(); i++) {
        printf("%lld\n",resultList[i]);
    }
    return 0;
}
