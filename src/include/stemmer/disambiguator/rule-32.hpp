#ifndef _RULE_32_HPP_
#define _RULE_32_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule32 : public stemmer::DisambiguatorAbstract
{
public:
	Rule32();
	~Rule32();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_32_HPP_ */