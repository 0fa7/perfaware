#pragma once

#include <cstdint>
#include <vector>

uint32_t inline unroll_2_scalar(uint32_t count, uint32_t *input)
{
    uint32_t sum = 0;
    for(int32_t ix = 0; ix < count; ix += 2)
    {
        sum += input[ix];
        sum += input[ix + 1];
    }

    return sum;
}

uint32_t inline unroll_4_scalar(uint32_t count, uint32_t *input)
{
    uint32_t sum = 0;
    for(int32_t ix = 0; ix < count; ix += 4)
    {
        sum += input[ix];
        sum += input[ix + 1];
        sum += input[ix + 2];
        sum += input[ix + 3];
    }

    return sum;
}

uint32_t inline unroll_8_scalar(uint32_t count, uint32_t *input)
{
    uint32_t sum = 0;
    for(int32_t ix = 0; ix < count; ix += 8)
    {
        sum += input[ix];
        sum += input[ix + 1];
        sum += input[ix + 2];
        sum += input[ix + 3];
        sum += input[ix + 4];
        sum += input[ix + 5];
        sum += input[ix + 6];
        sum += input[ix + 7];
    }

    return sum;
}

uint32_t inline dual_scalar(uint32_t count, uint32_t *input)
{
    uint32_t sum_a = 0;
    uint32_t sum_b = 0;

    for(int32_t ix = 0; ix < count; ix += 2)
    {
        sum_a += input[ix];
        sum_b += input[ix + 1];
    }

    return sum_a + sum_b;
}

uint32_t inline quad_scalar(uint32_t count, uint32_t *input)
{
    uint32_t sum_a = 0;
    uint32_t sum_b = 0;
    uint32_t sum_c = 0;
    uint32_t sum_d = 0;

    for(int32_t ix = 0; ix < count; ix += 4)
    {
        sum_a += input[ix];
        sum_b += input[ix + 1];
        sum_b += input[ix + 2];
        sum_b += input[ix + 3];
    }

    return sum_a + sum_b + sum_c + sum_d;
}

// why is ptr version faster?  blog says it will be addressed in later chapters
uint32_t inline quad_scalar_ptr(uint32_t count, uint32_t *input)
{
    uint32_t sum_a = 0;
    uint32_t sum_b = 0;
    uint32_t sum_c = 0;
    uint32_t sum_d = 0;

    count /= 4;

    while (count--)
    {
        sum_a += input[0];
        sum_b += input[1];
        sum_b += input[2];
        sum_b += input[3];
        input += 4;
    }

    return sum_a + sum_b + sum_c + sum_d;
}

uint32_t inline octo_scalar(uint32_t count, uint32_t *input)
{
    uint32_t sum_a = 0;
    uint32_t sum_b = 0;
    uint32_t sum_c = 0;
    uint32_t sum_d = 0;
    uint32_t sum_e = 0;
    uint32_t sum_f = 0;
    uint32_t sum_g = 0;
    uint32_t sum_h = 0;

    for(int32_t ix = 0; ix < count; ix += 8)
    {
        sum_a += input[ix];
        sum_b += input[ix + 1];
        sum_c += input[ix + 2];
        sum_d += input[ix + 3];
        sum_e += input[ix + 4];
        sum_f += input[ix + 5];
        sum_g += input[ix + 6];
        sum_h += input[ix + 7];
    }

    return sum_a + sum_b + sum_c + sum_d + sum_e + sum_f + sum_g;
}

uint32_t inline octo_scalar_ptr(uint32_t count, uint32_t *input)
{
    uint32_t sum_a = 0;
    uint32_t sum_b = 0;
    uint32_t sum_c = 0;
    uint32_t sum_d = 0;
    uint32_t sum_e = 0;
    uint32_t sum_f = 0;
    uint32_t sum_g = 0;
    uint32_t sum_h = 0;

    count /= 8;

    while(count--)
    {
        sum_a += input[0];
        sum_b += input[1];
        sum_c += input[2];
        sum_d += input[3];
        sum_e += input[4];
        sum_f += input[5];
        sum_g += input[6];
        sum_h += input[7];
        input += 8;
    }

    return sum_a + sum_b + sum_c + sum_d + sum_e + sum_f + sum_g;
}