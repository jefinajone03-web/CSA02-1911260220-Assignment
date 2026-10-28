#include <stdio.h>
#define RUPEES_TO_PAISE(rupees) ((long)(rupees) * 100L)
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

static inline long rupees_to_paise(long rupees)
{
    return rupees * 100L;
}

static inline int square_int(int x)
{
    return x * x;
}

static inline int max_int(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    int a = 3, b = 7;
    printf("Rs 12 in paise = %ld\n", RUPEES_TO_PAISE(12));
    printf("SQUARE(a + 1) = %d\n", SQUARE(a + 1));
    printf("MAX(a, b) = %d\n", MAX(a, b));
    printf("Inline square(4) = %d\n", square_int(4));
    printf("Inline max(3, 7) = %d\n", max_int(3, 7));
    return 0;
}
