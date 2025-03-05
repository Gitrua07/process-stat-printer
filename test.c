#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
#include <string.h>

int maxNum[] = {1,2,6,7,3};

void test_sort(){
    int border = sizeof(maxNum)/sizeof(maxNum[0]);
    for(int i = 0; i < border-1; i++){
        for(int j = 0; j < border-1; j++){
        if(maxNum[j] > maxNum[j+1]){
            int temp = maxNum[j];
            maxNum[j] = maxNum[j+1];
            maxNum[j+1] = temp;
        }

        }
        
    }
    
}

int main(){
    printf("After:\n");
    for(int i = 0; i < 75; i++){
        //index_order_t[i] = i;
       // printf("Index %d - Value: %d\n", i, index_order_t[i]);
       printf("Index %d\n", i);
    }
    return 0;

}