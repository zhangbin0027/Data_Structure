//
//  OldExam-1.cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/24.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

typedef int ElementType;
typedef struct LNode
{
    ElementType data;
    struct LNode *next;
    
}LNode;

/**
 已知一个带表头结点的单链表，假设该链表只给出了头结点head。在不改变链表的前提下，
 请设计一个尽可能搞笑的算法，查找链表中倒数第k个位置上的结点。若查找成功，输出该
 结点的data，返回1，否则返回0
 */
int LocateElement(LNode *head, int k)
{
    LNode *q = head->next;      //遍历结点
    LNode *p = head;            //遍历结点的前k个结点，当q遍历完成，该结点所指即为目标结点
    int i = 0;                  //i表示q移动次数，第k次时开始移动p
    
    while (q != NULL) {
        q = q->next;
        ++i;
        if (i >= k) {
            p = p->next;
        }
    }
    if (p == head) {            //p没走动，链表元素数量小于k
        return 0;
    }else{
        cout << p->data;
        return 1;
    }
}
