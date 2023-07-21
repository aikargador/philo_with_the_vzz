#include <stdio.h>
#include <pthread.h>
// #include <semaphore.h>

#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

#define NUM_PHILOSOPHERS 5

// Define a structure for the philosopher's chopsticks
typedef struct chopsticks {
	sem_t mutex;
} chopsticks;

// Define a structure for each philosopher
typedef struct philosopher {
	int id;
	chopsticks *left_chopstick;
	chopsticks *right_chopstick;
} philosopher;

// Define a function for the philosopher to pick up the chopsticks
void pick_up_chopsticks(philosopher *p) {
	// Acquire the mutexes for both chopsticks
	sem_wait(&p->left_chopstick->mutex);
	sem_wait(&p->right_chopstick->mutex);

	printf("Philosopher %d picked up both chopsticks.\n", p->id);
}

// Define a function for the philosopher to put down the chopsticks
void put_down_chopsticks(philosopher *p) {
	// Release the mutexes for both chopsticks
	sem_post(&p->left_chopstick->mutex);
	sem_post(&p->right_chopstick->mutex);

	printf("Philosopher %d put down both chopsticks.\n", p->id);
}

// Define a function for the philosopher thread
void *philosopher_thread(void *arg) {
	philosopher *p = (philosopher *)arg;

	while (1) {
		// Think for a random amount of time
		printf("Philosopher %d is thinking.\n", p->id);
		sleep(rand() % 5 + 1);

		// Pick up the chopsticks
		pick_up_chopsticks(p);

		// Eat for a random amount of time
		printf("Philosopher %d is eating.\n", p->id);
		sleep(rand() % 5 + 1);

		// Put down the chopsticks
		put_down_chopsticks(p);
	}

	pthread_exit(NULL);
}

int main() {
	// Initialize the chopsticks
	chopsticks chopstick[NUM_PHILOSOPHERS];
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		sem_init(&chopstick[i].mutex, 0, 1);
	}

	// Initialize the philosophers
	philosopher philosophers[NUM_PHILOSOPHERS];
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		philosophers[i].id = i;
		philosophers[i].left_chopstick = &chopstick[i];
		philosophers[i].right_chopstick = &chopstick[(i + 1) % NUM_PHILOSOPHERS];
	}

	// Create the philosopher threads
	pthread_t philosopher_threads[NUM_PHILOSOPHERS];
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_create(&philosopher_threads[i], NULL, philosopher_thread, &philosophers[i]);
	}

	// Wait for the philosopher threads to finish
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_join(philosopher_threads[i], NULL);
	}

	// Destroy the chopsticks
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		sem_destroy(&chopstick[i].mutex);
	}

	return 0;
}