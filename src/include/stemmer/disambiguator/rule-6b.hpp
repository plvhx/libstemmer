#ifndef _RULE_6B_HPP_
#define _RULE_6B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule6b : public stemmer::DisambiguatorAbstract
{
public:
	Rule6b();
	~Rule6b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_6B_HPP_ */