#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-31a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule31aTest, Matching)
{
	Rule31a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("penyanyi", rbuf_)); ASSERT_EQ("nyanyi", rbuf_); }
}