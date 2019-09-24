#ifndef _RULE_3_HPP_
#define _RULE_3_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule3 : public stemmer::DisambiguatorAbstract
{
public:
	Rule3();
	~Rule3();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}
#endif /* _RULE_3_HPP_ */