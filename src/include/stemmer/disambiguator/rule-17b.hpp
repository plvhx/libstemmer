#ifndef _RULE_17B_HPP_
#define _RULE_17B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule17b : public stemmer::DisambiguatorAbstract
{
public:
	Rule17b();
	~Rule17b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_17B_HPP_ */