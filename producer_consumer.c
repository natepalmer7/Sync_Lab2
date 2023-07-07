#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>


#define MAXX 5 // maximum items a producer can produce or a consumer can consume
#define BUFFSIZE 5 

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

//our buffer here is a *circular queue* (recall your data structures notes)
int in = 0;
int out = 0;
int buffer[BUFFSIZE];


/* wait, lock, place a random number in the buffer, unlock, post*/
void *producer(void *pno)
{   
    int item;
    for(int i = 0; i < MAXX; i++) {
        item = rand(); // random item
        //your code here
        //your code here
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
        in = (in+1)%BUFFSIZE; // circular buffer arithmetic
        //your code here
        //your code here
    }
}
/* wait, lock, remove an item from the buffer, unlock, post*/
void *consumer(void *cno)
{   
    for(int i = 0; i < MAXX; i++) {
        //your code here
        //your code here
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
        out = (out+1)%BUFFSIZE; // circular buffer arithmetic
        //your code here
        //your code here
    }
}

/*
NOTE: This is skeleton code that won't compile. Your job is to make it compile and solve the producer/consumer problem.
*/

int main()
{   

    pthread_t pro[5],con[5];
    
    // Initialize your mutex and semaphores (see pthread_mutex_init, sem_init)


    int a[5] = {1,2,3,4,5}; // used for numbering the producer and consumer (and gives an example of passing params as void*)

    for(int i = 0; i < 5; i++) {
        pthread_create(/* your code here*/, NULL, /* your code here*/, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(/* your code here*/, NULL, /* your code here*/, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(con[i], NULL);
    }

    // DON'T FORGET TO DESTROY YOUR MUTEX AND SEMAPHORES! (see pthread_mutex_destroy, sem_destroy)
    // (memory leak otherwise)


    return 0;
    
}
