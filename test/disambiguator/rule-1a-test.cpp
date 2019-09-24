#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-1a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule1aTest, Matching)
{
	Rule1a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("beria-ia", rbuf_)); ASSERT_EQ("ia-ia", rbuf_); }
	{ ASSERT_FALSE(rule_.disambiguate("berlari", rbuf_)); }
}