#ifndef _STOPWORD_REMOVER_FACTORY_HPP_
#define _STOPWORD_REMOVER_FACTORY_HPP_

#include <cstddef>
#include <string>
#include <map>
#include <stemmer/dictionary.hpp>
#include <stemmer/stopword-remover.hpp>

namespace stemmer {

class StopwordRemoverFactory
{
public:
	StopwordRemoverFactory();
	~StopwordRemoverFactory();

	StopwordRemover *create();

protected:
	Dictionary *dict_;
	StopwordRemover *sr_;

	std::map<uint32_t, std::string> getStopWords();
};

}

#endif /* _STOPWORD_REMOVER_FACTORY_HPP_ */