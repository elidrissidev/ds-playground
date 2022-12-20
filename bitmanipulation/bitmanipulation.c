#include <assert.h>
#include <stdio.h>

int set_bit(int target, int pos)
{
    int mask = 1 << pos;
    return target | mask;
}

int flip_bit(int target, int pos)
{
    int mask = 1 << pos;
    return target ^ mask;
}

int is_even(int x)
{
    return ~x & 1;
}

int main()
{
    // Test set_bit
    assert(set_bit(6, 0) == 7); // 6 (110) => 7 (111)
    assert(set_bit(5, 1) == 7); // 5 (101) => 7 (111)
    assert(set_bit(21, 3) == 29); // 21 (10101) => 29 (11101)

    // Test flip_bit
    assert(flip_bit(6, 0) == 7); // 6 (110) => 7 (111)
    assert(flip_bit(10, 2) == 14); // 10 (1010) => 14 (1110)
    assert(flip_bit(21, 3) == 29); // 21 (10101) => 29 (11101)

    // Test is_even
    assert(is_even(1) == 0);
    assert(is_even(4) == 1);
    assert(is_even(12) == 1);
    assert(is_even(7) == 0);

    return 0;
}
