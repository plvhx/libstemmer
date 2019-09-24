#include <string>
#include <gtest/gtest.h>
#include <stemmer/dictionary.hpp>
#include <stemmer/hash.hpp>
#include <map>

using namespace std;
using namespace stemmer;
using namespace testing;

TEST(DictionaryTest, AddAndContain)
{
	Dictionary dict_;

	EXPECT_FALSE(dict_.search("word"));

	dict_.add("word");

	EXPECT_TRUE(dict_.search("word"));
}

TEST(DictionaryTest, AddCountWord)
{
	Dictionary dict_;

	EXPECT_EQ(0, dict_.size());

	dict_.add("word");

	EXPECT_EQ(1, dict_.size());
}

TEST(DictionaryTest, AddVectorOfWords)
{
	Dictionary dict_;
	Hash ho_;
	map<uint32_t, string> umap_;

	umap_.insert(make_pair(ho_.generate("word1", DICT_CONST_HASH), "word1"));
	umap_.insert(make_pair(ho_.generate("word2", DICT_CONST_HASH), "word2"));

	dict_.make(umap_);

	EXPECT_EQ(2, dict_.size());
	EXPECT_TRUE(dict_.search("word1"));
	EXPECT_TRUE(dict_.search("word2"));
}