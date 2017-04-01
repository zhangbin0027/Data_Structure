//
//  BinarySearchTree.cpp
//  Search
//
//  Created by 牛严 on 2017/3/30.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct BTNode
{
    int key;
    BTNode *lchild;
    BTNode *rchild;
}BTNode;

/**
 二叉排序树查找关键字
 */
BTNode* BSTSearch(BTNode *bt, int key)
{
    if (bt == NULL) {
        return NULL;
    }
    
    if (key == bt->key) {
        return bt;
    }else if (key < bt->key){
        return BSTSearch(bt->lchild, key);
    }else {
        return BSTSearch(bt->rchild, key);
    }
}

/**
 二叉排序树插入关键字
 */
int BSTInsert(BTNode *&bt, int key)
{
    if (bt == NULL) {
        bt = (BTNode *)malloc(sizeof(BTNode));
        bt->key = key;
        return 1;
    }else {
        if (key == bt->key) {
            return 0;
        }else if(key < bt->key) {
            return BSTInsert(bt->lchild, key);
        }else {
            return BSTInsert(bt->lchild, key);
        }
    }
}
