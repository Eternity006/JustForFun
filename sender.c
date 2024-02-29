#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include"msg.h"
void reverse(int m, char* ch)
{
	int d=m;
	int c=0;
	int rev=0;
	while(d!=0)
	{
		c=d%10;
		rev=rev*10+c;
		d=d/10;
	}
	for(int  i=3;i>=0;i--){
		ch[i]=rev%10+'0';
		rev=rev/10;
	}
}
int main(){
	int mqid;
	int n;
	mqid=msgget(1234, IPC_CREAT|0666);
	MQ msg1;
	msg1.mtype=1;
	printf("enter the number");
	scanf("%d", &n);
	char ch[4];
	reverse(n,ch);
	strcpy(msg1.mdata, ch);
	msgsnd(mqid,&msg1, datasize, 0);
	printf("data send\n");	
}
