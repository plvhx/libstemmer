#include <algorithm>
#include <pcrecpp.h>
#include <stemmer/stemmer.hpp>
#include <stemmer/string-util.hpp>
#include <stemmer/context/context.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer;
using namespace stemmer::context;

string Stemmer::stem(string buf_)
{
	StringUtil util_;
	string norm_ = util_.normalize(buf_), tmp_;
	vector<string> wvec_ = util_.split(string(" "), norm_);
	
	string res_;

	for (unsigned i = 0; i < wvec_.size(); i++) {
		{ tmp_ = wvec_.at(i); util_.trim(tmp_); res_ += stemWord(tmp_) + string(" "); }
	}

	util_.rtrim(res_);

	return res_;
}

string Stemmer::stemWord(string buf_)
{
	string rbuf_;

	if (isPlural(buf_))
		stemPluralWord(buf_, rbuf_);
	else
		stemSingularWord(buf_, rbuf_);

	return rbuf_;
}

bool Stemmer::isPlural(string buf_)
{
	RE reg_("^(.*)\\-(ku|mu|nya|lah|kah|tah|pun)$", RE_Options(PCRE_CASELESS));
	string m0, m1;

	if (reg_.FullMatch(buf_, &m0, &m1))
		return (m0.find(string("-")) == string::npos ? false : true);

	return (buf_.find(string("-")) == string::npos ? false : true);
}

bool Stemmer::stemPluralWord(string buf_, string& rbuf_)
{
	string suffix_, rw1_, rw2_, param_, m0, m1;
	vector<string> vsuf_ = {
		string("ku"),
		string("mu"),
		string("nya"),
		string("lah"),
		string("kah"),
		string("tah"),
		string("pun")
	};

	if (!RE("^(.*)\\-(.*)$", RE_Options(PCRE_CASELESS)).FullMatch(buf_, &param_, &suffix_))
		return false;

	if ((find(begin(vsuf_), end(vsuf_), suffix_) != end(vsuf_)) && RE("^(.*)\\-(.*)$", RE_Options(PCRE_CASELESS)).FullMatch(param_, &m0, &m1)) {
		m1 += (string("-") + suffix_);
	}

	if (!m0.size() && !m1.size()) {
		m0 = param_; m1 = suffix_;
	}

	stemSingularWord(m0, rw1_);
	stemSingularWord(m1, rw2_);

	if (!da_->search(m1) && rw2_ == m1)
		stemSingularWord(string("me") + m1, rw2_);

	rbuf_ = (rw1_ == rw2_ ? rw1_ : buf_);

	return true;
}

bool Stemmer::stemSingularWord(string buf_, string& rbuf_)
{
	Context *ctx_ = new Context(buf_, da_, prov_);
	ctx_->execute();

	rbuf_ = ctx_->getResult();

	delete ctx_;

	return true;
}