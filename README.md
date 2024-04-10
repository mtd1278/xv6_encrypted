# Filesystem and Encyption
In this assignment you will be be updating the xv6 filesystem to read and write encrypted files. 

## Groups
You may work on this assignment in groups of up to 2 members. Group members must be in the same course section.

## Kernel Mode

### int encrypt(  int fd, uint8 key )
This system call will encrypt the file represented by the file descriptor, fd.  The system call will perform a byte-by-byte XOR encryption on the file using the provided key. 

Attempting to encrypt a file that is already encrypted will return -1 and no change will be made to the file.

### int decrypt(  int fd, uint8 key )
This system call will decrypt the file represented by the file descriptor, fd.  The system call will perform a byte-by-byte XOR decryption on the file using the provided key.  

Attempting to decrypt a file that is not encrypted will return -1 and no change will be made to the file.

### struct file and struct (file.c/h)
You will update the file structure and the in-memory inode structure to track if a file has been encrypted. 

### iupdate() and ilock() (fs.c)
Copy the encrypted status to and from the inode

### stati() (fs.c)
Copy the encrypted status from the inode

## User Space

### stat
Update the stat struct to add the encrypted status of the given file

### cat
Update cat.c so that encrypted files will not be printed. If cat is passed an encrypted file it should return: "Error: File is encrypted.". Ensure the print statement is exactly as specified.

### grep
Update grep.c so that encrypted file will not be search. If grep is passed an encrypted file it should return: "Error: File is encrypted.". Ensure the print statement is exactly as specified.

### wc
Update wc.c so that encrypted file will not be processed. If wc is passed an encrypted file it should return: "Error: File is encrypted.". Ensure the print statement is exactly as specified.


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

