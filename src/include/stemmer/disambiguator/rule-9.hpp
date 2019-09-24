#ifndef _RULE_9_HPP_
#define _RULE_9_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule9 : public stemmer::DisambiguatorAbstract
{
public:
	Rule9();
	~Rule9();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_9_HPP_ */