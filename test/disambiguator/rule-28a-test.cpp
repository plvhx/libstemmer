#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-28a.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule28aTest, Matching)
{
	Rule28a rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("penilai", rbuf_)); ASSERT_EQ("nilai", rbuf_); }
}