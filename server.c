#include <sys/types.h>
#include <sys/ipc.h>  //interprocess communication access structure
#include <sys/msg.h>  //message queue structures
#include <stdio.h>    //input/output
#include <stdlib.h>

typedef struct msgbuf//krijimi i struktures me emrin msgbuf
{
long mtype;//deklarohet nje variabel e tipit long
char mtext[100];//deklarohet nje array me 100 anetare
}
message_buf;//deklarimi  i nje variable te struktures
int main()
{
int msqid;// ID e radhës së mesazhit. Vlera e kthyer nga msgget()
key_t key;//çelësi i segmentit, i cili kalon te funksioni msgget()
message_buf rbuf;//deklarimi i nje variable te tipit msgbuf
key = 1234;// gjenerimi i çelesit unik, i krijuar nga serveri
msqid = msgget(key, 0666);//krijohet nje radhe nese ne fillim nuk ekziston nje e tille

msgrcv(msqid, &rbuf, 100, 1, 0);//Pranon nje pergjigje te mesazhit type 1
//1 (parametri i parafundit) – tipi i mesazhit
// 0 (parametri i fundit) – flag i mesazhit
printf("Mesazhi: %s u pranua\n", rbuf.mtext);//printohet mesazhi i cili eshte pranuar
exit(0);
}