#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-41.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule41::Rule41()
{
}

Rule41::~Rule41()
{
}

bool Rule41::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^ku(.*)$");
	string m0;

	if (!reg_.FullMatch(buf_, &m0))
		return false;

	rbuf_ = m0;

	return true;
}