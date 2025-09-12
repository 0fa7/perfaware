#pragma once

#include <cstdint>
#include <vector>

std::vector<uint32_t> init_array(uint32_t count)
{
    std::vector<uint32_t> result(count, 0);

    for (uint32_t i = 0; i < count; i++)
    {
        result[i] = i + 1;
    }

    return result;
}

uint32_t single_scalar(uint32_t count, uint32_t *input)
{
    uint32_t sum = 0;
    for(int32_t ix = 0; ix < count; ++ix)
    {
        sum += input[ix];
    }

    return sum;
}