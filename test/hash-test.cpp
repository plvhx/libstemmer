#include <string>
#include <gtest/gtest.h>
#include <stemmer/hash.hpp>

using namespace std;
using namespace stemmer;
using namespace testing;

#define HASH_SEED	0x01020304

TEST(HashTest, HashEqualsTest)
{
	Hash ho_;

	ASSERT_EQ(361661731, ho_.generate("This is a text.", HASH_SEED));
}