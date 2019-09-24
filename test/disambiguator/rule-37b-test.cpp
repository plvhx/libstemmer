#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-37b.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule37bTest, Matching)
{
	Rule37b rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("gerigi", rbuf_)); ASSERT_EQ("gigi", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("serabut", rbuf_)); ASSERT_EQ("sabut", rbuf_); }
}