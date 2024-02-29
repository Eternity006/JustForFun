
#define STORAGE_H
#include<stdio.h>
#include<string.h>
#define datasize 4
#define MQKEY 1234
typedef struct{
	long mtype;
	char mdata[datasize];
}MQ;

