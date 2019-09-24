#ifndef _STEMMER_HPP_
#define _STEMMER_HPP_

#include <string>
#include <vector>
#include <stemmer/dictionary.hpp>
#include <stemmer/stemmer-abstract.hpp>
#include <stemmer/context/visitor/visitor-provider.hpp>

namespace stemmer {

class Stemmer : public StemmerAbstract
{
public:
	Stemmer(Dictionary *rda_, context::visitor::VisitorProvider *rprov_): da_(rda_), prov_(rprov_)
	{
	}

	~Stemmer()
	{
	}

	std::string stem(std::string buf_);

protected:
	Dictionary *da_;
	context::visitor::VisitorProvider *prov_;

	std::string normalizeText(std::string buf_);
	std::string toLowerCase(std::string buf_);
	std::string trimWhitespace(std::string buf_);
	std::vector<std::string> split(std::string delim_, std::string buf_);
	std::string stemWord(std::string buf_);
	bool isPlural(std::string buf_);
	bool stemPluralWord(std::string buf_, std::string& rbuf_);
	bool stemSingularWord(std::string buf_, std::string& rbuf_);
};

}

#endif /* _STEMMER_HPP_ */