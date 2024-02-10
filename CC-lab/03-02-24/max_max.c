#include <stdio.h> 

int total_time_p1 = 0;
int total_time_p2 = 0;

int max_max(int burst_time_p1[], int burst_time_p2[], int n){

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

    int max = 0;
    int max_index;
    int processor;


    for(int i = 0 ; i < n*2 ; i++){
        if(max < assign[i] && assign[i] != 0){
            max = assign[i];
            if(i >= n){
                processor = 2;
                max_index = i;
            }    
            else{
                processor = 1;
                max_index = i;
            }        
        }
    }
    if(processor == 1){
        for(int i = 0 ; i < n; i++){
        //    burst_time_p1[i] =  burst_time_p1[i] + max;
        }
        total_time_p1 = total_time_p1 + max;
    }
    else{
        for(int i = 0 ; i < n; i++){
        //    burst_time_p2[i] =  burst_time_p2[i] + max;
        }
        total_time_p2 = total_time_p2 + max;
    }

    burst_time_p1[max_index] = 0;
    burst_time_p2[max_index] = 0;
    return max;
}

int main() { 
	int processes[] = {1, 2, 3}; 
	int n = sizeof processes / sizeof processes[0]; 

	int burst_time_p1[] = {140, 20, 60}; 
	int burst_time_p2[] = {100, 100, 70};
    int total_time;

    total_time = total_time + max_max(burst_time_p1,burst_time_p2,n);
    total_time = total_time + max_max(burst_time_p1,burst_time_p2,n);
    total_time = total_time + max_max(burst_time_p1,burst_time_p2,n);
    if(total_time_p1 > total_time_p2){
        printf("Total time taken: %d\n", total_time_p1);
    }
    else{
        printf("Total time taken: %d\n", total_time_p2);
    }
} 
