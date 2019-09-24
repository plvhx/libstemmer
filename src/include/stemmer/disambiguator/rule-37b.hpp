#ifndef _RULE_37B_HPP_
#define _RULE_37B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule37b : public stemmer::DisambiguatorAbstract
{
public:
	Rule37b();
	~Rule37b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_37B_HPP_ */