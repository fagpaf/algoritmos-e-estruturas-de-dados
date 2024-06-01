#include <stdio.h>
#include "bibs/Queue.h"

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
        int count = 0;
        while(length(q) > 0){   
            int queue_time = dequeue(q);
            int x = dequeue(l);
            if (x > time){
                time = x;
            }
            // PODERIA TER UTILIZADO OPERADOR TERNÁRIO
            if(queue_time < time){
                if (count == num_stud){
                    printf("0\n");
                }
                else{
                    printf("0 ");
                    count++;
                }
            }
            else{
                if (count == num_stud){
                    printf("%d\n", time);
                    time++;
                }
                else{
                    printf("%d ", time);
                    time++;
                    count++;
                }
            }
        }
        clear(q);
    }
    return 0;
}