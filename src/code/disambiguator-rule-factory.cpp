#include <map>
#include <vector>
#include <stemmer/disambiguator-rule-factory.hpp>
#include <stemmer/disambiguator-rule-collect.hpp>
#include <stemmer/util-macro.hpp>

using namespace std;
using namespace stemmer;
using namespace stemmer::disambiguator;

DisambiguatorRuleFactory::DisambiguatorRuleFactory()
{
	initRules();
}

DisambiguatorRuleFactory::~DisambiguatorRuleFactory()
{
	destroyRules();
}

void DisambiguatorRuleFactory::initRules()
{
	// 1a, 1b
	cont_.insert(
		make_pair(
			string("rule-1"),
			vector<DisambiguatorAbstract *>{ new Rule1a(), new Rule1b() }
		)
	);

	// 2
	cont_.insert(
		make_pair(
			string("rule-2"),
			vector<DisambiguatorAbstract *>{ new Rule2() }
		)
	);

	// 3
	cont_.insert(
		make_pair(
			string("rule-3"),
			vector<DisambiguatorAbstract *>{ new Rule3() }
		)
	);

	// 4
	cont_.insert(
		make_pair(
			string("rule-4"),
			vector<DisambiguatorAbstract *>{ new Rule4() }
		)
	);

	// 5
	cont_.insert(
		make_pair(
			string("rule-5"),
			vector<DisambiguatorAbstract *>{ new Rule5() }
		)
	);

	// 6a, 6b
	cont_.insert(
		make_pair(
			string("rule-6"),
			vector<DisambiguatorAbstract *>{ new Rule6a(), new Rule6b() }
		)
	);

	// 7
	cont_.insert(
		make_pair(
			string("rule-7"),
			vector<DisambiguatorAbstract *>{ new Rule7() }
		)
	);

	// 8
	cont_.insert(
		make_pair(
			string("rule-8"),
			vector<DisambiguatorAbstract *>{ new Rule8() }
		)
	);

	// 9
	cont_.insert(
		make_pair(
			string("rule-9"),
			vector<DisambiguatorAbstract *>{ new Rule9() }
		)
	);

	// 10
	cont_.insert(
		make_pair(
			string("rule-10"),
			vector<DisambiguatorAbstract *>{ new Rule10() }
		)
	);

	// 11
	cont_.insert(
		make_pair(
			string("rule-11"),
			vector<DisambiguatorAbstract *>{ new Rule11() }
		)
	);

	// 12
	cont_.insert(
		make_pair(
			string("rule-12"),
			vector<DisambiguatorAbstract *>{ new Rule12() }
		)
	);

	// 13a, 13b
	cont_.insert(
		make_pair(
			string("rule-13"),
			vector<DisambiguatorAbstract *>{ new Rule13a(), new Rule13b() }
		)
	);

	// 14
	cont_.insert(
		make_pair(
			string("rule-14"),
			vector<DisambiguatorAbstract *>{ new Rule14() }
		)
	);

	// 15
	cont_.insert(
		make_pair(
			string("rule-15"),
			vector<DisambiguatorAbstract *>{ new Rule15a(), new Rule15b() }
		)
	);

	// 16
	cont_.insert(
		make_pair(
			string("rule-16"),
			vector<DisambiguatorAbstract *>{ new Rule16() }
		)
	);

	// 17
	cont_.insert(
		make_pair(
			string("rule-17"),
			vector<DisambiguatorAbstract *>{ new Rule17a(), new Rule17b(), new Rule17c(), new Rule17d() }
		)
	);

	// 18
	cont_.insert(
		make_pair(
			string("rule-18"),
			vector<DisambiguatorAbstract *>{ new Rule18a(), new Rule18b() }
		)
	);

	// 19
	cont_.insert(
		make_pair(
			string("rule-19"),
			vector<DisambiguatorAbstract *>{ new Rule19() }
		)
	);

	// 20
	cont_.insert(
		make_pair(
			string("rule-20"),
			vector<DisambiguatorAbstract *>{ new Rule20() }
		)
	);

	// 21a, 21b
	cont_.insert(
		make_pair(
			string("rule-21"),
			vector<DisambiguatorAbstract *>{ new Rule21a(), new Rule21b() }
		)
	);

	// 23
	cont_.insert(
		make_pair(
			string("rule-23"),
			vector<DisambiguatorAbstract *>{ new Rule23() }
		)
	);

	// 24
	cont_.insert(
		make_pair(
			string("rule-24"),
			vector<DisambiguatorAbstract *>{ new Rule24() }
		)
	);

	// 25
	cont_.insert(
		make_pair(
			string("rule-25"),
			vector<DisambiguatorAbstract *>{ new Rule25() }
		)
	);

	// 26a, 26b
	cont_.insert(
		make_pair(
			string("rule-26"),
			vector<DisambiguatorAbstract *>{ new Rule26a(), new Rule26b() }
		)
	);

	// 27
	cont_.insert(
		make_pair(
			string("rule-27"),
			vector<DisambiguatorAbstract *>{ new Rule27() }
		)
	);

	// 28a, 28b
	cont_.insert(
		make_pair(
			string("rule-28"),
			vector<DisambiguatorAbstract *>{ new Rule28a(), new Rule28b() }
		)
	);

	// 29
	cont_.insert(
		make_pair(
			string("rule-29"),
			vector<DisambiguatorAbstract *>{ new Rule29() }
		)
	);

	// 30a, 30b, 30c
	cont_.insert(
		make_pair(
			string("rule-30"),
			vector<DisambiguatorAbstract *>{ new Rule30a(), new Rule30b(), new Rule30c() }
		)
	);

	// 31a, 31b
	cont_.insert(
		make_pair(
			string("rule-31"),
			vector<DisambiguatorAbstract *>{ new Rule31a(), new Rule31b() }
		)
	);

	// 32
	cont_.insert(
		make_pair(
			string("rule-32"),
			vector<DisambiguatorAbstract *>{ new Rule32() }
		)
	);

	// 34
	cont_.insert(
		make_pair(
			string("rule-34"),
			vector<DisambiguatorAbstract *>{ new Rule34() }
		)
	);

	// 35
	cont_.insert(
		make_pair(
			string("rule-35"),
			vector<DisambiguatorAbstract *>{ new Rule35() }
		)
	);

	// 36
	cont_.insert(
		make_pair(
			string("rule-36"),
			vector<DisambiguatorAbstract *>{ new Rule36() }
		)
	);

	// 37a, 37b
	cont_.insert(
		make_pair(
			string("rule-37"),
			vector<DisambiguatorAbstract *>{ new Rule37a(), new Rule37b() }
		)
	);

	// 38a, 38b
	cont_.insert(
		make_pair(
			string("rule-38"),
			vector<DisambiguatorAbstract *>{ new Rule38a(), new Rule38b() }
		)
	);

	// 39a, 39b
	cont_.insert(
		make_pair(
			string("rule-39"),
			vector<DisambiguatorAbstract *>{ new Rule39a(), new Rule39b() }
		)
	);

	// 40a, 40b
	cont_.insert(
		make_pair(
			string("rule-40"),
			vector<DisambiguatorAbstract *>{ new Rule40a(), new Rule40b() }
		)
	);

	// 41
	cont_.insert(
		make_pair(
			string("rule-41"),
			vector<DisambiguatorAbstract *>{ new Rule41() }
		)
	);

	// 42
	cont_.insert(
		make_pair(
			string("rule-42"),
			vector<DisambiguatorAbstract *>{ new Rule42() }
		)
	);
}

void DisambiguatorRuleFactory::destroyRules()
{
	for (auto& q: cont_) {
		for (unsigned i = 0; i < q.second.size(); i++)
			delete q.second.at(i);

		q.second.clear();
	}
}

vector<DisambiguatorAbstract *>& DisambiguatorRuleFactory::getDisambiguators(string key_)
{
	for (map<string, vector<DisambiguatorAbstract *>>::iterator iter_ = cont_.begin(); iter_ != cont_.end(); iter_++) {
		if (key_ == iter_->first)
			return iter_->second;
	}

	THROW_ERROR("Disambiguator rule vector with name: " << key_ << " doesn't exist.");
}