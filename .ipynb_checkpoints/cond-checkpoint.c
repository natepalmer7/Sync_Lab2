#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;


int value = 100;

void* reporter(void* unused) {
    /*
      your code here
    */
    printf("The value is %d\n", value);
    /*
     your line of code here
    */
    return NULL;
}

void* assigner(void* unused) {
    value = 20;
    /*
      your code here
    */
    return NULL;
}

int main(int argc, char** argv) {
    pthread_t rep, asgn;

    pthread_create(&rep, NULL, reporter, NULL);
    pthread_create(&asgn, NULL, assigner, NULL);

    void* unused;

    pthread_join(rep, &unused);
    pthread_join(asgn, &unused);
    return 0;
}
