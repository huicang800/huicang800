//
//  main.c
//  链式栈的表示与实现
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


/* 链栈结构 */
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct
{
    LinkStackPtr top;
    int count;
}LinkStack;

/*5.1 构造一个空栈S */
Status InitStack(LinkStack *S)
{
    S->top=NULL;
    S->count=0;
    return OK;
}


/*5.2 把链栈S置为空栈*/
Status ClearStack(LinkStack *S){
    LinkStackPtr p,q;
    p = S->top;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    S->count = 0;
    return OK;
    
}

/*5.3 若栈S为空栈,则返回TRUE, 否则返回FALSE*/
Status StackEmpty(LinkStack S){
    if (S.count == 0)
        return TRUE;
    else
        return FALSE;
}

/*5.4 返回S的元素个数,即栈的长度*/
int StackLength(LinkStack S){
    return S.count;
}

/*5.5 若链栈S不为空,则用e返回栈顶元素,并返回OK ,否则返回ERROR*/
Status GetTop(LinkStack S,SElemType *e){
    if(S.top == NULL)
        return ERROR;
    else
        *e = S.top->data;
    return OK;
}

/*5.6 插入元素e到链栈S (成为栈顶新元素)*/
Status Push(LinkStack *S, SElemType e){
    
    //创建新结点temp
    LinkStackPtr temp = (LinkStackPtr)malloc(sizeof(StackNode));
    //赋值
    temp->data = e;
    //把当前的栈顶元素赋值给新结点的直接后继, 参考图例第①步骤;
    temp->next = S->top;
    //将新结点temp 赋值给栈顶指针,参考图例第②步骤;
    S->top = temp;
    S->count++;
    return OK;
}

/*5.7 若栈不为空,则删除S的栈顶元素,用e返回其值. 并返回OK,否则返回ERROR*/
Status Pop(LinkStack *S,SElemType *e){
    LinkStackPtr p;
    if (StackEmpty(*S)) {
        return ERROR;
    }
    
    //将栈顶元素赋值给*e
    *e = S->top->data;
    //将栈顶结点赋值给p,参考图例①
    p = S->top;
    //使得栈顶指针下移一位, 指向后一结点. 参考图例②
    S->top= S->top->next;
    //释放p
    free(p);
    //个数--
    S->count--;
    
    return OK;
    
    
}

/*5.8 遍历链栈*/
Status StackTraverse(LinkStack S){
    LinkStackPtr p;
    p = S.top;
    while (p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("链栈定义与实现\n");
    
    int j;
    LinkStack s;
    int e;
    if(InitStack(&s)==OK)
        for(j=1;j<=10;j++)
            Push(&s,j);
    printf("栈中元素依次为：");
    StackTraverse(s);
    Pop(&s,&e);
    printf("弹出的栈顶元素 e=%d\n",e);
    StackTraverse(s);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    GetTop(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    
    return 0;
}

