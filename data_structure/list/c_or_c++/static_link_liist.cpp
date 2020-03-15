/*
 * @Author: Arctic 
 * @Date: 2020-03-15 11:59:13 
 * @Last Modified by: Arctic
 * @Last Modified time: 2020-03-15 12:08:15
 */
// 静态链表
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int Status;
typedef int ElemType;
typedef struct{
    ElemType data;
    int cur;  // 游标指示下格的位置
}
