#ifndef _RULE_21B_HPP_
#define _RULE_21B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule21b : public stemmer::DisambiguatorAbstract
{
public:
	Rule21b();
	~Rule21b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_21B_HPP_ */