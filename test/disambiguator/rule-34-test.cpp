#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-34.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule34Test, Matching)
{
	Rule34 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("petarung", rbuf_)); ASSERT_EQ("tarung", rbuf_); }
}