#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-41.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule41Test, Matching)
{
	Rule41 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("kumiliki", rbuf_)); ASSERT_EQ("miliki", rbuf_); }
}