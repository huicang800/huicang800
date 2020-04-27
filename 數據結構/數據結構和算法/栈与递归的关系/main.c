//
//  main.c
//  栈与递归的关系
//
//  Created by Apple on 4/16/20.
//  Copyright © 2020 ojoj. All rights reserved.
//

#include <stdio.h>

int m = 0;
void moves(char X,int n,char Y){
    m++;
    printf("%d: from %c ——> %c \n",n,X,Y);
}

//n为当前盘子编号. ABC为塔盘
void Hanoi(int n ,char A,char B,char C){
    
    //目标: 将塔盘A上的圆盘按规则移动到塔盘C上,B作为辅助塔盘;
    
    //将编号为1的圆盘从A移动到C上
    if(n==1) moves(A, 1, C);
    else
    {
        //将塔盘A上的编号为1至n-1的圆盘移动到塔盘B上,C作为辅助塔;
        Hanoi(n-1, A, C, B);
        //将编号为n的圆盘从A移动到C上;
        moves(A, n, C);
        //将塔盘B上的编号为1至n-1的圆盘移动到塔盘C上,A作为辅助塔;
        Hanoi(n-1, B, A, C);
    }
}




int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hanoi 塔问题\n");
    
    
    Hanoi(3, 'A', 'B', 'C');
    printf("盘子数量为3:一共实现搬到次数:%d\n",m);
    
  
    Hanoi(4, 'A', 'B', 'C');
    printf("盘子数量为3:一共实现搬到次数:%d\n",m);
    return 0;
}
