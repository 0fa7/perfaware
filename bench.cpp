#include <benchmark/benchmark.h>

#include "waste.h"
#include "instructions_per_clock.h"

static void BM_waste(benchmark::State& state, uint32_t count)
{
    auto input = init_array(count);

    for (auto _ : state)
    {
        single_scalar(count, input.data());
    }
}

static void BM_unroll_2_scalar(benchmark::State& state, uint32_t count)
{
    auto input = init_array(count);

    for (auto _ : state)
    {
        unroll_2_scalar(count, input.data());
    }
}

static void BM_unroll_4_scalar(benchmark::State& state, uint32_t count)
{
    auto input = init_array(count);

    for (auto _ : state)
    {
        unroll_4_scalar(count, input.data());
    }
}

static void BM_unroll_8_scalar(benchmark::State& state, uint32_t count)
{
    auto input = init_array(count);

    for (auto _ : state)
    {
        unroll_8_scalar(count, input.data());
    }
}

static void BM_dual_scalar(benchmark::State& state, uint32_t count)
{
    auto input = init_array(count);

    for (auto _ : state)
    {
        dual_scalar(count, input.data());
    }
}

static void BM_quad_scalar(benchmark::State& state, uint32_t count)
{
    auto input = init_array(count);

    for (auto _ : state)
    {
        quad_scalar(count, input.data());
    }
}

static void BM_quad_scalar_ptr(benchmark::State& state, uint32_t count)
{
    auto input = init_array(count);

    for (auto _ : state)
    {
        quad_scalar_ptr(count, input.data());
    }
}

static void BM_octo_scalar(benchmark::State& state, uint32_t count)
{
    auto input = init_array(count);

    for (auto _ : state)
    {
        octo_scalar(count, input.data());
    }
}

static void BM_octo_scalar_ptr(benchmark::State& state, uint32_t count)
{
    auto input = init_array(count);

    for (auto _ : state)
    {
        octo_scalar_ptr(count, input.data());
    }
}

// Register the function as a benchmark
BENCHMARK_CAPTURE(BM_waste, single_scalar_4096, 4096)->Iterations(1);
BENCHMARK_CAPTURE(BM_unroll_2_scalar, unroll_2_scalar_4096, 4096)->Iterations(1);
BENCHMARK_CAPTURE(BM_unroll_2_scalar, unroll_4_scalar_4096, 4096)->Iterations(1);
BENCHMARK_CAPTURE(BM_unroll_8_scalar, unroll_8_scalar_4096, 4096)->Iterations(1);
BENCHMARK_CAPTURE(BM_dual_scalar, dual_scalar_4096, 4096)->Iterations(1);
BENCHMARK_CAPTURE(BM_quad_scalar, quad_scalar_4096, 4096)->Iterations(1);
BENCHMARK_CAPTURE(BM_quad_scalar_ptr, quad_scalar_ptr_4096, 4096)->Iterations(1);
BENCHMARK_CAPTURE(BM_octo_scalar, octo_scalar_4096, 4096)->Iterations(1);
BENCHMARK_CAPTURE(BM_octo_scalar_ptr, octo_scalar_ptr_4096, 4096)->Iterations(1);

// Run the benchmark
BENCHMARK_MAIN();