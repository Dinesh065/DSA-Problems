#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Process
{
    string process_name;
    int arrival_time;
    int burst_time;
    int priority;
};

void waiting_times_fcfs(vector<Process> &processes, vector<int> &waiting_times)
{
    waiting_times[0] = 0;

    for (size_t i = 1; i < processes.size(); ++i)
    {
        waiting_times[i] = processes[i - 1].burst_time + waiting_times[i - 1];
    }
}

void waiting_times_sjf(vector<Process> &processes, vector<int> &waiting_times)
{
    int n = processes.size();
    vector<int> remaining_burst_times(n);
    for (int i = 0; i < n; ++i)
    {
        remaining_burst_times[i] = processes[i].burst_time;
    }
    int current_time = 0;
    int completed = 0;

    while (completed != n)
    {
        int min_burst = INT_MAX;
        int min_index = -1;

        for (int i = 0; i < n; ++i)
        {
            if (processes[i].arrival_time <= current_time && remaining_burst_times[i] < min_burst && remaining_burst_times[i] > 0)
            {
                min_burst = remaining_burst_times[i];
                min_index = i;
            }
        }

        if (min_index == -1)
        {
            current_time++;
            continue;
        }

        remaining_burst_times[min_index]--;
        current_time++;

        if (remaining_burst_times[min_index] == 0)
        {
            completed++;
            waiting_times[min_index] = current_time - processes[min_index].burst_time - processes[min_index].arrival_time;
        }
    }
}

void waiting_times_priority(vector<Process> &processes, vector<int> &waiting_times)
{
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         { return a.priority < b.priority; });
    waiting_times_fcfs(processes, waiting_times);
}

void waiting_times_rr(vector<Process> &processes, int quantum, vector<int> &waiting_times)
{
    int n = processes.size();
    vector<int> remaining_burst_times(n);
    for (int i = 0; i < n; ++i)
    {
        remaining_burst_times[i] = processes[i].burst_time;
    }
    int current_time = 0;

    while (true)
    {
        bool done = true;

        for (int i = 0; i < n; ++i)
        {
            if (remaining_burst_times[i] > 0)
            {
                done = false;

                if (remaining_burst_times[i] > quantum)
                {
                    current_time += quantum;
                    remaining_burst_times[i] -= quantum;
                }
                else
                {
                    current_time += remaining_burst_times[i];
                    waiting_times[i] = current_time - processes[i].burst_time;
                    remaining_burst_times[i] = 0;
                }
            }
        }

        if (done)
            break;
    }
}

double find_average_waiting_time(vector<Process> &processes, const string &algorithm)
{
    int n = processes.size();
    vector<int> waiting_times(n, 0);

    if (algorithm == "FCFS")
    {
        waiting_times_fcfs(processes, waiting_times);
    }
    else if (algorithm == "SJF")
    {
        waiting_times_sjf(processes, waiting_times);
    }
    else if (algorithm == "Priority")
    {
        waiting_times_priority(processes, waiting_times);
    }
    else if (algorithm == "Round Robin")
    {
        int quantum;
        cout << "Enter time quantum for Round Robin: ";
        cin >> quantum;
        waiting_times_rr(processes, quantum, waiting_times);
    }
    else
    {
        cout << "Invalid algorithm choice." << endl;
        return 0;
    }

    int total_waiting_time = 0;
    for (int wt : waiting_times)
    {
        total_waiting_time += wt;
    }
    return static_cast<double>(total_waiting_time) / n;
}

int main()
{
    vector<Process> processes = {
        {"P1", 0, 5, 3},
        {"P2", 1, 3, 1},
        {"P3", 2, 8, 4},
        {"P4", 3, 6, 2},
        {"P5", 4, 4, 5}};

    vector<string> algorithms = {"FCFS", "SJF", "Priority", "Round Robin"};

    for (const string &algorithm : algorithms)
    {
        double avg_waiting_time = find_average_waiting_time(processes, algorithm);
        cout << "Average waiting time using " << algorithm << ": " << avg_waiting_time << endl;
    }

    return 0;
}
