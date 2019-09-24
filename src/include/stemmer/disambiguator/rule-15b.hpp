#ifndef _RULE_15B_HPP_
#define _RULE_15B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule15b : public stemmer::DisambiguatorAbstract
{
public:
	Rule15b();
	~Rule15b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_15B_HPP_ */