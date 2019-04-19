//
//  HashTable.cpp
//  HQLHashTableDemo
//
//  Created by 何启亮 on 2019/4/17.
//  Copyright © 2019 hql_personal_team. All rights reserved.
//

#include "HashTable.hpp"
#include <string.h>
#include <stdlib.h>
#include <iostream>

// 构造函数
HashTable::HashTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        node[i] = NULL;
    }
}

// 析构函数
HashTable::~HashTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        node[i] = NULL;
    }
}

// 哈希算法
unsigned HashTable::hash(const char *key) {
    unsigned hash = 0;
    for (; *key; ++key) {
        hash = hash * 33 + *key;
    }
    return hash % HASHTABLESIZE;
}

// 查找
Node * HashTable::lookup(const char *key) {
    Node *np;
    unsigned index;
    index = hash(key); // 下标
    // 查找链表
    for (np = node[index]; np; np = np->next) {
        if (!strcmp(key, np->key)) {
            return np;
        }
    }
    return NULL;
}

// 添加
bool HashTable::add(const char *key, const char *value) {
    unsigned index;
    Node *np;
    if (!(np = lookup(key))) { // 该key没有存在
        index = hash(key);
        np = (Node *)malloc(sizeof(Node)); // 创建一个新的节点
        if (!np) {
            // 没有创建成功
            return false;
        }
        np->key = key;
        np->next = node[index]; // 指向原本的节点
        node[index] = np;
    }
    np->value = value;
    return true;
}

// 获取
const char * HashTable::get(const char *key) {
    Node *np = lookup(key);
    if (!np) {
        return NULL;
    }
    return np->value;
}

void HashTable::display() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        printf("current node index : %d \n", i);
        for (Node *np = node[i]; np; np = np->next) {
            std::cout<<"key:"<<np->key<<" "<<"value:"<<np->value<<std::endl;
        }
        printf("\n");
    }
}
