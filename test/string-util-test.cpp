#include <string>
#include <vector>
#include <gtest/gtest.h>
#include <stemmer/string-util.hpp>

using namespace std;
using namespace stemmer;
using namespace testing;

TEST(StringUtilTest, ToLowerCase)
{
	StringUtil su_;

	ASSERT_EQ("this is a text.", su_.tolower("This Is A Text."));
}

TEST(StringUtilTest, Trim)
{
	StringUtil su_;
	vector<string> tvec_{
		"\tthis is a text.\t",
		"\nthis is a text.\n",
		"\vthis is a text.\v",
		"\fthis is a text.\f",
		"\rthis is a text.\r",
		"  this is a text.  "
	};

	{ su_.trim(tvec_.at(0)); ASSERT_EQ("this is a text.", tvec_.at(0)); }
	{ su_.trim(tvec_.at(1)); ASSERT_EQ("this is a text.", tvec_.at(1)); }
	{ su_.trim(tvec_.at(2)); ASSERT_EQ("this is a text.", tvec_.at(2)); }
	{ su_.trim(tvec_.at(3)); ASSERT_EQ("this is a text.", tvec_.at(3)); }
	{ su_.trim(tvec_.at(4)); ASSERT_EQ("this is a text.", tvec_.at(4)); }
	{ su_.trim(tvec_.at(5)); ASSERT_EQ("this is a text.", tvec_.at(5)); }
}

TEST(StringUtilTest, RightTrim)
{
	StringUtil su_;
	vector<string> tvec_{
		"this is a text.\t",
		"this is a text.\n",
		"this is a text.\v",
		"this is a text.\f",
		"this is a text.\r",
		"this is a text.  "
	};

	{ su_.rtrim(tvec_.at(0)); ASSERT_EQ("this is a text.", tvec_.at(0)); }
	{ su_.rtrim(tvec_.at(1)); ASSERT_EQ("this is a text.", tvec_.at(1)); }
	{ su_.rtrim(tvec_.at(2)); ASSERT_EQ("this is a text.", tvec_.at(2)); }
	{ su_.rtrim(tvec_.at(3)); ASSERT_EQ("this is a text.", tvec_.at(3)); }
	{ su_.rtrim(tvec_.at(4)); ASSERT_EQ("this is a text.", tvec_.at(4)); }
	{ su_.rtrim(tvec_.at(5)); ASSERT_EQ("this is a text.", tvec_.at(5)); }
}

TEST(StringUtilTest, LeftTrim)
{
	StringUtil su_;
	vector<string> tvec_{
		"\tthis is a text.",
		"\nthis is a text.",
		"\vthis is a text.",
		"\fthis is a text.",
		"\rthis is a text.",
		"  this is a text."
	};

	{ su_.ltrim(tvec_.at(0)); ASSERT_EQ("this is a text.", tvec_.at(0)); }
	{ su_.ltrim(tvec_.at(1)); ASSERT_EQ("this is a text.", tvec_.at(1)); }
	{ su_.ltrim(tvec_.at(2)); ASSERT_EQ("this is a text.", tvec_.at(2)); }
	{ su_.ltrim(tvec_.at(3)); ASSERT_EQ("this is a text.", tvec_.at(3)); }
	{ su_.ltrim(tvec_.at(4)); ASSERT_EQ("this is a text.", tvec_.at(4)); }
	{ su_.ltrim(tvec_.at(5)); ASSERT_EQ("this is a text.", tvec_.at(5)); }
}

TEST(StringUtilTest, Normalize)
{
	StringUtil su_;
	string buf_ = "this,,is..a!!text$$";

	ASSERT_EQ("this is a text", su_.normalize(buf_));
}

TEST(StringUtilTest, Split)
{
	StringUtil su_;
	string buf_ = "this is a text.";
	vector<string> rvec_ = su_.split(" ", buf_);

	ASSERT_EQ(4, rvec_.size());
	ASSERT_EQ("this", rvec_.at(0));
	ASSERT_EQ("is", rvec_.at(1));
	ASSERT_EQ("a", rvec_.at(2));
	ASSERT_EQ("text.", rvec_.at(3));
}