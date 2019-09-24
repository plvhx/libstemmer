#include <string>
#include <pcrecpp.h>
#include <stemmer/context/visitor/remove-derivational-suffix.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer;
using namespace stemmer::context;
using namespace stemmer::context::visitor;

RemoveDerivationalSuffix::RemoveDerivationalSuffix()
{
}

RemoveDerivationalSuffix::~RemoveDerivationalSuffix()
{
}

void RemoveDerivationalSuffix::visit(ContextAbstract& ctx_)
{
	string result_ = removeSuffix(ctx_.getCurrentWord());
	string rp_;

	if (result_ != ctx_.getCurrentWord()) {
		rp_ = ctx_.getCurrentWord();

		RE(result_).Replace(string(""), &rp_);

		ctx_.constructRemoval(ctx_.getCurrentWord(), result_, rp_, string("DS"));
		ctx_.setCurrentWord(result_);
	}
}

string RemoveDerivationalSuffix::removeSuffix(string buf_)
{
	string rbuf_ = buf_;

	RE("(is|isme|isasi|i|kan|an)$").Replace(string(""), &rbuf_);

	return rbuf_;
}