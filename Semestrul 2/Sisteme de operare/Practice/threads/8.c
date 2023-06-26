#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int k, n, v[80000], fr[10], sum = 0;
pthread_t citire, thr[10];
pthread_barrier_t barr;
pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;

void* cititor(void* a) {
	int fd = open("random-file", O_RDONLY);
	for(int i = 0; i < n; i++) {
		read(fd, &v[i], 1);
	}
	close(fd);
	return NULL;
}

void* worker(void* arg)
{

        int i,indice=*(int*)arg,cnt=0;
	free(arg);
        for(i=indice*200;i<indice*200+200;i++)
        {
                if(v[i]%k==0) cnt++;
        }

//        pthread_mutex_lock(&mtx);
        sum=sum+cnt;
  //      pthread_mutex_unlock(&mtx);

    //    pthread_barrier_wait(&barr);
        printf("INTERVAL: %d - %d -> %d\n",indice*200,indice*200+200,cnt);
        return NULL;
}
int main(int argc, char**argv)
{
        printf("introduceti n si k: ");
        scanf("%d %d",&n,&k);
        int i;
      //  pthread_mutex_init(&mtx,NULL);

       // pthread_barrier_init(&barr,NULL,10);

        pthread_create(&citire,NULL,cititor,NULL);
        pthread_join(citire,NULL);

        for(i=0;i<=9;i++)
        {

        int* aux=(int*)malloc(sizeof(int));
        *aux=i;
        pthread_create(&thr[i],NULL,worker,aux); //dau i ca si argument
        }

        for(i=0;i<=9;i++)
                pthread_join(thr[i],NULL);

     //   pthread_mutex_destroy(&mtx);

        printf("TOTAL: %d\n",sum);

        return 0;
}
