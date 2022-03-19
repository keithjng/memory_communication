# memory_communication

The general idea for this code is to create a random array filled with random values. To ensure there is no pre-fetching, the cache is reset every time it is tested by touching a 4MB string (I had to play around with this number, and this worked best). The program then accesses the random array 10 times and takes the average of the time to read. Finally, the program prints out the time it took. 

## Compilation
Compile with "make", remove created files with "make clean". 

## Graph
Graph comparing time to read given buffer size: 
![image](https://user-images.githubusercontent.com/22458179/159110523-63cffe8f-96d0-4157-84a3-c5a4c248d129.png)


## Analysis
Based on the graph, my cache sizes are around 3MB, as we see a significant increase in time to read between 2097152B (~2MB) and 4194304B (~4MB). This lines up with what cpuinfo said, which states that each cache is 3MB. 
