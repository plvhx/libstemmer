#ifndef _RULE_23_HPP_
#define _RULE_23_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule23 : public stemmer::DisambiguatorAbstract
{
public:
	Rule23();
	~Rule23();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_23_HPP_ */