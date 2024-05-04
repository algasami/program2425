#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_TESTS 100
#define MAX_UNITS 100000

#define GET_TIME(x, dt)                              \
    {                                                \
        clock_t begin, end;                          \
        begin = clock();                             \
        x;                                           \
        end = clock();                               \
        dt = (double)(end - begin) / CLOCKS_PER_SEC; \
    }

long long int buffer[MAX_UNITS];

int main()
{
    srand(time(NULL));
    for (size_t i = 0; i < MAX_UNITS; i++)
    {
        buffer[i] = (long long int)(((float)rand() / (float)RAND_MAX) * 10000.0f);
    }
    int k = 57;
    double sm = 0;
    int a = 0;
    for (unsigned int iter = 0; iter < MAX_TESTS; iter++)
    {
        double dt;
        GET_TIME(
            for (size_t i = 0; i < MAX_UNITS; i++) {
                if ((unsigned long long int)buffer[i] % k == 0)
                {
                    ++a;
                }
            },
            dt)
        sm += dt;
    }
    double avg = sm / (double)MAX_TESTS;
    printf("unsigned long long int: %f sec\n", avg);
    sm = 0.0;

    for (unsigned int iter = 0; iter < MAX_TESTS; iter++)
    {
        double dt;
        GET_TIME(
            for (size_t i = 0; i < MAX_UNITS; i++) {
                if ((unsigned int)buffer[i] % k == 0)
                {
                    ++a;
                }
            },
            dt)
        sm += dt;
    }
    avg = sm / (double)MAX_TESTS;
    printf("unsigned int: %f sec\n", avg);
    sm = 0.0;

    for (unsigned int iter = 0; iter < MAX_TESTS; iter++)
    {
        double dt;
        GET_TIME(
            for (size_t i = 0; i < MAX_UNITS; i++) {
                if ((long long int)buffer[i] % k == 0)
                {
                    ++a;
                }
            },
            dt)
        sm += dt;
    }
    avg = sm / (double)MAX_TESTS;
    printf("long long int: %f sec\n", avg);
    sm = 0.0;

    for (unsigned int iter = 0; iter < MAX_TESTS; iter++)
    {
        double dt;
        GET_TIME(
            for (size_t i = 0; i < MAX_UNITS; i++) {
                if ((int)buffer[i] % k == 0)
                {
                    ++a;
                }
            },
            dt)
        sm += dt;
    }
    avg = sm / (double)MAX_TESTS;
    printf("int: %f sec\n", avg);
    sm = 0.0;

    return 0;
}