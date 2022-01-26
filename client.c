#include <sys/types.h>
#include <sys/ipc.h> //interprocess communication access structure
#include <sys/msg.h> //message queue structures
#include <stdio.h>   //input/output
#include <string.h>  //string
#include <stdlib.h>  //

typedef struct msgbuf//krijimi i struktures me emrin msgbuf
{
long mtype;// deklarohet nje variabel e tipit long
char mtext[100];//deklarohet nje array me 100 anetare
}
message_buf;//deklarimi  i nje variable te struktures
int main()
{
int msqid; // ID e radhës së mesazhit. Vlera e kthyer nga msgget()
key_t key; //çelësi i segmentit, i cili kalon te funksioni msgget()
message_buf sbuf;//deklarimi i nje variable te tipit msgbuf
size_t buf_length;//deklarimi i variables buf_length te tipit size_t qe do te thote se nuk prann vlera me te vogla se 0

key = 1234;// gjenerimi i çelesit unik, i krijuar nga serveri

msqid = msgget(key, IPC_CREAT|0666);// IPC_CREAT – krijon një radhë të mesazhit nëse nuk ekziston fillimisht

sbuf.mtype = 1;// definon mesazhin për dërgim
strcpy(sbuf.mtext, "Tungjatjeta");//vendoset vlera tungjatjeta tek variabla mtext
buf_length = strlen(sbuf.mtext) + 1 ;//inicializimi i variables buf_length

msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT);//dergohet mesazhi ne server 
printf("Mesazhi: %s u dergua\n" ,sbuf.mtext);//printohet mesazhi i derguar
exit(0);
}
