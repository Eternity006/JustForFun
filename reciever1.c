#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include"msg.h"
int main(){
	int mqid=msgget(123, IPC_CREAT|0666);
	MQ msg1;
	msgrcv(mqid, &msg1, datasize, 1, 0);
	printf("recieved :%s\n", msg1.mdata);
}

