#ifndef _RULE_30A_HPP_
#define _RULE_30A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule30a : public stemmer::DisambiguatorAbstract
{
public:
	Rule30a();
	~Rule30a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_30A_HPP_ */