#include "names.h"

#include <stdio.h>
#include <stdlib.h>
int pig(void);
int main(void) {
    pig();
}
int pig(void) {
    unsigned int defaultseed = 2023;
    unsigned int defaultplay = 2;
    unsigned int ID = 0;
    unsigned int token = 0;
    unsigned int playscore[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    //int points[7] = { 5, 5, 10, 10, 15, 0, 0 };
    unsigned int points[5] = { 0, 10, 10, 15, 5 };

    typedef enum { SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER } Position;
    const Position pig[7] = {
        SIDE,
        SIDE,
        RAZORBACK,
        TROTTER,
        SNOUTER,
        JOWLER,
        JOWLER,
    };

    printf("Number of players (2 to 10)? ");
    int num_assign = scanf("%d", &defaultplay);
    if (num_assign < 1 || defaultplay < 2 || defaultplay > 10) {
        fprintf(stderr, "Invalid number of players. Using 2 instead.\n");
        defaultplay = 2;
    }
    printf("Random-number seed? ");
    num_assign = scanf("%u", &defaultseed);
    if (num_assign < 1) {
        fprintf(stderr, "Invalid seed. Using 2023 instead.\n");
    }
    srandom(defaultseed);
    //printf("seed is %u\n", defaultseed);
    --defaultplay;
    printf("%s\n", player_name[ID]);
    while (ID <= defaultplay) {
        while (playscore[ID] != 100) {
            if (ID == defaultplay + 1) {
                ID = 0;
            }
            token = pig[(random() % 7)]; //random
            //printf("random callled\n");
            playscore[ID] = playscore[ID] + points[token];
            if (playscore[ID] >= 100) {
                printf(" rolls %d, has %d\n", points[token], playscore[ID]);
                break;
            } else if (points[token] == 0) {
                printf(" rolls %d, has %d\n", points[token], playscore[ID]);
                ID++;
                if (ID != defaultplay && ID > defaultplay) {
                    ID = ID - ID;
                }
                printf("%s\n", player_name[ID]);
            } else {
                printf(" rolls %d, has %d\n", points[token], playscore[ID]);
            }
        }
        printf("%s won!\n", player_name[ID]);
        //printf("%d\n", points[pig[2]]);
        break;
    }
    return 0;
}
