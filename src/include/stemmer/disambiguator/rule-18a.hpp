#ifndef _RULE_18A_HPP_
#define _RULE_18A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule18a : public stemmer::DisambiguatorAbstract
{
public:
	Rule18a();
	~Rule18a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_18A_HPP_ */