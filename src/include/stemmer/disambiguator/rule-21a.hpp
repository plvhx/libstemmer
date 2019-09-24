#ifndef _RULE_21A_HPP_
#define _RULE_21A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule21a : public stemmer::DisambiguatorAbstract
{
public:
	Rule21a();
	~Rule21a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_21A_HPP_ */