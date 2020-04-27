//
//  main.c
//  括号匹配实验
//
//  Created by Apple on 4/16/20.
//  Copyright © 2020 ojoj. All rights reserved.
//

#include <stdio.h>

#include<stdlib.h>
#include<string.h>

#define Stack_Init_Size 100
#define Stack_Increment 10
//栈的定义
typedef struct {
    char* base; //栈底指针
    char* top;  //栈顶指针
    int stacksize;  //栈MaxSize
}SqStack;

//初始化栈
/*
 思路:
 1. 如果栈底为空
 2. 分配一个最大容量Stack_Init_Size的数组,栈底/栈顶都指向与它.[参考图空栈情况]
 3. 初始化栈的最大容易Stack_Init_Size
 */
int Init(SqStack *stack){

    if(!stack->base){
        stack->base=(char*)malloc(Stack_Init_Size*sizeof(char));
        stack->top=stack->base;
        stack->stacksize = Stack_Init_Size;
        printf("初始化成功\n");
        return 0; //初始化成功
    }
    else return -1;//表示无法初始化已出始化栈
}

//获取栈顶数据
/*
 思路:
 1.判断栈是否为空
 2.非空,则栈定指针-1,返回栈顶元素;
 */
char GetTop(SqStack stack){
   
    if(stack.base==stack.top){
        //printf("栈中没有数据\n");
        return '#';
    }
    //printf("获取栈顶数据成功\n");
    return *(stack.top-1);
}

//往栈中插入元素
/*
 思路:
 1.判断栈是否已满,若满则返回ERROR #问题:如何判断栈是否已满?
 2.栈满,则续容空间 #问题:如何给已满栈续容空间?
 3.将元素element压栈
 4.栈顶指针加"1"
 */
int Push(SqStack *stack,char element){
    if(stack->top-stack->base==stack->stacksize){
        stack->base=(char*)realloc(stack->base,Stack_Increment*sizeof(char));
        stack->top=stack->base+stack->stacksize;
        stack->stacksize+=Stack_Increment;
    }
    *stack->top=element;
    stack->top+=1;
    return 0;
}

//删除栈顶元素
/*
 思路:
 1.判断栈是否已空
 2.非空,则获取栈顶元素,并将栈顶减"1";
 */
char Pop(SqStack *stack){
    if(stack->top==stack->base){
        printf("栈为空\n");
        return '#';
    }
    //printf("删除数据成功");
    return *--stack->top;
}

//释放栈空间
int Destroy(SqStack *stack){
    free(stack->base);
    stack->stacksize=0;
    return 0;
}

//处理数据，借助栈判断
/*
 思路:
 1. 将第0个元素压栈
 2. 遍历[1,strlen(data)]
    (3). 取栈顶字符
    (4). 检查该字符是左括号("(","[")
         a.是左"(",则判断紧接其后的data[i]是为右")"
            YES->压栈,NO->出栈
         b.是左"[",则判断紧跟其后的data[i]是为右"]"
            YES->压栈,NO->出栈
         c.表示式如果以"#"结尾,则判断紧跟其后的data是为左"(""]"
            YES->压栈,NO->-1;
 
 3.遍历结束,则判断栈是否为空,为空则表示匹配成功;否则匹配失败;
 [ ( [ ] [ ] ) ]
 1 2 3 4 5 6 7 8
 */
int ExecuteData(SqStack stack,char* data){
    Push(&stack,data[0]);
    for(int i=1;i<strlen(data);i++){
        char top = GetTop(stack);
        switch(top){
            case '(':
                if(data[i]==')')Pop(&stack);
                else Push(&stack,data[i]);
                break;
            case '[':
                if(data[i]==']')Pop(&stack);
                else Push(&stack,data[i]);
                break;
            case '#':
                if(data[i]=='('||data[i]=='['){
                    Push(&stack,data[i]);
                    break;
                }
                else
                    default:return -1;break;
        }
    }
    
    //如果栈为空,则返回"0"->匹配成功 否则返回"-1"匹配失败
    if(stack.top==stack.base){
        Destroy(&stack);
        return 0;
    }
    else{
        
        Destroy(&stack);
        return -1;
    }
}


int main(){
    
    /*
     算法问题:
     假设表达式中允许包含两种括号:圆括号与方括号,其嵌套顺序随意,即([]()) 或者[([][])]都是正确的.而这
     [(]或者(()])或者([()) 都是不正确的格式. 检验括号是否匹配的方法可用"期待的急迫程度"这个概念来描述. 例如,考虑以下括号的判断:
     
     [ ( [ ] [ ] ) ]
     1 2 3 4 5 6 7 8
     */
    
    SqStack stack;
    Init(&stack);
    char data[180];
    printf("请输入待匹配的字符串\n");
    scanf("%s",data);
    int result = ExecuteData(stack,data);
    if(result==0)printf("括号是正确匹配的\n");
    else printf("括号匹配不正确\n");
    return 0;
}



