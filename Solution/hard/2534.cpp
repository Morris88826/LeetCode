/*
2534. Time Taken to Cross the Door (https://leetcode.com/problems/time-taken-to-cross-the-door/description/)

There are n persons numbered from 0 to n - 1 and a door. Each person can enter or exit through the door once, taking one second.
You are given a non-decreasing integer array arrival of size n, where arrival[i] is the arrival time of the ith person at the door. You are also given an array state of size n, where state[i] is 0 if person i wants to enter through the door or 1 if they want to exit through the door.
If two or more persons want to use the door at the same time, they follow the following rules:

If the door was not used in the previous second, then the person who wants to exit goes first.
If the door was used in the previous second for entering, the person who wants to enter goes first.
If the door was used in the previous second for exiting, the person who wants to exit goes first.
If multiple persons want to go in the same direction, the person with the smallest index goes first.
Return an array answer of size n where answer[i] is the second at which the ith person crosses the door.

Note that:

Only one person can cross the door at each second.
A person may arrive at the door and wait without entering or exiting to follow the mentioned rules.
 

Example 1:

Input: arrival = [0,1,1,2,4], state = [0,1,0,0,1]
Output: [0,3,1,2,4]
Explanation: At each second we have the following:
- At t = 0: Person 0 is the only one who wants to enter, so they just enter through the door.
- At t = 1: Person 1 wants to exit, and person 2 wants to enter. Since the door was used the previous second for entering, person 2 enters.
- At t = 2: Person 1 still wants to exit, and person 3 wants to enter. Since the door was used the previous second for entering, person 3 enters.
- At t = 3: Person 1 is the only one who wants to exit, so they just exit through the door.
- At t = 4: Person 4 is the only one who wants to exit, so they just exit through the door.
Example 2:

Input: arrival = [0,0,0], state = [1,0,1]
Output: [0,2,1]
Explanation: At each second we have the following:
- At t = 0: Person 1 wants to enter while persons 0 and 2 want to exit. Since the door was not used in the previous second, the persons who want to exit get to go first. Since person 0 has a smaller index, they exit first.
- At t = 1: Person 1 wants to enter, and person 2 wants to exit. Since the door was used in the previous second for exiting, person 2 exits.
- At t = 2: Person 1 is the only one who wants to enter, so they just enter through the door.
 

Constraints:
n == arrival.length == state.length
1 <= n <= 105
0 <= arrival[i] <= n
arrival is sorted in non-decreasing order.
state[i] is either 0 or 1.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:

    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int n = arrival.size();
        vector<int> result(n);
        queue<pair<int,int>> enter, exit;

        for(int i=0; i<n; i++){
            (state[i]==0)? enter.push(make_pair(i, arrival[i])) : exit.push(make_pair(i, arrival[i]));
        }

        int time = 0;
        while(!enter.empty()&&!exit.empty()){
            time = max(time, min(enter.front().second, exit.front().second));
            if(exit.front().second <= enter.front().second){
                while(!exit.empty() && exit.front().second<=time){
                    result[exit.front().first] = time;
                    time++;
                    exit.pop();
                }
            }else{
                while(!enter.empty() && enter.front().second <=time){
                    result[enter.front().first] = time;
                    time++;
                    enter.pop();
                }
            }
        }

        while(!exit.empty()){
            time = max(exit.front().second, time);
            result[exit.front().first] = time;
            time++;
            exit.pop();
        }

        while(!enter.empty()){
            time = max(enter.front().second, time); // maybe not arrive yet for current time
            result[enter.front().first] = time;
            time++;
            enter.pop();
        }

        return result;
    }


    vector<int> timeTaken_v1(vector<int>& arrival, vector<int>& state) {
        
        map<int, vector<int>> groups;
        for(int i=0; i<arrival.size(); i++){
            groups[arrival[i]].push_back(i);
        }

        int previous = 1;
        int n = arrival.size();
        vector<int> sequence(n, -1);
        queue<int> waiting_enter;
        queue<int> waiting_leave;
        int previous_t = 0;
        int current_t = 0;
        for(auto g : groups){
            for(int i=current_t+1; i<g.first; i++){
                if(waiting_leave.empty() && waiting_enter.empty()){
                    previous = 1;
                    break;
                }

                if((previous==0 || waiting_leave.empty())&&(!waiting_enter.empty())){
                    sequence[waiting_enter.front()] = i;
                    waiting_enter.pop();
                    previous = 0;
                }else if(!waiting_leave.empty()){
                    sequence[waiting_leave.front()] = i;
                    waiting_leave.pop();
                    previous = 1;
                }
            }

            current_t = g.first;
            for(auto v: g.second){
                if(state[v]==0){
                    waiting_enter.push(v);
                }else{
                    waiting_leave.push(v);
                }
            }

            if((previous==0 || waiting_leave.empty())&&(!waiting_enter.empty())){
                sequence[waiting_enter.front()] = current_t;
                waiting_enter.pop();
                previous = 0;
            }else if(!waiting_leave.empty()){
                sequence[waiting_leave.front()] = current_t;
                waiting_leave.pop();
                previous = 1;
            }
        }

        current_t += 1;
        while(!waiting_enter.empty() || !waiting_leave.empty()){            
            if((previous==0 || waiting_leave.empty())&&(!waiting_enter.empty())){
                sequence[waiting_enter.front()] = current_t;
                waiting_enter.pop();
                previous = 0;
            }else if(!waiting_leave.empty()){
                sequence[waiting_leave.front()] = current_t;
                waiting_leave.pop();
                previous = 1;
            }
            current_t += 1;
        }

        return sequence;
    }
};