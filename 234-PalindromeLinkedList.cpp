//
//  234-PalindromeLinkedList.cpp
//  leecode
//
//  Created by lixiangqian on 16/12/26.
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    bool panduan = true;
    ListNode * s = head;
    ListNode * la;
    //新建链表
    ListNode * nh = (ListNode *)malloc(sizeof(ListNode));
    //计算长度
    la = s;
    int count = 0;
    while(la !=NULL){
        
        ListNode * t = (ListNode *)malloc(sizeof(ListNode));
        t->val = la->val;
        t->next = NULL;
        t->next = nh->next;
        nh->next = t;
        
        la = la->next;
        count ++;
    }
    ListNode * na = nh->next;
    la = s;
    for (int i = 0; i<count/2; i++) {
        if (la->val == na->val) {
            la = la->next;
            na = na->next;
        }else{
            panduan = false;
            break;
        }
    }
    return panduan;
}

int main(){
    ListNode *l;
    ListNode l1(3), l2(6), l3(3);
    l = &l1;
    l1.next = &l2;
    l2.next = &l3;
    
    if(isPalindrome(l)){
        cout<<"hello world!"<<endl;
    }else{
        cout<<"good night world!"<<endl;
    }
    return 0;
}
