# Filesystem and Encyption

In this assignment you will be be updating the xv6 filesystem to read and write encrypted files

## Required Changes 

### int encrypt(  int fd, uint8 key )
This system call will encrypt the file represented by the file descriptor, fd.  The system call will perform a byte-by-byte XOR encryption on the file.  

Attempting to encrypt a file that is already encrypted will return -1 and no change will be made to the file.

### int decrypt(  int fd, uint8 key )
This system call will decrypt the file represented by the file descriptor, fd.  The system call will perform a byte-by-byte XOR decryption on the file.  

Attempting to decrypt a file that is not encrypted will return -1 and no change will be made to the file.

### struct file and struct (file.c/h)
You will update the file struct and the in-memory inode structure to track if a file has been encrypted. 

### iupdate() and ilock() (fs.c)
Copy the encrypted status to and from the inode

### stat
update the stat struct to add the encrypted status of the given file

## stati() (fs.c)
Copy the encrypted status from the inode





Your ps application will print the following:

```
NAME    PID     STATUS      COLOR    TICKETS
init    1       SLEEPING    RED      10    
sh      2       SLEEPING    ORANGE   2
test    4       SLEEPING    RED      4
ps      6       RUNNING     INDIGO   1
```

### The scheduler

~Most of the code for the scheduler is quite localized and can be found in proc.c; the associated header file, proc.h is also quite useful to examine. To change the scheduler, not much needs to be done; study its control flow and then try some small changes.~

You'll need to assign tickets to a process when it is created. Specfically, you'll need to make sure a child process inherits the same number of tickets as its parents. Thus, if the parent has 10 tickets, and calls fork() to create a child process, the child should also get 10 tickets.

You'll also need to figure out how to generate random numbers in the kernel; some searching should lead you to a simple pseudo-random number generator, which you can then include in the kernel and use as appropriate.

Finally, you'll need to understand how to fill in the structure pstat in the kernel and pass the results to user space. The structure should look like what you see here, in a file you'll have to include called pstat.h:


```c
#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

struct pstat {
  char name[NPROC][16];        // name of the process
  enum procstate state[NPROC]; // state of the process   
  int inuse[NPROC];            // whether this slot of the process table is in use (1 or 0)
  int tickets[NPROC];          // the number of tickets this process has
  int pid[NPROC];              // the PID of each process
  enum COLOR color[NPROC];     // the color of the proces
  int ticks[NPROC];            // the number of ticks each process has accumulated 
};

#endif // _PSTAT_H_
```
## Graph and Test Application

~You'll have to make a graph for this assignment. The graph should show the number of time slices a set of three processes receives~
~over time, where the processes have a 3:2:1 ratio of tickets (e.g., process A might have 30 tickets, process B 20, and process C 10). The graph is likely to be pretty boring, but should clearly show that your lottery scheduler works as desired.  The graph must be submitted as a PDF file at the top level of your repo.~

~To gather this data you will need to write an application that forks three children and each child runs measuring the amount of the processor time each gets.~

## SUBMITTING

Push all your changes to your main branch.  

## BUILDING AND RUNNING XV6

### Setting up the cross-compiling environment
```
source source_me.sh
```

### To build the kernel:
```
make
```

### To build the userspace applications and run the OS
```
make qemu
```

### To exit xv6
```
ctrl-a x
```

## Administrative

This assignment must be coded in C. Any other language will result in 0 points. Your programs will be compiled and graded on the course GitHub Codespace. Code that does not compile with the provided makefile will result in a 0.

There are coding resources and working code you may use in the course GitHub repositories.  You are free to use any of that code in your program if needed. You may use no other outside code.

## Academic Integrity
This assignment must be 100% your own work. No code may be copied from friends,  previous students, books, web pages, etc. All code submitted is automatically checked 
against a database of previous semester’s graded assignments, current student’s code and common web sources. By submitting your code on GitHub you are attesting that 
you have neither given nor received unauthorized assistance on this work. Code that is copied from an external source or used as inspiration, excluding the 
course github, will result in a 0 for the assignment and referral to the Office of Student Conduct.

