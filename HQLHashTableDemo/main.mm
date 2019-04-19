//
//  main.m
//  HQLHashTableDemo
//
//  Created by 何启亮 on 2019/4/17.
//  Copyright © 2019 hql_personal_team. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "HashTable.hpp"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        HashTable *ht = new HashTable();
        NSString *keyString = @"hello";
        NSString *valueString = @"world";
        // 插入
        for (int i = 0; i < 50; i++) {
            NSString *aKey = [NSString stringWithFormat:@"%@%d",[keyString substringWithRange:NSMakeRange((i % keyString.length), 1)], i];
            NSString *aValue = [NSString stringWithFormat:@"%@%d", [valueString substringWithRange:NSMakeRange((i % valueString.length), 1)], i];
            ht->add([aKey UTF8String], [aValue UTF8String]);
        }
        
        const char *value = ht->get("l8");
        printf("%s", value);
        ht->display();
    }
    return 0;
}
