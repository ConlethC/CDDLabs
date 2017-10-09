#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "Signalling second thread"<<std::endl;
  theSemaphore->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "Waiting on first signal"<<std::endl;
  theSemaphore->Wait();
   std::cout << "First signal recieved"<<std::endl;
 
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
