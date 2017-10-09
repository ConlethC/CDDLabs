#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <mutex>

void taskOne(std::shared_ptr<Semaphore> firstThreadDone, std::shared_ptr<Semaphore> secondThreadDone){
  std::cout << "Thread 1 arrived at wait point"<<std::endl;
  firstThreadDone->Signal();
  secondThreadDone->Wait();
  std::cout << "Thread 1 second output"<<std::endl;
}
void taskTwo(std::shared_ptr<Semaphore> firstThreadDone, std::shared_ptr<Semaphore> secondThreadDone){
  std::cout << "Thread 2 arrived at wait point"<<std::endl;
  secondThreadDone->Signal();
  firstThreadDone->Wait();
  std::cout << "Thread 2 second output"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> firstThreadDone(new Semaphore);
  std::shared_ptr<Semaphore> secondThreadDone(new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,firstThreadDone, secondThreadDone);
  threadTwo=std::thread(taskOne,firstThreadDone, secondThreadDone);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
