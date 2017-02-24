//
//  Codeup-1329.cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/21.
//  Copyright © 2017年 牛严. All rights reserved.
//

//题目ID：1329 一元多项式加法

#include <iostream>

using namespace std;

typedef struct PNode
{
    int coe;        //coefficient 多项式系数
    int pow;        //power 幂数
    struct PNode *next;
}PNode;

/**
 一元多项式加法，A = A + B，加法前先排序，降序排列
 */
void AddPolyn(PNode *&A, PNode *B)
{
    PNode *p = A->next;
    PNode *q = B->next;
    PNode *r = A;           //存储要插入在A中p结点前面时候的先驱结点
    PNode *d;
    while (p != NULL && q != NULL) {
        if (p->pow == q->pow) {          //指数相等
            if (p->coe + q->coe == 0) {
                //删除p结点
                d = p;
                r->next = p->next;
                free(d);
            }else{
                //合并
                p->coe = p->coe + q->coe;
                p = p->next;
                q = q->next;
            }
        }else if (q->pow < p->pow) {    //q指数小于p指数，需要p轮寻到小区q的结点
            while (p != NULL) {
                r = p;
                p = p->next;
                if (p == NULL) {
                    //将B链表剩余部分直接接到A链表最后
                    p->next = q;
                }else if (p->pow < q->pow) {
                    //将q插入到r后
                    d = q->next;
                    r->next = q;
                    q->next = p;
                    r = q;
                    q = d;
                    break;
                }
            }
        }else {     //q指数大于p指数
            //直接插入到p前面
            d = q;
            r->next = q;
            q->next = p;
            r = q;
            q = d;
        }
    }
    if (q != NULL) {
        //将B链表剩余部分直接接到A链表最后
        p->next = q;
    }
    free(B);
}
