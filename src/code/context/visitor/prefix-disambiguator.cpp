#include <string>
#include <pcrecpp.h>
#include <stemmer/context/visitor/prefix-disambiguator.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer;
using namespace stemmer::context;
using namespace stemmer::context::visitor;

void PrefixDisambiguator::visit(ContextAbstract& ctx_)
{
	string res_, rp_;

	for (unsigned i = 0; i < da_.size(); i++) {
		if (da_.at(i)->disambiguate(ctx_.getCurrentWord(), res_)) {
			if (ctx_.getDictionary()->search(res_)) {
				break;
			}
		}
	}

	if (!res_.empty()) {
		rp_ = ctx_.getCurrentWord();
		RE(res_).Replace(string(""), &rp_);

		ctx_.constructRemoval(ctx_.getCurrentWord(), res_, rp_, string("DP"));
		ctx_.setCurrentWord(res_);
	}
}