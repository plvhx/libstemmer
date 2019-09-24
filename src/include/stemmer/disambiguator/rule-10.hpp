#ifndef _RULE_10_HPP_
#define _RULE_10_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule10 : public stemmer::DisambiguatorAbstract
{
public:
	Rule10();
	~Rule10();
	
	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_10_HPP_ */