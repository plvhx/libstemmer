#ifndef _RULE_6A_HPP_
#define _RULE_6A_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule6a : public stemmer::DisambiguatorAbstract
{
public:
	Rule6a();
	~Rule6a();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_6A_HPP_ */