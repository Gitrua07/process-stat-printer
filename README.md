# process-stat-printer

## Description
A program that accesses the /proc folder and outputs the statistics about the process and operating system that is running the program environment. 
Implements user input and file access methods to implement the program using C. 

### Program Output with No Argument
Outputs the following things about the operating system:
* CPU Model Name
* Number of cores
* Version of linux executing current environment
* Total memory available to system (Kb)
* Amount of time the system has been running represented using days, hours, minutes, and seconds (uptime)

### Program Output with Number Argument
Outputs the following things about the environment's current process: 
* Name of process
* Console command that started the process (only if it exists)
* Number of threads running the process
* Number of context-switches during process execution


