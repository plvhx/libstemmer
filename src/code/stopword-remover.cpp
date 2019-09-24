#include <stemmer/string-util.hpp>
#include <stemmer/stopword-remover.hpp>

using namespace std;
using namespace stemmer;

StopwordRemover::~StopwordRemover()
{
	delete dict_;
}

Dictionary *StopwordRemover::getDictionary()
{
	return dict_;		
}

string StopwordRemover::remove(string buf_)
{
	StringUtil util_;

	util_.trim(buf_);

	vector<string> vt_ = util_.split(string(" "), buf_);
	string res_ = "";

	for (unsigned i = 0; i < vt_.size(); i++) {
		if (!dict_->search(vt_.at(i)))
			res_ += vt_.at(i) + string(" ");
	}

	util_.rtrim(res_);

	return res_;
}