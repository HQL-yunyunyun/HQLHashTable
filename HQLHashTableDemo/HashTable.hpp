//
//  HashTable.hpp
//  HQLHashTableDemo
//
//  Created by 何启亮 on 2019/4/17.
//  Copyright © 2019 hql_personal_team. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>

/*
 哈希表的实现
    这里解决哈希冲突使用的是拉链法(同一哈希地址的value都放进一个链表中)
 */

#define HASHTABLESIZE 10 // 哈希表的大小
typedef struct Node {
    const char *key;
    const char *value;
    struct Node *next;
} Node;

class HashTable {
private:
    Node *node[HASHTABLESIZE];
public:
    HashTable(); // 构造方法
    ~HashTable(); // 析构函数
    unsigned hash(const char *key); // 哈希函数
    Node *lookup(const char *key); // 查找节点
    bool add(const char *key, const char *value); // 添加
    const char *get(const char *key); // 获取value
    void display(); // 显示所有的节点
};

#endif /* HashTable_hpp */
