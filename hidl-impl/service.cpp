#include <vendor/sample/benchmark/1.0/IBenchmark.h>

#include <hidl/LegacySupport.h>

using vendor::sample::benchmark::V1_0::IBenchmark;
using android::hardware::defaultPassthroughServiceImplementation;

int main()
{
    return defaultPassthroughServiceImplementation<IBenchmark>();
}
