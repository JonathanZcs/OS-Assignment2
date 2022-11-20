// Jonathan Zajac
// Operating Systens Coding Assignment 2
#include <stdio.h>

int allocation[5][3] = {{ 0, 1, 0 },  
                        { 2, 0, 0 },  
                        { 3, 0, 2 },  
                        { 2, 1, 1 },  
                        { 0, 0, 2 }}; 
int max[5][3] =        {{ 7, 5, 3 },  
                        { 3, 2, 2 },  
                        { 9, 0, 2 },  
                        { 2, 2, 2 },  
                        { 4, 3, 3 }}; 
int avaliable[3] =      { 3, 3, 2 };

int main() {
    int resources = 3;
    int processes = 5;
    int need[5][3];
    int safeSequence[5];
    int sequenceIndex = 0;
    int track = 0;
    int hold[3];
    hold[0] = avaliable[0];
    hold[1] = avaliable[1];
    hold[2] = avaliable[2];
    for(int i = 0; i < processes; i++) {
        for(int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    while(sequenceIndex != processes) {
        for(int i = 0; i < processes; i++) {
            int j = 0;
            if(need[i][j] != -1 && need[i][j] <= hold[j] && need[i][j+1] <= hold[j+1] && need[i][j+2] <= hold[j+2]) {
                hold[j] = hold[j] + allocation[i][j];
                hold[j+1] = hold[j+1] + allocation[i][j+1];
                hold[j+2] = hold[j+2] + allocation[i][j+2];
                safeSequence[sequenceIndex] = i;
                sequenceIndex++;
                need[i][j] = -1;
            } else {
                track = 1;
            }
        }
    }
    if(track == 1) printf("System is not in safe state; safe sequence is: ");
    else printf("System is in safe state.\n");
    for(int i = 0; i < processes; i++) {
        if(i != (processes - 1)) printf("P%d, ", safeSequence[i]);
        else printf("P%d", safeSequence[i]);
    }
}