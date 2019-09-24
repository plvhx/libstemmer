#ifndef _RULE_42_HPP_
#define _RULE_42_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule42 : public stemmer::DisambiguatorAbstract
{
public:
	Rule42();
	~Rule42();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_42_HPP_ */