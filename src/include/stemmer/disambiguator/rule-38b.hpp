#ifndef _RULE_38B_HPP_
#define _RULE_38B_HPP_

#include <string>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {
namespace disambiguator {

class Rule38b : public stemmer::DisambiguatorAbstract
{
public:
	Rule38b();
	~Rule38b();

	bool disambiguate(std::string buf_, std::string& rbuf_);
};

}
}

#endif /* _RULE_38B_HPP_ */