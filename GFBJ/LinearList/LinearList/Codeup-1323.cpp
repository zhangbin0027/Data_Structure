//
//  OJ.cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/20.
//  Copyright © 2017年 牛严. All rights reserved.
//

//题目ID：1323 集合union

#include <iostream>

using namespace std;

#define maxSize 200

typedef int ElementType;

typedef struct List
{
    ElementType data[maxSize];
    int length;
    
    List()
    {
        memset(this,0,sizeof(List));
    }
    
}List;

bool ExistElem(List &A, ElementType a)
{
    for (int i = 0; i < A.length; ++i) {
        if (a == A.data[i]) {
            return true;
        }
    }
    return false;
}

void ListInsert(List &A, int i, ElementType a)
{
    A.data[i] = a;
    ++A.length;
}

/**
 将所有在线性表B中但不在线性表A中的元素插入到A的尾部
 */
void Union(List &A, List B)
{
    for (int i = 0; i < B.length; i ++) {
        ElementType e = B.data[i];
        if (!ExistElem(A, e)) {
            ListInsert(A, ++A.length, e);
        }
    }
}



