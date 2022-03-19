# memory_communication

## Compilation
Compile with "make", remove created files with "make clean". 

## Graph
Graph comparing time to read given buffer size: 
![image](https://user-images.githubusercontent.com/22458179/159110523-63cffe8f-96d0-4157-84a3-c5a4c248d129.png)


## Analysis
Based on the graph, my cache sizes are around 3MB, as we see a significant increase in time to read between 2097152B (~2MB) and 4194304B (~4MB). This lines up with what cpuinfo said, which states that each cache is 3MB. 
