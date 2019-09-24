#ifndef _RULE_39B_HPP_
#define _RULE_39B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule39b : public stemmer::DisambiguatorAbstract
{
public:
	Rule39b();
	~Rule39b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_39B_HPP_ */