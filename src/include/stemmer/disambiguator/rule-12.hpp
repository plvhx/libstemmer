#ifndef _RULE_12_HPP_
#define _RULE_12_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule12 : public stemmer::DisambiguatorAbstract
{
public:
	Rule12();
	~Rule12();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_12_HPP_ */