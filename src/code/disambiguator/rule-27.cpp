#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-27.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule27::Rule27()
{
}

Rule27::~Rule27()
{
}

bool Rule27::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^pen([cdjstz])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = m0 + m1;

	return true;
}