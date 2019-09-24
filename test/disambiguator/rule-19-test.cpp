#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-19.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule19Test, Matching)
{
	Rule19 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("memproteksi", rbuf_)); ASSERT_EQ("proteksi", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("mempatroli", rbuf_)); ASSERT_EQ("patroli", rbuf_); }
}