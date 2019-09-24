#ifndef _RULE_30C_HPP_
#define _RULE_30C_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule30c : public stemmer::DisambiguatorAbstract
{
public:
	Rule30c();
	~Rule30c();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_30C_HPP_ */