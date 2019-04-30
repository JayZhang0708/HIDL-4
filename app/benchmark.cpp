#define LOG_TAG     "benchmark"
#include <stdio.h>
#include <stdint.h>
#include <utils/StopWatch.h>
#include <vendor/sample/benchmark/1.0/IBenchmark.h>
#include <vendor/sample/benchmark/1.0/types.h>
#include <hidl/Status.h>
#include <hidl/HidlSupport.h>
#include <string.h>
#include <log/log.h>
#include "sample.h"

using android::sp;
using android::hardware::Return;
using ::vendor::sample::benchmark::V1_0::IBenchmark;
using ::vendor::sample::benchmark::V1_0::SampleMessage;

#define BUFFER_SIZE     1024

uint8_t buffer[BUFFER_SIZE];

sp<IBenchmark> benchmark;

void test_function_call(void)
{
    android::StopWatch stopWatch("test_function_call");
    writeMessage(buffer, BUFFER_SIZE);
}

void test_hidl_interface(void)
{
    SampleMessage message;
    message.size = BUFFER_SIZE;
    message.data.resize(BUFFER_SIZE);
    ::memcpy(&message.data[0], buffer, BUFFER_SIZE);
    android::StopWatch stopWatch("test_hidl_interface");
    benchmark->writeMessage(message);
}

void test_oneway_hidl_interface(void)
{
    SampleMessage message;
    message.size = BUFFER_SIZE;
    message.data.resize(BUFFER_SIZE);
    ::memcpy(&message.data[0], buffer, BUFFER_SIZE);
    android::StopWatch stopWatch("test_oneway_hidl_interface");
    benchmark->writeMessageOneway(message);
}

int main(void)
{
    benchmark = IBenchmark::getService();
    if(benchmark == nullptr) {
        printf("Failed to get benckmark service\n");
        return -1;
    }

    test_function_call();
    test_hidl_interface();
    test_oneway_hidl_interface();

    return 0;
}
