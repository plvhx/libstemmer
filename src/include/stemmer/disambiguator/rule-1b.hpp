#ifndef _RULE_1B_HPP_
#define _RULE_1B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule1b : public stemmer::DisambiguatorAbstract
{
public:
	Rule1b();
	~Rule1b();
	
	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_1B_HPP_ */