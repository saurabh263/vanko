#include <iostream>
using namespace std;

void findwaitingtime(int processes[], int n, int bt[], int wt[], int at[])
{
    wt[0] = 0;
   
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1] - at[i];
        // Ensure waiting time is not negative
        if (wt[i] < 0) {
            wt[i] = 0;
        }
    }
}

void findturnaroundtime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgtime(int processes[], int n, int bt[], int at[])
{
    int wt[n], tat[n];
    int total_wt = 0;
    int total_tat = 0;

    findwaitingtime(processes, n, bt, wt, at);

    findturnaroundtime(processes, n, bt, wt, tat);
  
    cout << "processes  "
         << "arrival_time  "
         << "burst_time  "
         << "Waiting_time "
         << " turn_around_time\n"<<endl;

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << at[i] << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl;
        
    }
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

int main()
{
    int processes[] = {1, 2, 3};
    int burst_t[] = {10, 5, 8};
    int arrival_t[] = {0, 2, 4}; // Example arrival times
    int n = sizeof(processes) / sizeof(processes[0]);
    findavgtime(processes, n, burst_t, arrival_t);
    return 0;
}