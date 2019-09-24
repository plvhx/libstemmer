#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-40a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule40aTest, Matching)
{
	Rule40a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pinang", rbuf_)); ASSERT_EQ("pinang", rbuf_); }
}