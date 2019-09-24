#ifndef _RULE_18B_HPP_
#define _RULE_18B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule18b : public stemmer::DisambiguatorAbstract
{
public:
	Rule18b();
	~Rule18b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_18B_HPP_ */