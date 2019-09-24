#include <string>
#include <vector>
#include <stemmer/precedence-adjustor-specification.hpp>
#include <stemmer/context/removal.hpp>
#include <stemmer/context/context.hpp>

using namespace std;
using namespace stemmer;
using namespace stemmer::context;
using namespace stemmer::context::visitor;

Context::~Context()
{
	destroy();
}

void Context::setDictionary(Dictionary *rdict_)
{
	dict_ = rdict_;
}

Dictionary *Context::getDictionary()
{
	return dict_;
}

string Context::getOriginalWord()
{
	return original_word_;
}

void Context::setOriginalWord(string buf_)
{
	original_word_ = buf_;
}

string Context::getCurrentWord()
{
	return current_word_;
}

void Context::setCurrentWord(string buf_)
{
	current_word_ = buf_;
}

void Context::stopProcess()
{
	is_stopped_ = true;
}

bool Context::isProcessStopped()
{
	return is_stopped_;
}

void Context::constructRemoval(string current_, string result_, string part_, string af_type_)
{
	removals_.push_back(new Removal(current_, result_, part_, af_type_));
}

vector<RemovalAbstract *>& Context::getRemovals()
{
	return removals_;
}

vector<VisitorAbstract *>& Context::getVisitors()
{
	return visitors_;
}

vector<VisitorAbstract *>& Context::getPrefixVisitors()
{
	return prefix_visitors_;
}

vector<VisitorAbstract *>& Context::getSuffixVisitors()
{
	return suffix_visitors_;
}

string Context::getResult()
{
	return result_;
}

void Context::execute()
{
	startStemmingProcess();
	result_ = (dict_->search(getCurrentWord()) ? getCurrentWord() : getOriginalWord());
}

void Context::initVisitors()
{
	visitors_ = visitor_prov_->getVisitors();
	suffix_visitors_ = visitor_prov_->getSuffixVisitors();
	prefix_visitors_ = visitor_prov_->getPrefixVisitors();
}

void Context::orderFromPrefixToSuffix()
{
	// step 4, 5
	removePrefixes();

	if (!dict_->search(getCurrentWord())) {
		// step 2, 3
		removeSuffixes();

		if (!dict_->search(getCurrentWord())) {
			setCurrentWord(getOriginalWord());
			destroy();
			orderFromSuffixToPrefix();
		}
	}
}

void Context::orderFromSuffixToPrefix()
{
	// step 2, 3
	removeSuffixes();

	if (!dict_->search(getCurrentWord())) {
		// step 4, 5
		removePrefixes();

		if (!dict_->search(getCurrentWord())) {
			processAllSuffix();
		}
	}
}

void Context::startStemmingProcess()
{
	PrecedenceAdjustorSpecification pas_;
	string rbuf_;

	// step 1
	if (!dict_->search(getCurrentWord())) {
		acceptVisitors(getVisitors(), rbuf_);

		if (!dict_->search(getCurrentWord())) {
			if (pas_.isSatisfiedBy(getOriginalWord())) {
				orderFromPrefixToSuffix();
			} else {
				orderFromSuffixToPrefix();
			}
		}
	}
}

void Context::removePrefixes()
{
	string rbuf_;

	for (unsigned i = 0; i < 3; i++) {
		if (!dict_->search(getCurrentWord())) {
			acceptPrefixVisitors(getPrefixVisitors(), rbuf_);
		}
	}
}

void Context::removeSuffixes()
{
	string rbuf_;

	acceptVisitors(getSuffixVisitors(), rbuf_);
}

bool Context::acceptVisitors(vector<VisitorAbstract *>& rvisitors_, std::string& rbuf_)
{
	bool res_ = false;

	for (unsigned i = 0; i < rvisitors_.size(); i++) {
		rvisitors_.at(i)->visit(*this);

		if (dict_->search(getCurrentWord()) || isProcessStopped()) {
			rbuf_ = getCurrentWord();
			res_ = true;
			break;
		}
	}

	return res_;
}

bool Context::acceptPrefixVisitors(vector<VisitorAbstract *>& rprefix_visitors_, std::string& rbuf_)
{
	bool res_ = false;
	unsigned trsize_ = removals_.size();

	for (unsigned i = 0; i < rprefix_visitors_.size(); i++) {
		rprefix_visitors_.at(i)->visit(*this);

		if (dict_->search(getCurrentWord()) || isProcessStopped() || (removals_.size() > trsize_)) {
			rbuf_ = getCurrentWord();
			res_ = true;
			break;
		}
	}

	return res_;
}

void Context::processAllSuffix()
{
	restorePrefix();

	string cw_ = getCurrentWord();

	for (int i = removals_.size() - 1; i >= 0; i--) {
		if (isSuffixRemoval(removals_.at(i)) || removals_.at(i)->getAffixType() != "DP") {
			if (removals_.at(i)->getRemovedPart() == "kan") {
				setCurrentWord(removals_.at(i)->getResult() + "k");

				// step 4, 5
				removePrefixes();

				if (dict_->search(getCurrentWord())) {
					break;
				}

				setCurrentWord(removals_.at(i)->getResult() + "kan");
			} else {
				setCurrentWord(removals_.at(i)->getSubject());
			}

			// step 4, 5
			removePrefixes();

			if (dict_->search(getCurrentWord())) {
				break;
			}

			setCurrentWord(cw_);
		}
	}
}

bool Context::isSuffixRemoval(RemovalAbstract *rem_)
{
	return (
		rem_->getAffixType() == "DS" ||
		rem_->getAffixType() == "PP" ||
		rem_->getAffixType() == "P"
	);
}

void Context::destroy()
{
	// deallocate removals..
	while (!removals_.empty()) {
		if (removals_.back()) {
			delete removals_.back();
			removals_.pop_back();
		}
	}

	removals_.clear();
}

void Context::restorePrefix()
{
	for (unsigned i = 0; i < removals_.size(); i++) {
		if (removals_.at(i)->getAffixType() == "DP") {
			setCurrentWord(removals_.at(i)->getSubject());
			break;
		}
	}
}