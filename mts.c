#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
#include <string.h>

struct train{ 
    char train_direction[1];
    int load_time;
    int cross_time;
};

int queue[75]; /* Line 14 - 41: Helped by ChatGPT */
int head = 0, tail = 0;

int isEmpty() {
    return head == tail;
}

int isFull() {
    return (tail + 1) % 75 == head;
}

void enqueue(int train_index) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue train %d.\n", train_index);
        return;
    }
    queue[tail] = train_index;
    tail = (tail + 1) % 75;
}

int dequeue() {
    if (isEmpty()) {
        return -1;  // Queue is empty
    }
    int train = queue[head];
    head = (head + 1) % 75;
    return train;
}

struct train train_data[75]; /* Holds train attributes */
pthread_mutex_t count_mutex; /* Holds mutex */
pthread_mutex_t mutex_cond;
pthread_mutex_t mutex_cond3;
pthread_cond_t count_cond; /* Holds conditions */
pthread_cond_t count_cond2;
int load_done = 0; /* Checks if loading time is done. 0: Not done, 1: done */
int load_done2 = 0;
int train_index = 0;
//double curr_time = 0;

void *loading_time(void *index){ /* Add locks and conditions here*/
    /*
     * Function: loading_time
     *
     * Parameters: 
     *     index:  index: the number of the train to load
     *
     */
     char *train_direction_l = train_data[(intptr_t)index].train_direction;
     int load_time_l = train_data[(intptr_t)index].load_time;
     int index_l = (intptr_t)index;

     double new_time = (double)(load_time_l)/10;
     useconds_t load_time2 = (useconds_t)(new_time * 1000000);
     usleep(load_time2); /* Loads time */
     
     printf("00:00:0%.1f ", new_time);
     
     char *direction;
     if(strcmp(train_direction_l, "W")==0 || strcmp(train_direction_l, "w")==0){
         direction = "West";    
     }else{
        direction = "East";
     }
     printf("Train %2d is ready to go %s\n", index_l, direction);

     //add to queue - choose which train to use enqueue here OR don't enqueue here but in main()
     enqueue(index_l);

     pthread_mutex_lock(&count_mutex); /* Locks code below */
     load_done = 1;
     pthread_cond_broadcast(&count_cond); /* Signals load time is finished */
     pthread_mutex_unlock(&count_mutex); /* Unlocks code for other threads */
  
    pthread_exit(NULL); 

}

void *train_departs(void *index){
    /*
     * Function: train_departs
     *
     */
     int t_ind = (intptr_t)index;

        /* Output train on track */
        char *t_dir = train_data[t_ind].train_direction;
        int load_time_l = train_data[t_ind].load_time;
        int cross_time_l = train_data[t_ind].cross_time;

        char *dir;
        if(strcmp(t_dir, "W")==0 || strcmp(t_dir, "w")==0){
            dir = "West";    
        }else{
           dir = "East";
        }

        double new_time = (double)(load_time_l)/10;
        //double new_time = curr_time;
        double new_cross_time = (double)(cross_time_l)/10;
        double time_l = new_cross_time + new_time;
        useconds_t load_time2 = (useconds_t)(new_cross_time * 1000000);

        pthread_mutex_lock(&count_mutex);

        /* Output that train is on main track */
        printf("00:00:0%.1f Train %2d is ON the main track going %4s\n", new_time, t_ind, dir);

        usleep(load_time2); /* Loads time */

        /* Output that train is OFF the main track */
        printf("00:00:0%.1f Train %2d is OFF the main track after going %4s\n", time_l, t_ind, dir);

        pthread_mutex_unlock(&count_mutex);
    
    pthread_exit(NULL); 
}

int main(int argc, char **argv){ 
    pthread_t threads[75];
    pthread_t thread2;

    pthread_mutex_init(&count_mutex, NULL); /* Initializes mutex */
    pthread_mutex_init(&mutex_cond, NULL);
    pthread_mutex_init(&mutex_cond3, NULL);

    pthread_cond_init(&count_cond, NULL); /* Initializes condition */
    pthread_cond_init(&count_cond2, NULL);

    FILE *input = fopen(argv[1], "r");
    if(input == NULL){
        printf("Error: File is not available\n");
        return -1;
    }

    int num_trains = 0;
    while(!feof(input)){
        fscanf(input, "%s %d %d\n", train_data[num_trains].train_direction, &train_data[num_trains].load_time, &train_data[num_trains].cross_time);
        num_trains++;
    }

    for(int i = 0; i < num_trains; i++){
        pthread_create(&threads[i], NULL, loading_time, (void *)(intptr_t)i); /* Loads the trains and decides which train to enter the main track */
    }

    for(int i = 0; i < num_trains; i++){ /* Waits until train is ready to cross */
        
        pthread_mutex_lock(&count_mutex);

        while(load_done == 0){
            pthread_cond_wait(&count_cond,&count_mutex);
        }

        int j = dequeue();
        pthread_create(&thread2, NULL, train_departs, (void*)(intptr_t)j);

        pthread_mutex_unlock(&count_mutex);

        pthread_mutex_lock(&count_mutex);
        load_done = 0;
        pthread_cond_broadcast(&count_cond); /* Signal next train */
        pthread_mutex_unlock(&count_mutex);

    }

    for(int i=0; i< num_trains; i++){
        pthread_join(threads[i], NULL); /* Wait for threads to all complete */
    }

    pthread_join(thread2, NULL);
    
    pthread_mutex_destroy(&count_mutex);
    pthread_mutex_destroy(&mutex_cond);
    pthread_mutex_destroy(&mutex_cond3);

    pthread_cond_destroy(&count_cond);
    pthread_cond_destroy(&count_cond2);

    pthread_exit(NULL);

}