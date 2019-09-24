#ifndef _DISAMBIGUATOR_RULE_FACTORY_HPP_
#define _DISAMBIGUATOR_RULE_FACTORY_HPP_

#include <map>
#include <string>
#include <vector>
#include <stemmer/disambiguator-abstract.hpp>

namespace stemmer {

class DisambiguatorRuleFactory
{
public:
	DisambiguatorRuleFactory();
	~DisambiguatorRuleFactory();

	std::vector<DisambiguatorAbstract *>& getDisambiguators(std::string key_);

protected:
	std::map<std::string, std::vector<DisambiguatorAbstract *>> cont_;

	void initRules();
	void destroyRules();
};

}

#endif /* _DISAMBIGUATOR_RULE_FACTORY_HPP_ */