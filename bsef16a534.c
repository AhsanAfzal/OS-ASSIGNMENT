#include<stdio.h>

#include<pthread.h>

#include<stdlib.h>




int ar[1000];


void* sum(void*  arg)

{
 int sum=0;
for(int a=(int)arg;a<(int)arg+100;a++)
{
sum+=ar[a];
}
return (void*)sum;
}



int main()

{

for(int a=0;a<1000;a++)

ar[a]=a;


pthread_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;

pthread_create(&t1,NULL,sum,(void*)0);


pthread_create(&t2,NULL,sum,(void*)100);

pthread_create(&t3,NULL,sum,(void*)200);

pthread_create(&t4,NULL,sum,(void*)300);

pthread_create(&t5,NULL,sum,(void*)400);

pthread_create(&t6,NULL,sum,(void*)500);

pthread_create(&t7,NULL,sum,(void*)600);

pthread_create(&t8,NULL,sum,(void*)700);

pthread_create(&t9,NULL,sum,(void*)800);

pthread_create(&t10,NULL,sum,(void*)900);

 int *b[10];int s=0;


pthread_join(t1,(int*)&b[0]);

pthread_join(t2,(int*)&b[1]);

pthread_join(t3,(int*)&b[2]);

pthread_join(t4,(int*)&b[3]);

pthread_join(t5,(int*)&b[4]);

pthread_join(t6,(int*)&b[5]);

pthread_join(t7,(int*)&b[6]);

pthread_join(t8,(int*)&b[7]);

pthread_join(t9,(int*)&b[8]);

pthread_join(t10,(int*)&b[9]);


for(int i=0;i<10;i++)

{
void *t=(void*)b[i];

int itemp=(int*)t;
s+=itemp;
}

printf("%d",s);

}