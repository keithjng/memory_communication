#include <iostream>
#include <string>
#include <chrono>
#include <stdlib.h>

using namespace std;
using namespace std::chrono;

int benchmark(unsigned int buffer_bytes) {

    struct timespec t0, t1, t2, t3;
    // n-byte string so we can have n potential bytes to access
    string buffer(buffer_bytes, 'a');

    // Create a random seed and a random array
    srand(time(NULL));
    unsigned int* rand_array = new unsigned int[buffer_bytes];

    // Populate the array of random values
    for (unsigned int i = 0; i < buffer_bytes; i++) {
        rand_array[i] = rand()%buffer_bytes;
    }

    // Flood out random array and access info in cache for clean start
    char x;
    // Make long_string 4MB long 
    string long_string(4000000, 'b');
    for (int j = 0; j < 4000000; j++) {
        x = long_string[j];
    }

    char y;
    for (unsigned int k = 0; k < buffer_bytes; k++) {
        y = buffer[k];
    }

    // Measure time to access rand chars in buffer 10 times.
    char z;
    clock_gettime(CLOCK_MONOTONIC_RAW, &t0);
    for (unsigned int l = 0; l < 10; l++) {
        for (unsigned int m = 0; m < buffer_bytes; m++) {
            z = buffer[rand_array[m]];
        }
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
    // Mean time = measured/iterations, converted to nanoseconds
    long double mean_time = (1000000000 * (t1.tv_sec - t0.tv_sec) + (t1.tv_nsec - t0.tv_nsec)) / (double) buffer_bytes;

    cout << buffer_bytes << "                     " << mean_time << "\n";
    delete [] rand_array;
    return 0;
}

int main () {
    printf("Buffer Size (B)          Time to Read (NS) \n");
    int buffer_bytes = 1024;
    // Goes up to 64MB
    while (buffer_bytes <= 67108864) {
        benchmark(buffer_bytes);
        buffer_bytes = buffer_bytes * 2;
    }
    return 0;
}
