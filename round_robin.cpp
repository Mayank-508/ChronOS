#include "process.h"
#include "utils.h"
#include <vector>
#include <queue>
#include <algorithm>

void roundRobin(std::vector<Process> processes, int quantum) {
    int time = 0, n = processes.size();
    std::vector<std::pair<int, int>> timeline;
    std::queue<int> q;
    std::vector<bool> inQueue(n, false);

    std::sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrival_time < b.arrival_time;
    });

    q.push(0);
    inQueue[0] = true;

    while (!q.empty()) {
        int idx = q.front(); q.pop();
        if (processes[idx].arrival_time > time) time = processes[idx].arrival_time;
        timeline.push_back({processes[idx].pid, time});
        int run_time = std::min(quantum, processes[idx].remaining_time);
        processes[idx].remaining_time -= run_time;
        time += run_time;

        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                q.push(i);
                inQueue[i] = true;
            }
        }
        if (processes[idx].remaining_time > 0) q.push(idx);
        else processes[idx].completion_time = time;
    }
    showStats(processes, timeline);
}

