#ifndef _DICTIONARY_ABSTRACT_HPP_
#define _DICTIONARY_ABSTRACT_HPP_

#include <string>
#include <map>
#include <vector>
#include <cstddef>

namespace stemmer {

class DictionaryAbstract
{
public:
	virtual void add(std::string buf_) = 0;
	virtual void remove(std::string buf_) = 0;
	virtual void make(std::map<uint32_t, std::string> pdict_) = 0;
	virtual void makeFromFile(std::string file_) = 0;
	virtual bool search(std::string buf_) = 0;
	virtual std::vector<std::string> items() = 0;
	virtual std::vector<uint32_t> keys() = 0;
	virtual size_t size() = 0;
};

}

#endif /* _DICTIONARY_ABSTRACT_HPP_ */