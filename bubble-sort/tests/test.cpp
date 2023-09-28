#include "BubbleSort.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include "../../helper/include/StreamCapture.h"
#include "../../helper/include/ArrayPrinter.h"

using namespace Sorting;
using namespace Utility;
using namespace std;

TEST_CASE("Bubble Sort Test")
{
    int data[] = {64, 34, 25, 12, 22, 11, 90};

    BubbleSort(data).sort();
    auto sorted = StreamCapture<char>::capture([&]()
                                               { cout << ArrayPrinter(data); });
    REQUIRE(sorted == "11 12 22 25 34 64 90 ");
}
