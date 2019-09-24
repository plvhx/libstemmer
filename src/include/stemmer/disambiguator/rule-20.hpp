#ifndef _RULE_20_HPP_
#define _RULE_20_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule20 : public stemmer::DisambiguatorAbstract
{
public:
	Rule20();
	~Rule20();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_20_HPP_ */