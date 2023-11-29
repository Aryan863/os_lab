#include <stdio.h>

void findWaitingTime(int burst_time[], int waiting_time[], int quantum, int n)
{
    int i, remaining_time[n];
    for (i = 0; i < n; i++)
    {
        remaining_time[i] = burst_time[i];
    }
    int time = 0;
    while (1)
    {
        int done = 1;
        for (i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0)
            {
                done = 0;
                if (remaining_time[i] > quantum)
                {
                    time += quantum;
                    remaining_time[i] -= quantum;
                }
                else
                {
                    time += remaining_time[i];
                    waiting_time[i] = time - burst_time[i];
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1)
        {
            break;
        }
    }
}

void findTurnAroundTime(int burst_time[], int waiting_time[], int turn_around_time[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        turn_around_time[i] = burst_time[i] + waiting_time[i];
    }
}

void findAverageTime(int burst_time[], int quantum, int n)
{
    int waiting_time[n], turn_around_time[n], total_waiting_time = 0, total_turn_around_time = 0;
    int i;

    findWaitingTime(burst_time, waiting_time, quantum, n);
    findTurnAroundTime(burst_time, waiting_time, turn_around_time, n);

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    printf("Average waiting time = %f\n", (float)total_waiting_time / (float)n);
    printf("Average turnaround time = %f", (float)total_turn_around_time / (float)n);
}

int main()
{
    int burst_time[10], quantum, n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    findAverageTime(burst_time, quantum, n);

    return 0;
}
