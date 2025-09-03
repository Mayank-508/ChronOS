#ifndef PROCESS_H
#define PROCESS_H

struct Process {
    int pid, arrival_time, burst_time, remaining_time, priority;
    int start_time = -1, completion_time = 0, waiting_time = 0, turnaround_time = 0;
};

#endif
