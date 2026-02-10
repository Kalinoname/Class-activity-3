#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 12

void* worker(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d started (pthread id: %lu)\n", id, (unsigned long)pthread_self());
    sleep(10); // keep thread alive for visualization
    printf("Thread %d exiting\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, worker, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All macOS threads finished.\n");
    return 0;
}
