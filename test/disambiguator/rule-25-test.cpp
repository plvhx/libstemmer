#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-25.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule25Test, Matching)
{
	Rule25 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pembaruan", rbuf_)); ASSERT_EQ("baruan", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pemfokusan", rbuf_)); ASSERT_EQ("fokusan", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("pemvaksinan", rbuf_)); ASSERT_EQ("vaksinan", rbuf_); }
}