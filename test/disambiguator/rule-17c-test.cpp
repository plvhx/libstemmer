#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-17c.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule17cTest, Matching)
{
	Rule17c rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("mengecas", rbuf_)); ASSERT_EQ("cas", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("mengecat", rbuf_)); ASSERT_EQ("cat", rbuf_); }
}