/*
    There are 3 states in which each philosopher can be
        1) Thinking
        2) Waiting (waiting for his neighbor to drop chopstick)
        3) Eating


    each chopstick is represented by a semaphore
*/




#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <vector>
#include <mutex>
#include <semaphore.h>

using namespace std;

//sem_t* -> represents a semaphore

class Philosopher {
private:
    int id;  //Philosopher number
    sem_t* left_chopstick;  //LeftChopstick (Note: chopsticks are represented as semaphore)
    sem_t* right_chopstick;
    mt19937 generator; //Random generator, it will be used in sechduling the amount of time philosopher id is in a particular state

public:
    Philosopher(int id, sem_t* left, sem_t* right) : id(id), left_chopstick(left), right_chopstick(right), generator(random_device()()) {}
    void operator()() {
        while (true) {
            think(); //Firstly the philosopher thinks
            pickLeftChopStick();
            pickRightChopStick();
            eat();
            putDownChopstick();
        }
    }

private:
    void think() {
        cout << "philosopher " << id << " is thinking" << endl;
        //Think for milliseconds(generator() % 10). Taking a modulo 10 always keeps the time less than 10
        this_thread::sleep_for(chrono::milliseconds(generator() % 10));
    }

    void pickLeftChopStick() {
        /*
        if (sem_wait(left_chopstick) == 0) The chopstick is not free, left neighbor is holding the chopstick
        */
        if (sem_wait(left_chopstick) == 0) cout << "philosopher " << id << " is waiting for left chopstick" << endl;
        else cout << "Philosopher " << id << " is HOLDING left chopstick." << endl;
    }
    void pickRightChopStick() {
        
        if (sem_wait(right_chopstick) == 0) cout << "philosopher " << id << " is waiting for right chopstick" << endl;
        else cout << "Philosopher " << id << " is HOLDING right chopstick." << endl;
    }

    void eat() {
        cout << "Philosopher " << id << " is EATING" << endl;
        //Eat for milliseconds(generator() % 10)
        this_thread::sleep_for(chrono::milliseconds(generator() % 10));
    }
    //After eating
    void putDownChopstick() {
        //Relase left chopstick, semaphore becomes available
        sem_post(left_chopstick);
        //Release right chopstick, 
        sem_post(right_chopstick);
    }
};

int main() {
    vector<thread> threads;
    vector<sem_t> chopsticks(5); //Create 5 semaphores (chopsticks)
    for (int i = 0; i < 5; i++) sem_init(&chopsticks[i], 0, 1); //initialise the semaphores, 1-> maximum number of users of a chopstick 

    //Add all philosophers as threads
    for (int i = 0; i < 5; i++) threads.emplace_back(Philosopher(i + 1, &chopsticks[i], &chopsticks[(i + 1) % 5]));
    //Start all threads
    for (auto& thread : threads) thread.join();
    return 0;
}
