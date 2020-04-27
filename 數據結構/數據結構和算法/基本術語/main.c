//
//  main.c
//  基本術語
//
//  Created by Apple on 4/14/20.
//  Copyright © 2020 ojoj. All rights reserved.
//

#include <stdio.h>
//数据项: 一个数据元素由若干数据项组成
//数据元素: 组成数据的对象的基本单位
//数据对象: 性质相同的数据元素的集合(类似于数组)
//
//结构: 数据元素之间不是独立的,存在特定的关系.这些关系即是结构;
//数据结构:指的数据对象中的数据元素之间的关系
struct Teacher{  //一种数据结构
    char *name;  //数据项--名字
    char *title; //数据项--职称
    int age;     //数据项--年龄
};
int main(int argc, const char * argv[]) {
    
    
    // insert code here...
    
    printf("Hello, World!\n");
    
    
    struct Teacher t1;
    
    struct Teacher tArray[10];
    
    
    t1.age = 18;
    
    t1.name = "CC";
    
    t1.title = "講師";
    
    printf("%s\n",t1.name);
    
    printf("%d\n",t1.age);
    
    printf("%s\n",t1.title);
    
    
    return 0;
}
