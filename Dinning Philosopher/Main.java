import java.util.*;
import java.util.concurrent.Semaphore;

public class Main {
    public static void main(String[] args) {
        Semaphore[] chopsticks = new Semaphore[5];
        for(int i=0;i<5;i++) chopsticks[i] = new Semaphore(1);
        philosopher[] philosophers = new philosopher[5];
        for(int i=0;i<5;i++){
            philosophers[i] = new philosopher(i+1,chopsticks[i],chopsticks[(i+1)%5]);
            new Thread(philosophers[i]).start();
        }
    }
}
class philosopher implements Runnable{
    private final Random random = new Random();
    private int id;
    private Semaphore leftChopStick;
    private Semaphore rightChopStick;

    public philosopher(int id, Semaphore leftChopStick, Semaphore rightChopStick) {
        this.id = id;
        this.leftChopStick = leftChopStick;
        this.rightChopStick = rightChopStick;
    }

    @Override
    public void run() {
        try {
            while (true){
                think();
                pickLeftChopStick();
                pickRightChopStick();
                eat();
                putDownChopstick();
            }
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
    private void think() throws InterruptedException {
        System.out.println("philosopher " + id + " is thinking");
        Thread.sleep(random.nextInt(10));

    }
    private void pickLeftChopStick() throws InterruptedException {
        if(leftChopStick.availablePermits() == 0){
            System.out.println("philosopher "+ id + " is waiting for left chopstick");
        }
        leftChopStick.acquire();
        System.out.println("Philosopher " + id + " is HOLDING  left  chopstick.");
    }
    private void pickRightChopStick() throws InterruptedException {
        if(rightChopStick.availablePermits() == 0){
            System.out.println("philosopher " + id + " is waiting for right chopstick");
        }
        rightChopStick.acquire();
        System.out.println("Philosopher " + id + " is HOLDING right chopstick.");
    }
    private void eat() throws InterruptedException {
        System.out.println("Philosopher " + id + " is EATING");
        Thread.sleep(random.nextInt(10));
    }
    private void putDownChopstick(){
        leftChopStick.release();
        rightChopStick.release();
    }
}
