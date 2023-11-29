#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

pthread_mutex_t reader_sem;
pthread_mutex_t writer_sem;
int shared_resource = 0;
int reader_count = 0;

void *reader(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&reader_sem);
        reader_count++;
        if (reader_count == 1)
        {
            pthread_mutex_lock(&writer_sem);
        }
        pthread_mutex_unlock(&reader_sem);

        // Read the shared resource
        printf("Reader %d read: %d\n", *((int *)arg), shared_resource);

        pthread_mutex_lock(&reader_sem);
        reader_count--;
        if (reader_count == 0)
        {
            pthread_mutex_unlock(&writer_sem);
        }
        pthread_mutex_unlock(&reader_sem);

        // Simulate reading time
        sleep(2);
    }
}

void *writer(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&writer_sem);

        // Write to the shared resource
        shared_resource++;
        printf("Writer %d wrote: %d\n", *((int *)arg), shared_resource);

        pthread_mutex_unlock(&writer_sem);

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

    pthread_mutex_init(&reader_sem, NULL);
    pthread_mutex_init(&writer_sem, NULL);

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

    return 0;
}
