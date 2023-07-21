#include "types.h"
#include "stat.h"
#include "user.h"
#define MAXTESTNUM 20

int rs[MAXTESTNUM];
int TESTNUM = 10;
int SIZE = 5000;
// int lengths[TESTNUM] = {1000, 2000, 500, 5000, 10000, 1000, 1000, 2000, 500, 5000};
int 
main(int argc, char **argv) {
    if(argc >= 2)
        TESTNUM = atoi(argv[1]);
    if (argc >= 3)
        SIZE = atoi(argv[2]);
    
    printf(1, "Number of processes: %d\nSize of processes: %d int = %d*4 = %d\n", TESTNUM, SIZE, SIZE, SIZE*4);
    
    for (int i = 0; i < TESTNUM; i++)
    {
        rs[i] = fork();
        if (rs[i] == 0)
        {
            int* a1 = malloc(SIZE * sizeof(int));
            int sum = 0;
            for (int j = 0; j < 1000; j++)
            {
                sum += a1[j];
            }
            while (1) continue;
            exit();
        }
    }
    proc_dump();
    exit();
}