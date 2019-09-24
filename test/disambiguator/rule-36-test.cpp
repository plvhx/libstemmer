#include <string>
#include <gtest/gtest.h>
#include <stemmer/disambiguator/rule-36.hpp>

using namespace std;
using namespace testing;
using namespace stemmer::disambiguator;

TEST(Rule36Test, Matching)
{
	Rule36 rule_;
	string rbuf_;

	{ ASSERT_TRUE(rule_.disambiguate("pekerja", rbuf_)); ASSERT_EQ("kerja", rbuf_); }
	{ ASSERT_TRUE(rule_.disambiguate("peserta", rbuf_)); ASSERT_EQ("serta", rbuf_); }
}