//
//  main.cpp
//  leecode
//
//  Created by lixiangqian on 16/10/23.
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
ListNode * addTwoNumbers(ListNode *l1, ListNode *l2){
    ListNode *p =l1, *q=l2;
    ListNode * result = (ListNode *)malloc(sizeof(ListNode));
    ListNode * s = result;
    
    int add =0;
    while(p !=NULL || q!=NULL){
        int temp = (p?p->val:0) + (q?q->val:0);
        ListNode *t = (ListNode *)malloc(sizeof(ListNode));
        t->val = (temp+add)%10;
        add = (temp+add)/10;
        s->next = t;
        s =t;
        p = p?p->next:p;
        q = q?q->next:q;
    }
    if(add==1){
        ListNode *t=(ListNode *)malloc(sizeof(ListNode));
        t->val = add;
        s->next = t;
        s=t;
    }
    s->next=NULL;
    return result;
}
int main()
{
    ListNode* l1;
    ListNode l10(2), l11(4), l12(6);
    ListNode* l2;
    ListNode l20(5), l21(6), l22(4);
    
    l1 =&l10;
    l10.next = &l11;
    l11.next = &l12;
    
    l2 =&l20;
    l20.next = &l21;
    l21.next = &l22;

    
    ListNode * l3 = addTwoNumbers(l1,l2);
    ListNode * r = l3->next;
    while(r!=NULL){
        cout<< " "<< r->val;
        r= r->next;
    }
    cout<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
