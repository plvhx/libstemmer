#ifndef _RULE_5_HPP_
#define _RULE_5_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule5 : public stemmer::DisambiguatorAbstract
{
public:
	Rule5();
	~Rule5();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_5_HPP_ */