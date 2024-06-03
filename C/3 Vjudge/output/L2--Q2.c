#include <stdio.h>
#include "libs/Queue.h"

int main(){
    int test;
    scanf("%d", &test);
    
    while(test-- >= 0){
        Queue* q = create_queue();
        Queue* l = create_queue();
        int num_stud;
        scanf("%d", &num_stud);
        
        for(int j = 0; j < num_stud; j++){
            int li, ri;
            scanf("%d %d", &li, &ri);
            enqueue(q, ri);
            enqueue(l, li);
        }
        
        int time = 1;
        while(length(q) > 0){   
            int queue_time = dequeue(q);
            int x = dequeue(l);
            if (x > time){
                time = x;
            }
            if(queue_time < time){
                printf("0 ");
            }
            else{
                printf("%d ", time);
                time++;
            }
        }
        clearQueue(q);
        clearQueue(l);
    }
    return 0;
}