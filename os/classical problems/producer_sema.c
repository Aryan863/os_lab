#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define PRODUCERS 5
#define CONSUMERS 3

sem_t buffer_mutex;
sem_t full_sem;
sem_t empty_sem;

int buffer[10];
int count = 0;

void *producer(void *arg)
{
    while (1)
    {
        int x = rand() % 100;

        sem_wait(&empty_sem);
        sem_wait(&buffer_mutex);

        buffer[count] = x;
        count++;
        printf("Producer produced %d\n", x);

        if (count == 10)
        {
            printf("Buffer is full\n");
        }

        sem_post(&buffer_mutex);
        sem_post(&full_sem);

        sleep(2);
    }
}

void *consumer(void *arg)
{
    while (1)
    {
        int y;

        sem_wait(&full_sem);
        sem_wait(&buffer_mutex);

        y = buffer[count - 1];
        count--;
        printf("Consumer consumed %d\n", y);

        if (count == 0)
        {
            printf("Buffer is empty\n");
        }

        sem_post(&buffer_mutex);
        sem_post(&empty_sem);

        sleep(1);
    }
}

int main()
{
    pthread_t producer_thread[PRODUCERS];
    pthread_t consumer_thread[CONSUMERS];

    sem_init(&buffer_mutex, 0, 1);
    sem_init(&full_sem, 0, 0);
    sem_init(&empty_sem, 0, 10);

    for (int i = 0; i < PRODUCERS; i++)
    {
        pthread_create(&producer_thread[i], NULL, producer, NULL);
    }

    for (int i = 0; i < CONSUMERS; i++)
    {
        pthread_create(&consumer_thread[i], NULL, consumer, NULL);
    }
    for (int i = 0; i < PRODUCERS; i++)
    {
        pthread_join(producer_thread[i], NULL);
    }
    for (int i = 0; i < CONSUMERS; i++)
    {
        pthread_join(consumer_thread[i], NULL);
    }

    sem_destroy(&buffer_mutex);
    sem_destroy(&full_sem);
    sem_destroy(&empty_sem);

    return 0;
}