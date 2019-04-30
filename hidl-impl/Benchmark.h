#ifndef VENDOR_SAMPLE_BENCHMARK_V1_0_BENCHMARK_H
#define VENDOR_SAMPLE_BENCHMARK_V1_0_BENCHMARK_H

#include <vendor/sample/benchmark/1.0/IBenchmark.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace vendor {
namespace sample {
namespace benchmark {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Benchmark : public IBenchmark {
    // Methods from ::vendor::sample::benchmark::V1_0::IBenchmark follow.
    Return<void> writeMessage(const ::vendor::sample::benchmark::V1_0::SampleMessage& message) override;
    Return<void> writeMessageOneway(const ::vendor::sample::benchmark::V1_0::SampleMessage& message) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
extern "C" IBenchmark* HIDL_FETCH_IBenchmark(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace benchmark
}  // namespace sample
}  // namespace vendor

#endif  // VENDOR_SAMPLE_BENCHMARK_V1_0_BENCHMARK_H
