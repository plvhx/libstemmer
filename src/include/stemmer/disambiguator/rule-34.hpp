#ifndef _RULE_34_HPP_
#define _RULE_34_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule34 : public stemmer::DisambiguatorAbstract
{
public:
	Rule34();
	~Rule34();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_34_HPP_ */