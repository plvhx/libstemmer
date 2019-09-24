#ifndef _RULE_8_HPP_
#define _RULE_8_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule8 : public stemmer::DisambiguatorAbstract
{
public:
	Rule8();
	~Rule8();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_8_HPP_ */