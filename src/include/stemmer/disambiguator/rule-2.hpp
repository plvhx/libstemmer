#ifndef _RULE_2_HPP_
#define _RULE_2_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule2 : public stemmer::DisambiguatorAbstract
{
public:
	Rule2();
	~Rule2();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_2_HPP_ */