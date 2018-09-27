#include <unity.h>
#include <unity_fixture.h>

#include "my_string.h"


TEST_GROUP( MyString );


TEST_SETUP( MyString )
{}

TEST_TEAR_DOWN( MyString )
{}

/**
 * 0 のときは Hello の定型文を書き込む
 * 予想される文字列であることをテストします
 */
TEST( MyString, my_string_should_return_hello_where_0_is_given )
{
    char buffer[256] = "";

    my_string( 0, buffer );
    TEST_ASSERT_EQUAL_STRING( "(^O^) < Hello", buffer );
}

/**
 * 1 のときは goodby の定型文を書き込む
 * 予想される文字列であることをテストします
 */
TEST( MyString, my_string_should_return_goodbye_where_1_is_given )
{
    char buffer[256] = "";

    my_string( 1, buffer );
    TEST_ASSERT_EQUAL_STRING( "(T_T) < goodby", buffer );
}

/**
 * それ以外は seeyou の定型文を書き込む
 * 予想される文字列であることを適当な範囲でテストします
 */
TEST( MyString, my_string_should_return_greeting_otherwise )
{
    char buffer[256] = "";

    my_string( 2, buffer );
    TEST_ASSERT_EQUAL_STRING( "(・v・) < seeyou", buffer );

    my_string( 10, buffer );
    TEST_ASSERT_EQUAL_STRING( "(・v・) < seeyou", buffer );

    my_string( -50, buffer );
    TEST_ASSERT_EQUAL_STRING( "(・v・) < seeyou", buffer );

    my_string( 1000, buffer );
    TEST_ASSERT_EQUAL_STRING( "(・v・) < seeyou", buffer );
}

