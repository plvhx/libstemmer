#ifndef _DISAMBIGUATOR_ABSTRACT_HPP_
#define _DISAMBIGUATOR_ABSTRACT_HPP_

#include <string>

namespace stemmer {

class DisambiguatorAbstract
{
public:
	virtual bool disambiguate(std::string buf_, std::string& rbuf_) = 0;
};

}

#endif /* _DISAMBIGUATOR_ABSTRACT_HPP_ */