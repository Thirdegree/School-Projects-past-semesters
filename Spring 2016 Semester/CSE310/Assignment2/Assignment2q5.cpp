#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int** createSchedule(int k) {
    if (k==1) {
        int **sch = (int**) malloc(64*sizeof(int*));
        for (int i = 0; i<64; i++) {
            sch[i] = (int*) malloc(63*sizeof(int));
        }

        sch[0][0] = 2;
        sch[1][0] = 1;
        return sch;
    }
    int **halfSchedule = createSchedule(k-1);
    int offsetHelper = pow(2, k-1)+1;
    for (int i = 0; i < pow(2, k-1); i++) { //goes through each lower level player.
        for (int j = pow(2, k-1)-1; j < pow(2, k); j++) { // for each day
            halfSchedule[i][j] = offsetHelper;
            offsetHelper++;
            if (offsetHelper > pow(2,k)) {
                offsetHelper = pow(2,k-1) + 1;
            }
        }
        
    }
    for (int i = 0; i < pow(2, (k-1))-1; i++) { // adds old days for new players
        for (int j = 0; j < pow(2, (k-1)); j++) {
            halfSchedule[(int)pow(2,(k-1)) + j][i] = halfSchedule[j][i] + pow(2,(k-1));
        }
    }
    for (int i = pow(2, (k-1))-1; i< pow(2, k)-1; i++) { // adds new old days for new players
        for (int j = 0; j< pow(2, k-1); j++) {
            halfSchedule[(int)pow(2, k-1) + j][i] = halfSchedule[j][i] - pow(2,(k-1));
        }
    }
    return halfSchedule;
}

int main() {
    int k;
    printf("Please input k: ");
    scanf("%d", &k);
    int** schedule = createSchedule(k);
    for (int i = 1; i < pow(2, k); i++) {
        std::cout << "\t" << i;
    }
    std::cout << std::endl;
    for (int i = 0; i < pow(2,k); i++) {
        std::cout << i+1 << "\t";
        for (int j = 0; j < pow(2,k)-1; j++) {
            std::cout << schedule[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 64; i++){
        free(schedule[i]);
    }
    free(schedule); // found that last leak. Also, apparently there's a bug in OSX's implementation of valgrind. "2,064 bytes in 1 blocks are possibly lost in loss record 58 of 66" - they lie! 
    return 0;
}