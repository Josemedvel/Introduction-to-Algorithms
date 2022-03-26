#include <stdio.h>

int list[] = {5,2,4,6,1,3};
int size = 6;
void insertion_sort(int * list, int size){
    for(int j = 1; j < size; j++){
        int item = list[j];
        int i = j - 1;
        while(i >= 0 && list[i] > item){
            list[i + 1] = list[i];
            i = i - 1;
        }
        list[i+1] = item; 
    }
    return;
}

int main(){

    insertion_sort(list,size);
    for(int i = 0; i < size; i++){
        printf("%d ",list[i]);
    }
    return 0;
}