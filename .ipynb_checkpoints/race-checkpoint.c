#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

/* single global variable */
/* shared, accessible, modifiable by all threads */
int accum = 0;
pthread_mutex_t mutex;

void* square(void* x) {
    int xi = (int)x;

    // Acquire the mutex lock
    pthread_mutex_lock(&mutex);

    accum += xi * xi;

    // Release the mutex lock
    pthread_mutex_unlock(&mutex);

    return NULL; /* nothing to return, prevent warning */
}

int main(int argc, char** argv) {
    int i;
    pthread_t ths[20];

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < 20; i++) {
        pthread_create(&ths[i], NULL, square, (void*)(i + 1));
    }

    for (i = 0; i < 20; i++) {
        void* res;
        pthread_join(ths[i], &res);
    }

    printf("accum = %d\n", accum);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
