#include <vector>
#include <stemmer/dictionary.hpp>
#include <stemmer/hash.hpp>
#include <stemmer/stopword-remover-factory.hpp>

using namespace std;
using namespace stemmer;

StopwordRemoverFactory::StopwordRemoverFactory()
{
	dict_ = new Dictionary();
	dict_->make(getStopWords());
	sr_ = new StopwordRemover(dict_);
}

StopwordRemoverFactory::~StopwordRemoverFactory()
{
	delete sr_;
}

StopwordRemover *StopwordRemoverFactory::create()
{
	return sr_;
}

map<uint32_t, string> StopwordRemoverFactory::getStopWords()
{
	Hash ho_;
	map<uint32_t, string> umap_;
	vector<string> sw_{
		   "yang",      "untuk",    "pada",        "ke",         "para",    "namun",    "menurut",     "antara",
		    "dia",        "dua",      "ia",   "seperti",         "jika", "sehingga",    "kembali",        "dan",
		  "tidak",        "ini",  "karena",    "kepada",         "oleh",     "saat",      "harus",  "sementara",
		"setelah",      "belum",    "kami",   "sekitar",         "bagi",    "serta",         "di",       "dari",
		  "telah",    "sebagai",   "masih",       "hal",       "ketika",   "adalah",        "itu",      "dalam",
		   "bisa",      "bahwa",    "atau",     "hanya",         "kita",   "dengan",       "akan",       "juga",
		    "ada",     "mereka",   "sudah",      "saya",     "terhadap",   "secara",       "agar",       "lain",
		   "anda",     "begitu", "mengapa",    "kenapa",        "yaitu",    "yakni",   "daripada",     "itulah",
		   "lagi",       "maka", "tentang",      "demi",       "dimana",   "kemana",       "pula",     "sambil",
		"sebelum",    "sesudah",  "supaya",      "guna",          "kah",      "pun",     "sampai",  "sedangkan",
		 "selagi",  "sementara",  "tetapi",    "apakah",      "kecuali",    "sebab",     "selain",     "seolah",
		 "seraya", "seterusnya",   "tanpa",      "agak",        "boleh",    "dapat",        "dsb",        "dst",
		    "dll",     "dahulu", "dulunya",       "anu",     "demikian",     "tapi",      "ingin",       "juga",
		  "nggak",       "mari",   "nanti", "melainkan",           "oh",       "ok", "seharusnya", "sebetulnya",
		 "setiap", "setidaknya", "sesuatu",     "pasti",         "saja",      "toh",         "ya",      "walau",
		 "tolong",      "tentu",    "amat",   "apalagi", "bagaimanapun"
	};

	for (unsigned i = 0; i < sw_.size(); i++) {
		umap_.insert(make_pair(ho_.generate(sw_.at(i), DICT_CONST_HASH), sw_.at(i)));
	}

	return umap_;
}