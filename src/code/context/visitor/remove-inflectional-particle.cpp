#include <string>
#include <pcrecpp.h>
#include <stemmer/context/visitor/remove-inflectional-particle.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer;
using namespace stemmer::context;
using namespace stemmer::context::visitor;

RemoveInflectionalParticle::RemoveInflectionalParticle()
{
}

RemoveInflectionalParticle::~RemoveInflectionalParticle()
{
}

void RemoveInflectionalParticle::visit(ContextAbstract& ctx_)
{
	string res_ = remove(ctx_.getCurrentWord());
	string rp_;

	if (res_ != ctx_.getCurrentWord()) {
		rp_ = ctx_.getCurrentWord();

		RE(res_).Replace(string(""), &rp_);
		
		ctx_.constructRemoval(ctx_.getCurrentWord(), res_, rp_, string("P"));
		ctx_.setCurrentWord(res_);
	}
}

string RemoveInflectionalParticle::remove(string buf_)
{
	string rbuf_ = buf_;

	RE("-*(lah|kah|tah|pun)$").Replace(string(""), &rbuf_);

	return rbuf_;
}