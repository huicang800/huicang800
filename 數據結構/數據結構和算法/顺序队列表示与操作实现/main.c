//
//  main.c
//  顺序队列表示与操作实现
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
typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

/* 循环队列的顺序存储结构 */
typedef struct
{
    QElemType data[MAXSIZE];
    int front;        /* 头指针 */
    int rear;        /* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
}SqQueue;


//6.1 初始化一个空队列Q
Status InitQueue(SqQueue *Q){
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

//6.2 将队列清空
Status ClearQueue(SqQueue *Q){
    
    Q->front = Q->rear = 0;
    return OK;
}

//6.3 若队列Q为空队列,则返回TRUR,否则返回FALSE;
Status QueueEmpty(SqQueue Q){
    //队空标记
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}


//6.4 返回Q的元素个数,也就是队列的当前长度
int QueueLength(SqQueue Q){
    return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
}

//6.5 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR;
Status GetHead(SqQueue Q,QElemType *e){
    //队列已空
    if (Q.front == Q.rear)
        return ERROR;
    
    *e = Q.data[Q.front];
    return OK;
    
}

//6.6 若队列未满,则插入元素e为新队尾元素
Status EnQueue(SqQueue *Q,QElemType e){
    
    //队列已满
    if((Q->rear+1)%MAXSIZE == Q->front)
        return ERROR;
    
    //将元素e赋值给队尾
    Q->data[Q->rear] = e;
    
    //rear指针向后移动一位,若到最后则转到数组头部;
    Q->rear = (Q->rear+1)%MAXSIZE;
    
    return OK;
}

//6.7 若队列不空,则删除Q中队头的元素,用e返回值
Status DeQueue(SqQueue *Q,QElemType *e){
   
    //判断队列是否为空
    if (Q->front == Q->rear) {
        return ERROR;
    }
    
    //将队头元素赋值给e
    *e = Q->data[Q->front];
    
    //front 指针向后移动一位,若到最后则转到数组头部
    Q->front = (Q->front+1)%MAXSIZE;
    
    return OK;
}


//6.8 从队头到队尾依次对队列的每个元素数组
Status QueueTraverse(SqQueue Q){
    int i;
    i = Q.front;
    while ((i+Q.front) != Q.rear) {
        printf("%d   ",Q.data[i]);
        i = (i+1)%MAXSIZE;
    }
    printf("\n");
    return OK;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("001--顺序队列表示与操作实现\n");
    
    Status j;
    int i=0,l;
    QElemType d;
    SqQueue Q;
    InitQueue(&Q);
    printf("初始化队列后，队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
    
    printf("入队:\n");
    while (i < 10) {
        EnQueue(&Q, i);
        i++;
    }
    QueueTraverse(Q);
    printf("队列长度为: %d\n",QueueLength(Q));
    printf("现在队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
    printf("出队:\n");
   
   //出队
    DeQueue(&Q, &d);
    printf("出队的元素:%d\n",d);
    QueueTraverse(Q);

    //获取队头
    j=GetHead(Q,&d);
    if(j)
        printf("现在队头元素为: %d\n",d);
    ClearQueue(&Q);
    printf("清空队列后, 队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
    return 0;
}
