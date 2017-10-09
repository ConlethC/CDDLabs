#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

void exclusion(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "Waiting on access\n";
  theSemaphore->Wait();
  
  sleep(2);
  theSemaphore->Signal();
  std::cout << "Access via semaphore\n";
  
}


int main(void){
  std::thread threadOne, threadTwo, threadThree;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  sem->Signal();
  std::cout << "Initial signal, Semaphore value 1.\n";
  threadOne=std::thread(exclusion,sem);
  threadTwo=std::thread(exclusion,sem);
  threadThree=std::thread(exclusion,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  return 0;
}
