#ifndef _RULE_16_HPP_
#define _RULE_16_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule16 : public stemmer::DisambiguatorAbstract
{
public:
	Rule16();
	~Rule16();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_16_HPP_ */