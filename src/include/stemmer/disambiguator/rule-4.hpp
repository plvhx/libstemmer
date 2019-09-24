#ifndef _RULE_4_HPP_
#define _RULE_4_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule4 : public stemmer::DisambiguatorAbstract
{
public:
	Rule4();
	~Rule4();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_4_HPP_ */