#include <iostream>
#include "utils.h"
using namespace std;

void printGanttChart(const vector<pair<int, int>>& timeline) {
    cout << "\nGantt Chart:\n";
    for (auto [pid, _] : timeline) cout << "| P" << pid << " ";
    cout << "|\n";
    for (auto [_, time] : timeline) cout << time << "    ";
    cout << endl;
}

void showStats(vector<Process>& processes, const vector<pair<int, int>>& timeline) {
    printGanttChart(timeline);
    float total_wt = 0, total_tat = 0;
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &p : processes) {
        p.turnaround_time = p.completion_time - p.arrival_time;
        p.waiting_time = p.turnaround_time - p.burst_time;
        total_tat += p.turnaround_time;
        total_wt += p.waiting_time;
        cout << "P" << p.pid << "\t" << p.arrival_time << "\t" << p.burst_time << "\t"
             << p.completion_time << "\t" << p.turnaround_time << "\t" << p.waiting_time << endl;
    }
    cout << "Average Waiting Time: " << total_wt / processes.size() << endl;
    cout << "Average Turnaround Time: " << total_tat / processes.size() << endl;
}


