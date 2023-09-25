#include "StreamCapture.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>

using namespace Utility;
using namespace std;

TEST_CASE("StreamCapture string")
{
    auto result = StreamCapture<char>::capture([]()
                                               { cout << "This is a string test."; });
    REQUIRE(result == "This is a string test.");
}

TEST_CASE("StreamCapture wstring")
{
    auto result = StreamCapture<wchar_t>::capture([]()
                                                  { wcout << L"This is a wide string test."; });
    REQUIRE(result == L"This is a wide string test.");
}
