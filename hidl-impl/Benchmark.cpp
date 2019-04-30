#include "Benchmark.h"
#include "sample.h"

namespace vendor {
namespace sample {
namespace benchmark {
namespace V1_0 {
namespace implementation {

// Methods from ::vendor::sample::benchmark::V1_0::IBenchmark follow.
Return<void> Benchmark::writeMessage(const ::vendor::sample::benchmark::V1_0::SampleMessage& message) {
    // TODO implement
    ::writeMessage((uint8_t *)(&message.data[0]), message.size);
    return Void();
}

Return<void> Benchmark::writeMessageOneway(const ::vendor::sample::benchmark::V1_0::SampleMessage& message) {
    // TODO implement
    ::writeMessage((uint8_t *)(&message.data[0]), message.size);
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

IBenchmark* HIDL_FETCH_IBenchmark(const char* /* name */) {
    return new Benchmark();
}
//
}  // namespace implementation
}  // namespace V1_0
}  // namespace benchmark
}  // namespace sample
}  // namespace vendor
