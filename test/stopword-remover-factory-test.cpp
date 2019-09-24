#include <gtest/gtest.h>
#include <stemmer/stopword-remover-factory.hpp>

using namespace stemmer;
using namespace testing;

TEST(StopwordRemoverFactory, EqualityTest)
{
	StopwordRemoverFactory *sr_ = new StopwordRemoverFactory();

	ASSERT_EQ("pergi sekolah", sr_->create()->remove("pergi ke sekolah"));
	ASSERT_EQ("makan rumah", sr_->create()->remove("makan di rumah"));

	delete sr_;
}