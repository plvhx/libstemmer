#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-13b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule13bTest, Matching)
{
	Rule13b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("memakai", rbuf_)); ASSERT_EQ("pakai", rbuf_); }
}