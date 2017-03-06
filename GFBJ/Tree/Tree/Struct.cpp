//
//  Struct.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/6.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct BTNode
{
    char data;
    
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;
