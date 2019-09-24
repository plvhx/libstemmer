#ifndef _RULE_24_HPP_
#define _RULE_24_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule24 : public stemmer::DisambiguatorAbstract
{
public:
	Rule24();
	~Rule24();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_24_HPP_ */