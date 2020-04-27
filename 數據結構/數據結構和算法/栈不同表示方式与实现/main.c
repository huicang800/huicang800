//
//  main.c
//  栈不同表示方式与实现
//
//  Created by Apple on 4/16/20.
//  Copyright © 2020 ojoj. All rights reserved.
//

#include <stdio.h>

#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 顺序栈结构 */
typedef struct
{
    SElemType data[MAXSIZE];
    int top; /* 用于栈顶指针 */
}SqStack;

//4.1 构建一个空栈S
Status InitStack(SqStack *S){
   
    S->top = -1;
    return OK;
}


//4.2 将栈置空
Status ClearStack(SqStack *S){
    
    //疑问: 将栈置空,需要将顺序栈的元素都清空吗?
    //不需要,只需要修改top标签就可以了.
    S->top = -1;
    return OK;
}

//4.3 判断顺序栈是否为空;
Status StackEmpty(SqStack S){
    if (S.top == -1)
        return TRUE;
    else
        return FALSE;
}

//4.4 返回栈的长度
int StackLength(SqStack S){
    return S.top + 1;
}

//4.5 获取栈顶
Status GetTop(SqStack S,SElemType *e){
    if (S.top == -1)
        return ERROR;
    else
        *e = S.data[S.top];
   
    return OK;
    
}

//4.6 插入元素e为新栈顶元素
Status PushData(SqStack *S, SElemType e){
    
    //栈已满
    if (S->top == MAXSIZE -1) {
        return ERROR;
    }
    
    //栈顶指针+1;
    S->top ++;
    //将新插入的元素赋值给栈顶空间
    S->data[S->top] = e;
    
    return OK;
}

//4.7 删除S栈顶元素,并且用e带回
Status Pop(SqStack *S,SElemType *e){
   
    //空栈,则返回error;
    if (S->top == -1) {
        return ERROR;
    }
    
    //将要删除的栈顶元素赋值给e
    *e = S->data[S->top];
    //栈顶指针--;
    S->top--;
    
    return OK;
}

//4.8 从栈底到栈顶依次对栈中的每个元素打印
Status StackTraverse(SqStack S){
    int i = 0;
    printf("此栈中所有元素");
    while (i<=S.top) {
        printf("%d ",S.data[i++]);
    }
    printf("\n");
    return OK;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("顺序栈的表示与实现!\n");
    
    
    SqStack S;
    int e;
    
    if (InitStack(&S) == OK) {
        for (int j = 1 ; j < 10; j++) {
            PushData(&S, j);
        }
    }
    
    printf("顺序栈中元素为:\n");
    StackTraverse(S);
    
    Pop(&S, &e);
    printf("弹出栈顶元素为: %d\n",e);
    StackTraverse(S);
    printf("是否为空栈:%d\n",StackEmpty(S));
    GetTop(S, &e);
    printf("栈顶元素:%d \n栈长度:%d\n",e,StackLength(S));
    ClearStack(&S);
    printf("是否已经清空栈 %d, 栈长度为:%d\n",StackEmpty(S),StackLength(S));
    

    return 0;
}
