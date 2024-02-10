#include <stdio.h> 

int total_time_p1 = 0;
int total_time_p2 = 0;

int min_min(int burst_time_p1[], int burst_time_p2[], int n){

    int assign[n*2];
    for (int i = 0 ; i<n*2; i++){
        assign[i] = 0;
    }

    for(int i = 0 ; i < n ; i++){
        if (burst_time_p2[i] > burst_time_p1[i]){
            assign[i] = burst_time_p1[i];
        }
        else{
            assign[n+i] = burst_time_p2[i];
        }
    }

    int min = 10000000;
    int min_index;
    int processor;

    for(int i = 0 ; i < n*2 ; i++){
        if(min > assign[i] && assign[i] != 0){
            min = assign[i];
            if(i > n/2){
                processor = 2;
                min_index = i/2;
            }    
            else{
                processor = 1;
                min_index = i;
            }        
        }
    }
    if(processor == 1){
        for(int i = 0 ; i < n; i++){
            burst_time_p1[i] =  burst_time_p1[i] + min;
        }
        total_time_p1 = total_time_p1 + min;
    }
    else{
        for(int i = 0 ; i < n; i++){
            burst_time_p2[i] =  burst_time_p2[i] + min;
        }
        total_time_p2 = total_time_p2 + min;
    }

    burst_time_p1[min_index] = 0;
    burst_time_p2[min_index] = 0;
    return min;
}

int main() { 
	int processes[] = {1, 2, 3}; 
	int n = sizeof processes / sizeof processes[0]; 

	int burst_time_p1[] = {140, 20, 60}; 
	int burst_time_p2[] = {100, 100, 70};
    // int assign[n*2] = {};
    int total_time;

    total_time = total_time + min_min(burst_time_p1,burst_time_p2,n);
    total_time = total_time + min_min(burst_time_p1,burst_time_p2,n);
    total_time = total_time + min_min(burst_time_p1,burst_time_p2,n);
    if(total_time_p1 > total_time_p2){
        printf("Total time taken: %d\n", total_time_p1);
    }
    else{
        printf("Total time taken: %d\n", total_time_p2);
    }
} 
