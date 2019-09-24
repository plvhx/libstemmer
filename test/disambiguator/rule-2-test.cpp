#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-2.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule2Test, Matching)
{
	Rule2 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("bertabur", rbuf_)); ASSERT_EQ("tabur", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("beria-ia", rbuf_)); }
}