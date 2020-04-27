//
//  main.c
//  線性表鏈式存儲
//
//  Created by Apple on 4/14/20.
//  Copyright © 2020 ojoj. All rights reserved.
//

#include <stdio.h>
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OK 1

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

//定义结点
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node * LinkList;


//2.1 初始化单链表线性表
Status InitList(LinkList *L){
    
    //产生头结点,并使用L指向此头结点
    *L = (LinkList)malloc(sizeof(Node));
    //存储空间分配失败
    if(*L == NULL) return ERROR;
    //将头结点的指针域置空
    (*L)->next = NULL;
    
    return OK;
}


//2.2 单链表插入
/*
 初始条件:顺序线性表L已存在,1≤i≤ListLength(L);
 操作结果：在L中第i个位置之后插入新的数据元素e，L的长度加1;
 */
Status ListInsert(LinkList *L,int i,ElemType e){
 
    int j;
    LinkList p,s;
    p = *L;
    j = 1;
    
    //寻找第i-1个结点
    while (p && j<i) {
        p = p->next;
        ++j;
    }
    
    //第i个元素不存在
    if(!p || j>i) return ERROR;
    
    //生成新结点s
    s = (LinkList)malloc(sizeof(Node));
    //将e赋值给s的数值域
    s->data = e;
    //将p的后继结点赋值给s的后继
    s->next = p->next;
    //将s赋值给p的后继
    p->next = s;
    
    return OK;
}


//2.3 单链表取值
/*
 初始条件: 顺序线性表L已存在,1≤i≤ListLength(L);
 操作结果：用e返回L中第i个数据元素的值
 */
Status GetElem(LinkList L,int i,ElemType *e){
    
    //j: 计数.
    int j;
    //声明结点p;
    LinkList p;
    
    //将结点p 指向链表L的第一个结点;
    p = L->next;
    //j计算=1;
    j = 1;
    
    
    //p不为空,且计算j不等于i,则循环继续
    while (p && j<i) {
        
        //p指向下一个结点
        p = p->next;
        ++j;
    }
    
    //如果p为空或者j>i,则返回error
    if(!p || j > i) return ERROR;
    
    //e = p所指的结点的data
    *e = p->data;
    return OK;
    
    
}

//2.4 单链表删除元素
/*
 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)
 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
 */

Status ListDelete(LinkList *L,int i,ElemType *e){
    
    int j;
    LinkList p,q;
    p = (*L)->next;
    j = 1;
    
    //查找第i-1个结点,p指向该结点
    while (p->next && j<(i-1)) {
        p = p->next;
        ++j;
    }
    
    //当i>n 或者 i<1 时,删除位置不合理
    if (!(p->next) || (j>i-1)) return  ERROR;
    
    //q指向要删除的结点
    q = p->next;
    //将q的后继赋值给p的后继
    p->next = q->next;
    //将q结点中的数据给e
    *e = q->data;
    //让系统回收此结点,释放内存;
    free(q);
    
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;           /*  p指向第一个结点 */
    while(p)                /*  没到表尾 */
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;        /* 头结点指针域为空 */
    return OK;
}

//3.1 单链表前插入法
/* 随机产生n个元素值,建立带表头结点的单链线性表L(前插法)*/
void CreateListHead(LinkList *L, int n){
    
    LinkList p;
    
    //建立1个带头结点的单链表
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    
    //循环前插入随机数据
    for(int i = 0; i < n;i++)
    {
        //生成新结点
        p = (LinkList)malloc(sizeof(Node));
       
        //i赋值给新结点的data
        p->data = i;
        //p->next = 头结点的L->next
        p->next = (*L)->next;
        
        //将结点P插入到头结点之后;
        (*L)->next = p;
        
    }
}

//3.2 单链表后插入法
/* 随机产生n个元素值,建立带表头结点的单链线性表L(后插法)*/
void CreateListTail(LinkList *L, int n){
    
    LinkList p,r;
 
    //建立1个带头结点的单链表
    *L = (LinkList)malloc(sizeof(Node));
    //r指向尾部的结点
    r = *L;
    
    for (int i=0; i<n; i++) {
        
        //生成新结点
        p = (Node *)malloc(sizeof(Node));
        p->data = i;
        
        //将表尾终端结点的指针指向新结点
        r->next = p;
        //将当前的新结点定义为表尾终端结点
        r = p;
    }
    
    //将尾指针的next = null
    r->next = NULL;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
