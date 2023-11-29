#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

sem_t reader_sem;
sem_t writer_sem;
int shared_resource = 0;
int reader_count = 0;

void *reader(void *arg)
{
    while (1)
    {
        sem_wait(&reader_sem);
        reader_count++;
        if (reader_count == 1)
        {
            sem_wait(&writer_sem);
        }
        sem_post(&reader_sem);

        // Read the shared resource
        printf("Reader %d read: %d\n", *((int *)arg), shared_resource);

        sem_wait(&reader_sem);
        reader_count--;
        if (reader_count == 0)
        {
            sem_post(&writer_sem);
        }
        sem_post(&reader_sem);

        // Simulate reading time
        sleep(2);
    }
}

void *writer(void *arg)
{
    while (1)
    {
        sem_wait(&writer_sem);

        // Write to the shared resource
        shared_resource++;
        printf("Writer %d wrote: %d\n", *((int *)arg), shared_resource);

        sem_post(&writer_sem);

        // Simulate writing time
        sleep(1);
    }
}

int main()
{
    pthread_t reader_threads[NUM_READERS];
    pthread_t writer_threads[NUM_WRITERS];
    int i;

    int reader_ids[NUM_READERS];
    int writer_ids[NUM_WRITERS];

    sem_init(&reader_sem, 0, 1);
    sem_init(&writer_sem, 0, 1);

    for (i = 0; i < NUM_READERS; i++)
    {
        reader_ids[i] = i + 1;
        pthread_create(&reader_threads[i], NULL, reader, &reader_ids[i]);
    }

    for (i = 0; i < NUM_WRITERS; i++)
    {
        writer_ids[i] = i + 1;
        pthread_create(&writer_threads[i], NULL, writer, &writer_ids[i]);
    }

    for (i = 0; i < NUM_READERS; i++)
    {
        pthread_join(reader_threads[i], NULL);
    }

    for (i = 0; i < NUM_WRITERS; i++)
    {
        pthread_join(writer_threads[i], NULL);
    }

    sem_destroy(&reader_sem);
    sem_destroy(&writer_sem);

    return 0;
}
