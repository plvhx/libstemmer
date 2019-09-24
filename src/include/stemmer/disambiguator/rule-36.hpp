#ifndef _RULE_36_HPP_
#define _RULE_36_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule36 : public stemmer::DisambiguatorAbstract
{
public:
	Rule36();
	~Rule36();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_36_HPP_ */