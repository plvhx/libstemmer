#ifndef _CONTEXT_HPP_
#define _CONTEXT_HPP_

#include <string>
#include <vector>
#include <stemmer/dictionary.hpp>
#include <stemmer/context/context-abstract.hpp>
#include <stemmer/context/removal-abstract.hpp>
#include <stemmer/context/visitor/visitor-abstract.hpp>
#include <stemmer/context/visitor/visitor-provider.hpp>

namespace stemmer {
namespace context {

class Context : public ContextAbstract
{
public:
	Context(std::string& buf_, stemmer::Dictionary* rdict_, visitor::VisitorProvider* prov_): original_word_(buf_), current_word_(buf_), dict_(rdict_), visitor_prov_(prov_), is_stopped_(false)
	{
		initVisitors();
	}

	~Context();

	std::string getOriginalWord();
	void setOriginalWord(std::string buf_);
	std::string getCurrentWord();
	void setCurrentWord(std::string buf_);
	stemmer::Dictionary *getDictionary();
	void setDictionary(stemmer::Dictionary *rdict_);
	void stopProcess();
	bool isProcessStopped();
	void constructRemoval(std::string current_, std::string result_, std::string part_, std::string af_type_);
	std::vector<RemovalAbstract *>& getRemovals();
	void restorePrefix();
	void processAllSuffix();
	std::string getResult();
	void execute();

protected:
	std::string original_word_;
	std::string current_word_;
	bool is_stopped_;
	std::vector<RemovalAbstract *> removals_;
	stemmer::Dictionary *dict_;
	visitor::VisitorProvider *visitor_prov_;
	std::vector<visitor::VisitorAbstract *> visitors_;
	std::vector<visitor::VisitorAbstract *> suffix_visitors_;
	std::vector<visitor::VisitorAbstract *> prefix_visitors_;
	std::string result_;

	void initVisitors();
	void orderFromPrefixToSuffix();
	void orderFromSuffixToPrefix();
	void startStemmingProcess();
	void removePrefixes();
	void removeSuffixes();
	std::vector<visitor::VisitorAbstract *>& getVisitors();
	std::vector<visitor::VisitorAbstract *>& getPrefixVisitors();
	std::vector<visitor::VisitorAbstract *>& getSuffixVisitors();
	bool acceptVisitors(std::vector<visitor::VisitorAbstract *>& rvisitors_, std::string& rbuf_);
	bool acceptPrefixVisitors(std::vector<visitor::VisitorAbstract *>& rprefix_visitors_, std::string& rbuf_);
	bool isSuffixRemoval(RemovalAbstract *rem_);
	void destroy();
};

}
}

#endif /* _CONTEXT_HPP_ */