#ifndef _RULE_19_HPP_
#define _RULE_19_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule19 : public stemmer::DisambiguatorAbstract
{
public:
	Rule19();
	~Rule19();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_19_HPP_ */