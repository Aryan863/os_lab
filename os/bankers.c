#include <stdio.h>
int main()
{
    int i, j, k, pc, rc;
    printf("Enter no of processes:\n");
    scanf("%d", &pc);
    printf("Enter no of resources:\n");
    scanf("%d", &rc);

    int max_req[pc][rc], allocated[pc][rc], rem_need[pc][rc], available[rc];

    printf("Enter maximum requirement of each process:\n");
    for (i = 0; i < pc; i++)
    {
        for (j = 0; j < rc; j++)
        {
            scanf("%d", &max_req[i][j]);
        }
    }

    printf("Enter allocated resources of each process:\n");
    for (i = 0; i < pc; i++)
    {
        for (j = 0; j < rc; j++)
        {
            scanf("%d", &allocated[i][j]);
            rem_need[i][j] = max_req[i][j] - allocated[i][j];
        }
    }

    printf("Enter available resources:\n");
    for (j = 0; j < rc; j++)
        scanf("%d", &available[j]);

    int finish[pc], safe_seq[pc], index = 0;
    for (k = 0; k < pc; k++)
    {
        finish[k] = 0;
    }

    int y = 0;
    for (k = 0; k < pc; k++)
    {
        for (i = 0; i < pc; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < rc; j++)
                {
                    if (rem_need[i][j] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    safe_seq[index++] = i;
                    for (y = 0; y < rc; y++)
                        available[y] = available[y] + allocated[i][y];

                    finish[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < pc; i++)
    {
        if (finish[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }

    if (flag == 1)
    {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < pc - 1; i++)
            printf(" P%d ->", safe_seq[i]);
        printf(" P%d", safe_seq[pc - 1]);
    }

    return (0);
}