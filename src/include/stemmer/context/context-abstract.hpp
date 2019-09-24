#ifndef _CONTEXT_ABSTRACT_HPP_
#define _CONTEXT_ABSTRACT_HPP_

#include <string>
#include <vector>
#include <stemmer/dictionary.hpp>
#include <stemmer/context/removal-abstract.hpp>

namespace stemmer {
namespace context {

class ContextAbstract
{
public:
	virtual std::string getOriginalWord() = 0;
	virtual void setOriginalWord(std::string buf_) = 0;
	virtual std::string getCurrentWord() = 0;
	virtual void setCurrentWord(std::string buf_) = 0;
	virtual stemmer::Dictionary *getDictionary() = 0;
	virtual void setDictionary(stemmer::Dictionary *rdict_) = 0;
	virtual void stopProcess() = 0;
	virtual bool isProcessStopped() = 0;
	virtual void constructRemoval(std::string current_, std::string result_, std::string part_, std::string af_type_) = 0;
	virtual std::vector<RemovalAbstract *>& getRemovals() = 0;
};

}
}

#endif /* _CONTEXT_ABSTRACT_HPP_ */