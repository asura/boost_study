#include <catch2/catch.hpp>
#include <functional>

namespace
{
int freeMethod(int the_value)
{
    return the_value * 2;
}

struct Klass
{
    int method(int the_value)
    {
        return the_value + 2;
    }
};
}  // namespace

SCENARIO(
    "std::functionを使ってみる",
    "[std::function]")
{
    GIVEN("入れ物を用意")
    {
        std::function<int(int)> f;

        WHEN("フリー関数を代入する")
        {
            f = ::freeMethod;

            THEN("std::functionを通じて呼び出すことができる")
            {
                CHECK(f(123) == 246);
            }
        }

        WHEN("クラスメソッドを代入する")
        {
            ::Klass klass;
            f = std::bind(&Klass::method, klass, std::placeholders::_1);
            // 以下のようにインスタンスのポインタを指定してもOK
            // f = std::bind(&Klass::method, &klass, std::placeholders::_1);

            THEN("std::functionを通じて呼び出すことができる")
            {
                CHECK(f(1) == 3);
            }
        }

        WHEN("ラムダ式を代入する")
        {
            f = [](int the_value) { return the_value % 256; };

            THEN("std::functionを通じて呼び出すことができる")
            {
                CHECK(f(1025) == 1);
            }
        }
    }
}