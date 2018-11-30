#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h>  

using namespace std; 
  
int main() 
{ int i=0;
    // ftok to generate unique key 
    key_t key = ftok("shmfile",65); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
 while(1)
{ 
    // shmat to attach to shared memory 
    int *str = (int*) shmat(shmid,(void*)0,0); 
  
    //cout << "Write Data : "; 
    //cin >> *str;

    *str = i++;
  
    cout << "Data written in memory: " << *str << endl;; 
   
    //detach from shared memory  
    shmdt(str); 
  }
    return 0; 
} 
