#include "process.h"
#include "utils.h"
#include <vector>

void sjf(std::vector<Process> processes) {
    int time = 0, completed = 0, n = processes.size();
    std::vector<std::pair<int, int>> timeline;
    std::vector<bool> visited(n, false);

    while (completed < n) {
        int idx = -1, min_bt = 1e9;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && !visited[i] && processes[i].burst_time < min_bt) {
                min_bt = processes[i].burst_time;
                idx = i;
            }
        }
        if (idx != -1) {
            visited[idx] = true;
            processes[idx].start_time = time;
            time += processes[idx].burst_time;
            processes[idx].completion_time = time;
            timeline.push_back({processes[idx].pid, processes[idx].start_time});
            completed++;
        } else {
            time++;
        }
    }
    showStats(processes, timeline);
}