#ifndef _RULE_17A_HPP_
#define _RULE_17A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule17a : public stemmer::DisambiguatorAbstract
{
public:
	Rule17a();
	~Rule17a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_17A_HPP_ */