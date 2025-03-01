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
pthread_cond_t count_cond; /* Holds conditions */
int load_done = 0; /* Checks if loading time is done. 0: Not done, 1: done */
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

     usleep((useconds_t)(new_time * 1000000));

     pthread_mutex_lock(&count_mutex); /* Locks code below */
     char *dir; 
     if(strcmp(train_data[(intptr_t)index].train_direction, "W")==0 || strcmp(train_data[(intptr_t)index].train_direction, "w")==0){
         dir = "West";
     }else{
         dir = "East";
     }
     printf("00:00:0%.1f ", new_time);
     printf("Train %2ld is ready to go %4s\n", (intptr_t)index, dir);

     load_done = 1;
     pthread_cond_signal(&count_cond);
     pthread_mutex_unlock(&count_mutex); /* Unlocks code for other threads */

     //pthread_mutex_lock()
     //pthread_cond_wait(&)
     direction = dir;
     if(strcmp(train_data[(intptr_t)index].train_direction, "W")==0 || strcmp(train_data[(intptr_t)index].train_direction, "w")==0){
        printf("%ld -- %s goes next - Higher priority\n", (intptr_t)index, train_data[(intptr_t)index].train_direction);
        // if((intptr_t)index){}
        //loading_train1 = , loading_train2 = 
       // train_index = (intptr_t)index;
    }else{
        printf("%ld -- %s goes next - Lower priority\n", (intptr_t)index, train_data[(intptr_t)index].train_direction);
       // train_index = (intptr_t)index;
    }
    train_index = (intptr_t)index;
    //pthread_mutex_unlock();
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
        printf("Train %2d is OFF the main track after going %4s\n",train_index, direction);
     }
     pthread_mutex_unlock(&mutex_cond);
     load_done = 0;
     pthread_exit(NULL); 
}

void *crossing_time(void *index){
    /*
     * Function: crossing_time
     *
     * Parameters: 
     *      index: the number of the train to cross
     *
     */
     pthread_exit(NULL); 

}

int main(int argc, char **argv){ 
    pthread_t threads[75];

    pthread_mutex_init(&count_mutex, NULL); /* Initializes mutex */
    pthread_mutex_init(&mutex_cond, NULL);
    pthread_cond_init(&count_cond, NULL); /* Initializes condition */

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
        pthread_create(&threads[i], NULL, train_departs, (void *)(intptr_t)i); /* Prints out that train has crossed */
    }

    for(int i=0; i< num_trains; i++){
        pthread_join(threads[i], NULL); /* Wait for threads to all complete */
    }
    
    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&count_cond);

    pthread_exit(NULL);

}