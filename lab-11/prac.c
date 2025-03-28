//Posix thread api
#include<pthread.h>
#include<stdio.h>
void* thf(void* arg){
	printf("Inside thread\n");
	//printf(t_id);
	return NULL;
}
int main(){
	pthread_t t_id;//thread id
	printf("Before thread\n");
	pthread_create(&t_id,NULL/*system takes null parameter*/,thf,NULL/*parameters pass to fun*/);
        pthread_join(t_id,NULL);//when thread ends it joins to the current process
	printf("After thread\n");
}
/*
pthread_exit(void* n);
pthread_self(void); shows the id of current thread
pthread_equal(t1,t2);
pthread_detach(tid);
*/
