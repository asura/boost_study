#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <catch.hpp>

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
    "boost::functionを使ってみる",
    "[boost::function]")
{
    GIVEN("入れ物を用意")
    {
        boost::function<int(int)> f;

        WHEN("フリー関数を代入する")
        {
            f = ::freeMethod;

            THEN("boost::functionを通じて呼び出すことができる")
            {
                CHECK(f(123) == 246);
            }
        }

        WHEN("クラスメソッドを代入する")
        {
            ::Klass klass;
            f = boost::bind(&Klass::method, klass, boost::placeholders::_1);
            // 以下のようにインスタンスのポインタを指定してもOK
            // f = boost::bind(&Klass::method, &klass, boost::placeholders::_1);

            THEN("boost::functionを通じて呼び出すことができる")
            {
                CHECK(f(1) == 3);
            }
        }
    }
}
