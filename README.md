# CS441/541 Scheduling Project

## Author(s):

Kyle McElligott


## Date:

02/18/2020


## Description:

This program simulates four different scheduling algorithms: First-Come, First-Served (FCFS), Shortest-Job First (SJF), Priority, and Round-Robin (RR). The program takes a number of processes and a scheduling algorithm, provided by the user, and calculates the average Waiting and Turnaround times. If RR is the chosen algorithm an additional quantum parameter is required.


## How to build the software

Built with Makefile.  Simply move to 'scheduling' directory in the terminal and type 'make'.


## How to use the software

After the software is built run the program with

'./scheduler -s xx xxxxxx.txt -q xx'

There are four options associated with the -s parameter:
  -s 1 -> FCFS
  -s 2 -> SJF
  -s 3 -> Priority
  -2 4 -> RR

The txt file format must start with a number signifying the number of processes. The following lines indicate the process ID, CPU burst, and priority.

The -q parameter is only required for RR and is ignored if provided with any other algorithm.


## How the software was tested

(See 'tests' directory.)

## Test Suite

(See 'tests' directory.)


## Known bugs and problem areas

RoundRobin scheduling algorithm incorrect.
