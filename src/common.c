#include <common.h>
int RanInt(int min, int max)
{
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}