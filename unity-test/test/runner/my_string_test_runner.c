#include <unity.h>
#include <unity_fixture.h>

TEST_GROUP_RUNNER( MyString )
{
  RUN_TEST_CASE( MyString, my_string_should_return_hello_where_0_is_given );
  RUN_TEST_CASE( MyString, my_string_should_return_goodbye_where_1_is_given );
  RUN_TEST_CASE( MyString, my_string_should_return_greeting_otherwise );
}
