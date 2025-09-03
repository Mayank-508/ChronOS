#include "process.h"
#include "utils.h"
#include <vector>

void priorityPreemptive(std::vector<Process> processes) {
    int time = 0, completed = 0, n = processes.size();
    std::vector<std::pair<int, int>> timeline;
    int prev = -1;

    while (completed < n) {
        int idx = -1, min_pr = 1e9;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0 && processes[i].priority < min_pr) {
                min_pr = processes[i].priority;
                idx = i;
            }
        }
        if (idx != -1) {
            if (prev != idx) timeline.push_back({processes[idx].pid, time});
            prev = idx;
            processes[idx].remaining_time--;
            if (processes[idx].remaining_time == 0) {
                processes[idx].completion_time = time + 1;
                completed++;
            }
        }
        time++;
    }
    showStats(processes, timeline);
}
