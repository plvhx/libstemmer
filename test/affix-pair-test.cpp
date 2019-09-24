#include <string>
#include <gtest/gtest.h>
#include <stemmer/affix-pair.hpp>

using namespace std;
using namespace stemmer;
using namespace testing;

TEST(AffixPairTest, TruthTest)
{
	AffixPair ap_;

	EXPECT_FALSE(ap_.isSatisfiedBy("memberikan"));
	EXPECT_FALSE(ap_.isSatisfiedBy("ketahui"));

	EXPECT_TRUE(ap_.isSatisfiedBy("berjatuhi"));
	EXPECT_TRUE(ap_.isSatisfiedBy("dipukulan"));
	EXPECT_TRUE(ap_.isSatisfiedBy("ketiduri"));
	EXPECT_TRUE(ap_.isSatisfiedBy("ketidurkan"));
	EXPECT_TRUE(ap_.isSatisfiedBy("menduaan"));
	EXPECT_TRUE(ap_.isSatisfiedBy("terduaan"));
	EXPECT_TRUE(ap_.isSatisfiedBy("perkataan"));
}