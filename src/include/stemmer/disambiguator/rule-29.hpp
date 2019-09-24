#ifndef _RULE_29_HPP_
#define _RULE_29_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule29 : public stemmer::DisambiguatorAbstract
{
public:
	Rule29();
	~Rule29();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_29_HPP_ */