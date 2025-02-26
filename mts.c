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

struct train train_data[75]; // Holds train attributes

void *loading_time(void *index){ /* Add locks and conditions here*/
    /*
     * Function: loading_time
     *
     * Parameters: 
     *     index:  index: the number of the train to load
     *
     */

     usleep(train_data[(intptr_t)index].load_time);
     pthread_exit(NULL);

}

void train_departs(int index){
    /*
     * Function: train_departs
     *
     * Parameters: 
     *      index: the number of the train to depart
     *
     */
}

void crossing_time(int index){
      /*
     * Function: crossing_time
     *
     * Parameters: 
     *      index: the number of the train to cross
     *
     */

}

int main(int argc, char **argv){ 
    pthread_t threads[75];

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

    printf("Number of trains: %d\n", num_trains);

    // Next part
    int i;
    for(i = 0; i < num_trains; i++){
        pthread_create(&threads[i], NULL, loading_time, (void *)(intptr_t)i); /* Loads the trains */

        char *dir; 
        if(strcmp(train_data[i].train_direction, "W")==0 || strcmp(train_data[i].train_direction, "w")==0){
            dir = "West";
        }else{
            dir = "East";
        }
        printf("Train %2d is ready to go %4s\n", i, dir);
    }
 
    printf("-----> End \n");
    return 0;
}