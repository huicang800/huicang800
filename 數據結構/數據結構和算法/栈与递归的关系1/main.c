//
//  main.c
//  栈与递归的关系1
//
//  Created by Apple on 4/16/20.
//  Copyright © 2020 ojoj. All rights reserved.
//

#include <stdio.h>


int Fbi(long i){
    if(i<2)
        return i == 0?0:1;
    return Fbi(i-1)+Fbi(i-2);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("斐波拉契数列!\n");
    // 1 1 2 3 5 8 13 21 34 55 89 144
    for (long i =0; i < 100000000000; i++) {
         printf("%d  ",Fbi(i));
    }
    printf("\n");
   
    return 0;
}
