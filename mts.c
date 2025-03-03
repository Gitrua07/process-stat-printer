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

struct train train_data[75]; /* Holds train attributes */
pthread_mutex_t count_mutex; /* Holds mutex */
pthread_mutex_t mutex_cond;
pthread_mutex_t mutex_cond3;
pthread_cond_t count_cond; /* Holds conditions */
pthread_cond_t count_cond2;
int load_done = 0; /* Checks if loading time is done. 0: Not done, 1: done */
int load_done2 = 0;
int train_index = 0;
char *direction;

void *loading_time(void *index){ /* Add locks and conditions here*/
    /*
     * Function: loading_time
     *
     * Parameters: 
     *     index:  index: the number of the train to load
     *
     */

     double new_time = ((double)train_data[(intptr_t)index].load_time)/10;
     useconds_t load_time2 = (useconds_t)(new_time * 1000000);

     usleep(load_time2); /* Loads time */

     pthread_mutex_lock(&count_mutex); /* Locks code below */
     printf("00:00:0%.1f ", new_time);
     
     if(strcmp(train_data[(intptr_t)index].train_direction, "W")==0 || strcmp(train_data[(intptr_t)index].train_direction, "w")==0){
         printf("Train %2ld is ready to go West\n", (intptr_t)index);
         direction = "West";
     }else{
        printf("Train %2ld is ready to go East\n", (intptr_t)index);
        direction = "East";
     }
     
     load_done = 1;
     pthread_cond_signal(&count_cond); /* Signals load time is finished */
     pthread_mutex_unlock(&count_mutex); /* Unlocks code for other threads */

     printf("00:00:0%.1f ", new_time);
     printf("Train %2ld is ON the main track going %4s\n", (intptr_t)index, direction);

   pthread_mutex_lock(&mutex_cond3);
   while(load_done2==0){
     pthread_cond_wait(&count_cond2, &mutex_cond3);
   }

   pthread_mutex_unlock(&mutex_cond3);
   load_done2 = 0;

    double cross_time = ((double)train_data[(intptr_t)index].cross_time) / 10;
    usleep((useconds_t)(cross_time * 1000000));

    printf("00:00:0%.1f ", new_time);
    printf("Train %2ld is OFF the main track after going %4s\n",(intptr_t)index, direction);
  
    pthread_exit(NULL); 

}

void *train_departs(void *index){
    /*
     * Function: train_departs
     *
     * Parameters: 
     *      index: the number of the train to depart
     *
     */

     pthread_mutex_lock(&mutex_cond);
     while(load_done==0){
        pthread_cond_wait(&count_cond, &mutex_cond);
     }

     load_done2 = 1;
     pthread_cond_broadcast(&count_cond2);
     pthread_mutex_unlock(&mutex_cond);
     load_done = 0;

     pthread_exit(NULL); 
}

int main(int argc, char **argv){ 
    pthread_t threads[75];

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

    for(int i = 0; i < num_trains; i++){
        pthread_create(&threads[i], NULL, train_departs, (void *)(intptr_t)i); /* Prints out that train has crossed */
    }

    for(int i=0; i< num_trains; i++){
        pthread_join(threads[i], NULL); /* Wait for threads to all complete */
    }
    
    pthread_mutex_destroy(&count_mutex);
    pthread_mutex_destroy(&mutex_cond);
    pthread_mutex_destroy(&mutex_cond3);

    pthread_cond_destroy(&count_cond);
    pthread_cond_destroy(&count_cond2);

    pthread_exit(NULL);

}