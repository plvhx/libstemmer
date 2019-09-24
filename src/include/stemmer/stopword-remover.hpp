#ifndef _STOPWORD_REMOVER_HPP_
#define _STOPWORD_REMOVER_HPP_

#include <string>
#include <stemmer/dictionary.hpp>

namespace stemmer {

class StopwordRemover
{
public:
	StopwordRemover(Dictionary *rdict_): dict_(rdict_) {}
	~StopwordRemover();

	Dictionary* getDictionary();
	std::string remove(std::string buf_);

protected:
	Dictionary *dict_;
};

}

#endif /* _STOPWORD_REMOVER_HPP_ */