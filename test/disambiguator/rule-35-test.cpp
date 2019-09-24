#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-35.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule35Test, Matching)
{
	Rule35 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("terpercaya", rbuf_)); ASSERT_EQ("percaya", rbuf_); }
}