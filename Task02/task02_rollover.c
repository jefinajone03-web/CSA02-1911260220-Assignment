#include <stdio.h>
#include <limits.h>

typedef unsigned short meter_t;

/* A 16-bit meter rolls from 65535 back to 0. */
unsigned int consumption(meter_t previous, meter_t current)
{
    return ((unsigned int)current - (unsigned int)previous)
           & (unsigned int)USHRT_MAX;
}

int main(void)
{
    printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n",
           sizeof(meter_t), (unsigned int)USHRT_MAX);
    printf("Consumption: %u units\n", consumption(1200, 1530));
    printf("Consumption: %u units\n", consumption(65400, 120));
    return 0;
}
