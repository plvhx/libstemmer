#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-32.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule32::Rule32()
{
}

Rule32::~Rule32()
{
}

bool Rule32::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^pe(l[aiueo])(.*)$");
	string m0, m1;

	if (buf_ == "pelajar") {
		rbuf_ = "ajar";
		goto fin;
	}

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = m0 + m1;

fin:
	return true;
}