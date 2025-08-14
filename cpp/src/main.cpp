#include <array>
#include <compare>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <optional>
#include <print>
#include <utility>
#include <string>
#include <format>

#include "CarFactory.h"
#include "Logger.h"
#include "TheOrigin.h"

using namespace std;

namespace mycode {
void foo() { std::println("foo() from mycode namespace."); }
namespace inner_space {
    int r;
    namespace inner_er_space {
        int j;
    }
} // namespace inner_space

} // namespace mycode

using namespace mycode;

optional<int> getData(bool giveIt)

{
    if (giveIt) {
        return 42;
    }
    return nullopt;
}

int main()
{
    unsigned uj { 5U };
    unsigned 中文 {5U };
    TheOrigin myOrigin;
    ToyotaFactory myFactory;
    auto myCar { myFactory.requestCar() };
println("こんにちは世界");
    auto b = { 11, 22 };
    println("{}", myCar->info());
    Logger::setLogFilename("log.out");
    std::println("Hueta?");
    std::println("{}", 中文);

    mycode::foo();
    foo();

    myOrigin.Attribute = true;
    println("myOrigin.Attrbute = {} ", myOrigin.Attribute);
    //  myOrigin.ShowTheRealAttribute();

    int i { 11 };
    strong_ordering result { i <=> 0 };

    if (result == strong_ordering::less) {
        println("less");
    }
    if (result == strong_ordering::greater) {
        println("greater");
    }
    if (result == strong_ordering::equal) {
        println("equal");
    }

    array<int, 3> arr { 9, 8, 7 };
    println("Array = {}", arr);
    println("Array size = {}", arr.size());
    println("Array 2nd element = {}", arr[1]);

    pair<double, int> myPair { 1.23, 5 };
    pair<char, int> myPair2 { 'c', 8 };
    println("my pair = {}", myPair);
    println("my pair2 = {}", myPair2);

    optional<int> data1 { getData(true) };
    optional<int> data2 { getData(false) };

    if (data1) {
        println("data1.has_value = {}", data1.has_value());
        println("data1.value = {}", data1.value());
    }

    println("data2.has_value = {}", data2.has_value());
    try {
        println("data2.value = {}", data2.value());
    } catch (const bad_optional_access& ex) {
        try {
            println("in 1st catch data2.value = {}", data2.value());
        } catch (const bad_optional_access& ex2) {
            println(" in 2nd catch Fuck up excepton: {}", ex2.what());
        }
    }
      int x{ 42 };
        int y{ 84 };

        // C-style function.
        printf("x has value %d and y has value %d.\n", x, y);

        // C++ I/O stream.
        cout << "x has value " << x << " and y has value " << y << '.' << endl;

        // C++20 std::format() + I/O streams.
        cout << format("x has value {} and y has value {}.", x, y) << endl;

        // C++23 std::println().
        println("x has value {} and y has value {}.", x, y);

        // C++23 std::println() + Unicode.
        println("こんにちは世界");

        // I/O streams + Unicode.
        cout << "こんにちは世界" << endl;

        // C++23 std::println() + Unicode emojis.
        println("😀");
    return 0;
}
