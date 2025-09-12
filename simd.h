#pragma once

#include <cstdint>
#include <immintrin.h>

uint32_t __attribute__((target("ssse3"))) single_sse(uint32_t count, uint32_t *input)
{
    __m128i sum = _mm_setzero_si128();

    for (int ix = 0; ix < count; ix += 4)
    {
        sum = _mm_add_epi32(sum, _mm_load_si128((__m128i*)&input[ix]));
    }

    // a_1 a_2 a_3 a_4
    // b_1 b_2 b_3 b_4
    // a1 + a2, a3 + a4, b_1 + b_2, b_3 + b_4, 0, 0

    // a1 + a2, a3 + a4, b_1 + b_2, b_3 + b_4
    // a1 + a2, a3 + a4, b_1 + b_2, b_3 + b_4
    // a1 + a2 + a3 + a4, b_1 + b_2 + b_3 + b_4, 0, 0
    sum = _mm_hadd_epi32(sum, sum);
    sum = _mm_hadd_epi32(sum, sum);

    return _mm_cvtsi128_si32(sum);
}

uint32_t __attribute__((target("avx2"))) single_avx(uint32_t count, uint32_t *input)
{
    __m256i sum = _mm256_setzero_si256();

    for (int ix = 0; ix < count; ix += 8)
    {
        sum = _mm256_add_epi32(sum, _mm256_loadu_si256((__m256i *)&input[ix]));
    }

    sum = _mm256_hadd_epi32(sum, sum);
    sum = _mm256_hadd_epi32(sum, sum);

    __m256i sum_s = _mm256_permute2x128_si256(sum, sum, 1 | 1 << 4);

    sum = _mm256_hadd_epi32(sum, sum_s);

    return _mm256_cvtsi256_si32(sum);
}

uint32_t __attribute__((target("avx2"))) dual_avx(uint32_t count, uint32_t *input)
{
    __m256i sum_a = _mm256_setzero_si256();
    __m256i sum_b = _mm256_setzero_si256();

    for(int ix = 0; ix < count; ix += 16)
    {
        sum_a = _mm256_add_epi32(sum_a, _mm256_loadu_si256((__m256i *)&input[ix]));
        sum_b = _mm256_add_epi32(sum_b, _mm256_loadu_si256((__m256i *)&input[ix + 8]));
    }

    __m256i sum = _mm256_add_epi32(sum_a, sum_b);

    sum = _mm256_hadd_epi32(sum, sum);
    sum = _mm256_hadd_epi32(sum, sum);
    __m256i sum_s = _mm256_permute2x128_si256(sum, sum, 1 | (1 << 4));
    sum = _mm256_add_epi32(sum, sum_s);

    return _mm256_cvtsi256_si32(sum);
}

uint32_t __attribute__((target("avx2"))) quad_avx(uint32_t count, uint32_t *input)
{
    __m256i sum_a = _mm256_setzero_si256();
    __m256i sum_b = _mm256_setzero_si256();
    __m256i sum_c = _mm256_setzero_si256();
    __m256i sum_d = _mm256_setzero_si256();

    for(int ix = 0; ix < count; ix += 32)
    {
        sum_a = _mm256_add_epi32(sum_a, _mm256_loadu_si256((__m256i *)&input[ix]));
        sum_b = _mm256_add_epi32(sum_b, _mm256_loadu_si256((__m256i *)&input[ix + 8]));
        sum_c = _mm256_add_epi32(sum_c, _mm256_loadu_si256((__m256i *)&input[ix + 16]));
        sum_d = _mm256_add_epi32(sum_d, _mm256_loadu_si256((__m256i *)&input[ix + 24]));
    }

    __m256i sum_a_b = _mm256_add_epi32(sum_a, sum_b);
    __m256i sum_c_d = _mm256_add_epi32(sum_c, sum_d);
    __m256i sum = _mm256_add_epi32(sum_a_b, sum_c_d);

    sum = _mm256_hadd_epi32(sum, sum);
    sum = _mm256_hadd_epi32(sum, sum);
    __m256i sum_s = _mm256_permute2x128_si256(sum, sum, 1 | (1 << 4));
    sum = _mm256_add_epi32(sum, sum_s);

    return _mm256_cvtsi256_si32(sum);
}

uint32_t __attribute__((target("avx2"))) quad_avx_ptr(uint32_t count, uint32_t *input)
{
    __m256i sum_a = _mm256_setzero_si256();
    __m256i sum_b = _mm256_setzero_si256();
    __m256i sum_c = _mm256_setzero_si256();
    __m256i sum_d = _mm256_setzero_si256();

    count /=32;

    while(count--)
    {
        sum_a = _mm256_add_epi32(sum_a, _mm256_loadu_si256((__m256i *)&input[0]));
        sum_b = _mm256_add_epi32(sum_b, _mm256_loadu_si256((__m256i *)&input[8]));
        sum_c = _mm256_add_epi32(sum_c, _mm256_loadu_si256((__m256i *)&input[16]));
        sum_d = _mm256_add_epi32(sum_d, _mm256_loadu_si256((__m256i *)&input[24]));
        input += 32;
    }

    __m256i sum_a_b = _mm256_add_epi32(sum_a, sum_b);
    __m256i sum_c_d = _mm256_add_epi32(sum_c, sum_d);
    __m256i sum = _mm256_add_epi32(sum_a_b, sum_c_d);

    sum = _mm256_hadd_epi32(sum, sum);
    sum = _mm256_hadd_epi32(sum, sum);
    __m256i sum_s = _mm256_permute2x128_si256(sum, sum, 1 | (1 << 4));
    sum = _mm256_add_epi32(sum, sum_s);

    return _mm256_cvtsi256_si32(sum);
}