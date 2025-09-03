#include "process.h"
#include "utils.h"
#include <vector>
#include <algorithm>

void fcfs(std::vector<Process> processes) {
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrival_time < b.arrival_time;
    });
    int time = 0;
    std::vector<std::pair<int, int>> timeline;
    for (auto &p : processes) {
        if (time < p.arrival_time) time = p.arrival_time;
        p.start_time = time;
        time += p.burst_time;
        p.completion_time = time;
        timeline.push_back({p.pid, p.start_time});
    }
    showStats(processes, timeline);
}