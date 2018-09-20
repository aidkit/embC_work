/*
 * SprintfTest.cpp
 *
 *  Created on: 2018/09/20
 *      Author: P18886
 */

#include "CppUTest/TestHarness.h"

extern "C"
{
#include <stdio.h>
#include <memory.h>
}

//START: testGroup
TEST_GROUP(sprintf)
{
	char output[100];
	const char* expected;

	void setup()
	{
		memset(output, 0xaa, sizeof output);
		expected = "";
	}

	void teardown()
	{
	}

	void expect(const char* s)
	{
		expected = s;
	}

	void given(int charsWritten)
	{
		LONGS_EQUAL(strlen(expected), charsWritten);
		STRCMP_EQUAL(expected, output);
		BYTES_EQUAL(0xaa, output[strlen(expected)+1]);

	}
};
//END: testGroup

#if 1
TEST(sprintf, NoformatOperations)
{
	expect("hey");
	given(sprintf(output, "hey"));

}

TEST(sprintf, InsertString)
{
	expect("Hello World\n");
	given(sprintf(output, "Hello %s\n", "World"));
}
#else
TEST(sprintf, NoFomatOperations)	// chapter 2.2.3
{
	char output[5];
	LONGS_EQUAL(4, sprintf(output, "hey"));
	STRCMP_EQUAL("hey", output);
}
#endif
