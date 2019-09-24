#ifndef _DICTIONARY_HPP_
#define _DICTIONARY_HPP_

#include <cstddef>
#include <string>
#include <map>
#include <vector>
#include <stemmer/dictionary-abstract.hpp>

#ifndef DICT_CONST_HASH
# define DICT_CONST_HASH	(0x01020304 >> 16)
#endif

namespace stemmer {

class Dictionary : public DictionaryAbstract
{
public:
	Dictionary();
	~Dictionary();

	void add(std::string buf_);
	void remove(std::string buf_);
	void make(std::map<uint32_t, std::string> pdict_);
	void makeFromFile(std::string file_);
	bool search(std::string buf_);
	std::vector<std::string> items();
	std::vector<uint32_t> keys();
	size_t size();

private:
	std::map<uint32_t, std::string> dict_;
};

}

#endif /* _DICTIONARY_HPP_ */