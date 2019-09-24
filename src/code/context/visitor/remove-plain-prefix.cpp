#include <string>
#include <pcrecpp.h>
#include <stemmer/context/visitor/remove-plain-prefix.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer;
using namespace stemmer::context;
using namespace stemmer::context::visitor;

RemovePlainPrefix::RemovePlainPrefix()
{
}

RemovePlainPrefix::~RemovePlainPrefix()
{
}

void RemovePlainPrefix::visit(ContextAbstract& ctx_)
{
	string res_ = remove(ctx_.getCurrentWord());
	string rp_;

	if (res_ != ctx_.getCurrentWord()) {
		rp_ = ctx_.getCurrentWord();

		RE(res_).Replace(string(""), &rp_);

		ctx_.constructRemoval(ctx_.getCurrentWord(), res_, rp_, string("DP"));
		ctx_.setCurrentWord(res_);
	}
}

std::string RemovePlainPrefix::remove(std::string buf_)
{
	string rbuf_ = buf_;

	RE("^(di|ke|se)").Replace(string(""), &rbuf_);

	return rbuf_;
}