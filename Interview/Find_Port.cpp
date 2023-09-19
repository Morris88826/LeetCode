/* 
Find_Port

Packets are sent to different ports on a computer system based on the hash of their packetID, the value of the hash is given below: 
Hash=mod(packet_id, numberOfPorts) where mod is the modulus operator. 

packetIDs comes at every second, i.e. t=0 packetIDs[0], t=1 packetIDs[1], ...
Each transmission takes TransmissionTime to complete, and if the port is currently being used, use the next available port.

ex:
We assume we have packetIDs=[1,4,7,9] and numberOfPorts=3. We can calculate the Hash=[1,1,1,0]. These arrive at time 1,2,3,4. 
The first packet is sent to port 1 with no conflicts. Port1 will be occupied at times1 and 2 due to the transimssion time.
So the second packet has a conflict is sent to port 1+1=2. The 3rd packet wants to go to port 1 and arrives at time 3. 
Since port1 is no longer transimtting packet, it receives the 3rd packet. The 4th pack goes to port0 without conflicts.
The return array is[1,2,1,0]
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findPort(vector<int> packetIDs, int numberOfPorts, int TransmissionTime) {
   
}