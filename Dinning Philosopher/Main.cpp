#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <vector>
#include <mutex>
#include <semaphore.h>

using namespace std;

class Philosopher {
private:
    int id;
    sem_t* left_chopstick;
    sem_t* right_chopstick;
    mt19937 generator;

public:
    Philosopher(int id, sem_t* left, sem_t* right) : id(id), left_chopstick(left), right_chopstick(right), generator(random_device()()) {}
    void operator()() {
        while (true) {
            think();
            pickLeftChopStick();
            pickRightChopStick();
            eat();
            putDownChopstick();
        }
    }

private:
    void think() {
        cout << "philosopher " << id << " is thinking" << endl;
        this_thread::sleep_for(chrono::milliseconds(generator() % 10));
    }

    void pickLeftChopStick() {
        if (sem_wait(left_chopstick) == 0) cout << "Philosopher " << id << " is HOLDING left chopstick." << endl;
        else cout << "philosopher " << id << " is waiting for left chopstick" << endl;
    }
    void pickRightChopStick() {
        if (sem_wait(right_chopstick) == 0) cout << "Philosopher " << id << " is HOLDING right chopstick." << endl;
        else cout << "philosopher " << id << " is waiting for right chopstick" << endl;
    }

    void eat() {
        cout << "Philosopher " << id << " is EATING" << endl;
        this_thread::sleep_for(chrono::milliseconds(generator() % 10));
    }

    void putDownChopstick() {
        sem_post(left_chopstick);
        sem_post(right_chopstick);
    }
};

int main() {
    vector<thread> threads;
    vector<sem_t> chopsticks(5);
    for (int i = 0; i < 5; i++) sem_init(&chopsticks[i], 0, 1);
    for (int i = 0; i < 5; i++) threads.emplace_back(Philosopher(i + 1, &chopsticks[i], &chopsticks[(i + 1) % 5]));
    for (auto& thread : threads) thread.join();
    return 0;
}
