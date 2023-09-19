/*
CPU Task Scheduler (https://www.codingninjas.com/studio/problems/cpu-task-scheduler_2248081?leftPanelTab=3)

There is a multi-core CPU. A single-core in this CPU can execute only a single task at a given time, so if two tasks need to be executed simultaneously, we will need at least two different cores to process them.

You have been given a list of ‘N’ tasks that need to be executed, this list contains starting and ending times of each task.

Find out the minimum number of cores required in this CPU so that all the tasks can be executed at their scheduled time.

ex:
If N = 4 and the timestamps of the tasks are: { {0,10}, {5,20}, {10,25}, {30,40} }
Then the minimum number of cores required is equal to 2. 
Task-1 will arrive at 0 and core-1 will execute it till 10.
Task-2 will arrive at 5 and as core-1 is busy executing task-1, so core-2 will be assigned and it will execute this task till 20
Task-3 will arrive at 10, core-1 has just finished executing task-1 and is now free, so core-1 will execute this task till 25.
Task-4 will arrive at 30, both core-1 and core-2 are free and any one of them will execute this task.

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cpuTaskScheduler(int n, vector<vector<int>> arr) {
   // Write your code here
   
    vector<pair<int,bool>> task;
    for(int i=0; i<n; i++){
        task.push_back({arr[i][0], 1});
        task.push_back({arr[i][1], 0});
    }

    sort(task.begin(), task.end(), [](const pair<int,bool> &p1, const pair<int,bool> &p2){
        return p1.first < p2.first;
    });

    int max_machines = 0;
    int num_machines = 0;
    for(int i=0; i<task.size(); i++){
        if(task[i].second){
            num_machines += 1;
        }else{
            num_machines -= 1;
        }

        if(num_machines>max_machines)
            max_machines = num_machines;
    }

   return max_machines;
}