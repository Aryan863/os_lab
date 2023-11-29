#include <stdio.h>
#include <pthread.h>

int matA[3][3] = {{2, 2, 2},
                  {2, 2, 2},
                  {2, 2, 2}};

int matB[3][3] = {{3, 2, 2},
                  {3, 3, 2},
                  {2, 2, 2}};

int matC[3][3] = {{0, 0, 0},
                  {0, 0, 0},
                  {0, 0, 0}};

int ROW = 3;
int COLUMN = 3;
int MAX_THREADS = 3;
int k = 0;

void display(int mat[ROW][COLUMN])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void *mat_mul(void *arg)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matC[k][i] += (matA[k][j] * matB[j][i]);
        }
    }

    k++;
}

void *mat_add(void *arg)
{

    for (int i = 0; i < ROW; i++)
    {

        matC[k][i] = (matA[k][i] + matB[k][i]);
    }

    k++;
}

void *mat_sub(void *arg)
{

    for (int i = 0; i < ROW; i++)
    {

        matC[k][i] = (matA[k][i] - matB[k][i]);
    }

    k++;
}

int main()
{

    int ch;
    printf("\nEnter operation- \n1. Mul\n2. Add\n3. Sub\n");
    scanf("%d", &ch);

    int max_threads = MAX_THREADS;
    switch (ch)
    {
    case 1:
    {
        k = 0;
        printf("matrix A-\n");
        display(matA);

        printf("matrix B-\n");
        display(matB);

        pthread_t mul_th[max_threads];
        for (int i = 0; i < max_threads; i++)
        {
            int ret;
            ret = pthread_create(&mul_th[i], NULL, mat_mul, NULL);
            if (ret == 0)
                printf("\nThread%d created successfully", i);
            else
                printf("\nThread%d not created", i);
        }

        for (int i = 0; i < max_threads; i++)
        {
            pthread_join(mul_th[i], NULL);
        }

        printf("\nmatrix C-\n");
        display(matC);
        pthread_exit(NULL);
        break;
    }
    case 2:
    {
        k = 0;
        printf("matrix A-\n");
        display(matA);

        printf("matrix B-\n");
        display(matB);

        pthread_t add_th[max_threads];
        for (int i = 0; i < max_threads; i++)
        {

            int ret;
            ret = pthread_create(&add_th[i], NULL, mat_add, NULL);
            if (ret == 0)
                printf("\nThread%d created successfully", i);
            else
                printf("\nThread%d not created", i);
        }

        for (int i = 0; i < max_threads; i++)
        {
            pthread_join(add_th[i], NULL);
        }

        printf("\nmatrix C-\n");
        display(matC);
        break;
    }
    case 3:
    {
        k = 0;
        printf("matrix A-\n");
        display(matA);

        printf("matrix B-\n");
        display(matB);

        pthread_t sub_th[max_threads];
        for (int i = 0; i < max_threads; i++)
        {

            int ret;
            ret = pthread_create(&sub_th[i], NULL, mat_sub, NULL);
            if (ret == 0)
                printf("\nThread%d created successfully", i);
            else
                printf("\nThread%d not created", i);
        }

        for (int i = 0; i < max_threads; i++)
        {
            pthread_join(sub_th[i], NULL);
        }

        printf("\nmatrix C-\n");
        display(matC);

        break;
    }

    default:
        break;
    }
}
