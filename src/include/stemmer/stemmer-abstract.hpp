#ifndef _STEMMER_ABSTRACT_HPP_
#define _STEMMER_ABSTRACT_HPP_

#include <string>

namespace stemmer {

class StemmerAbstract
{
public:
	virtual std::string stem(std::string buf_) = 0;
};

}

#endif /* _STEMMER_ABSTRACT_HPP_ */