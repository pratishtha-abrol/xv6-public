# XV6 Updation

## Implemented:
* Addition of Schedulers
    * FCFS Scheduler
    * PBS (Priority Based Scheduler)
    * MLFQ Scheduler (Multi Level Feedback Queue)

* Extending the process structure with
    * run time
    * start time
    * end time
    * priority
    * current queue for MLFQ
    * number of runs

* Custom waitx system call mimicking wait but assigning values of runtime and wait time to argument passed.

* ps, a user function which displays details of all current processes

## System Calls

### waitx system call
It is similar to the wait system call already used, but in addition it takes in two integer arguments ```wtime``` and ```rtime```  
to which the values of the total wait time and total run time of process are assigned respectively.  
To do this proc structure has been extended with:  
    ```stime, rtime, etime```  

* We assume only a process in runnable state to be waiting, a sleeping process does not count for wait as it is a voluntary exit.
* wtime is reset to 0 everytime the scheduler picks it up or every time it changes queue

> use time command on console to invoke waitx system call

### setpriority system call
This system call changes the default process priority to the given priority, the function being ```int setpriority(int priority, int pid)```

> use setPriority command on console to use this system call

### getps system call
This aids the ```ps console command```, collecting all details of the current processes (as long as a process structure is not in UNUSED state) and printing them to the console.
* the default value for current queue is 0, as long as MLFQ scheduler isn't used, in which case, the value updates as per current queue.

> use ps console command to see getps functioning

## Schedulers

### Default
flag : ```SCHEDULER=DEFAULT``` 
This is the round robin mechanism already implemented, in case a SCHEDULER flag isn't provided, the system proceeds with the DEFAULT scheduling policy

### MLFQ
flag : ```SCHEDULER=MLFQ```
We use 5 queues numbered 0 to 4, the lower the number the higher the priority. The processes jum queues as per their current priority and the time spent waiting. 
We count the number of ticks (time) spent in each queue and the current queue of the process.
> This is a **non-preemptive** policy.

### PBS
flag : ```SCHEDULER=PBS```
This is a priority based scheduling mechanism, it picks the process with the highest priority and executes it first.

### FCFS
flag : ```SCHEDULER=FCFS```
USe this scheduler to run processes as per their arrival time. The first process to arrive is the first one executed.

## Results and Observations
We ran the benchark program, set at ```int number_of_processes = 10;``` for each scheduler, arriving at the following results.

For ```SCHEDULER=DEFAULT``` 
``` bash
wait time = 4101,
run time = 8
```

For ```SCHEDULER=PBS``` 
``` bash
wait time = 4042,
run time = 7
```

For ```SCHEDULER=MLFQ``` 
``` bash
wait time = 4041,
run time = 7
```

For ```SCHEDULER=FCFS``` 
``` bash
wait time = 4141,
run time = 7
```

Observing this, we see that the time for the process goes in the following fashion:
MLFQ < PBS < Default(RR) < FCFS

> MLFQ providing the least waiting time for the program.

## To Run

```bash
make clean
make qemu-nox SCHEDULER=$SCHEDULERFLAG
```