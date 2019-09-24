#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include <stemmer/dictionary.hpp>
#include <stemmer/stemmer.hpp>
#include <stemmer/context/visitor/visitor-provider.hpp>

using namespace std;
using namespace testing;
using namespace stemmer;
using namespace stemmer::context::visitor;

static vector<string> preservedDictionaryWords_{
	     "hancur",   "benar",     "apa",   "siapa",    "jubah",     "baju",    "beli",
         "celana",   "hantu",    "jual",    "buku",    "milik",    "kulit",   "sakit",
          "kasih",   "buang",    "suap",   "nilai",     "beri",   "rambut",     "adu",
          "suara",  "daerah",    "ajar",   "kerja",   "ternak",    "asing",    "raup",
          "gerak",   "puruk", "terbang",   "lipat",  "ringkas",    "warna",   "yakin",
         "bangun",  "fitnah",   "vonis",    "baru",     "ajar",  "tangkap",   "kupas",
          "minum",   "pukul",   "cinta",     "dua",   "dahulu",     "jauh",   "jarah",
         "ziarah",  "nuklir", "nasihat",    "gila",    "hajar",    "qasar",   "udara",
        "populer",   "warna",    "yoga",    "adil",    "rumah",     "muka",   "labuh",
         "tarung",   "tebar",   "indah",    "daya",   "untung",  "sepuluh", "ekonomi",
         "makmur",   "telah",   "serta", "percaya", "pengaruh",   "kritik",    "seko",
        "sekolah",   "tahan",    "capa",   "capai",     "mula",    "mulai",   "petan",
           "tani",     "aba",    "abai",   "balas",    "balik",    "peran",   "medan",
         "syukur",  "syarat",     "bom", "promosi", "proteksi", "prediksi",    "kaji",
       "sembunyi", "langgan",    "laku",    "baik",   "terang",     "iman",   "bisik",
           "taat",    "puas",   "makan",   "nyala",   "nyanyi",    "nyata",   "nyawa",
           "rata",  "lembut",   "ligas",  "budaya",    "karya",    "ideal",   "final",
           "taat",    "tiru",   "sepak",   "kuasa", "malaikat",   "nikmat",  "stabil",
    "transkripsi",   "lewat",  "nganga",   "allah"
};

class ParameterizedStemmerFixture : public ::Test
{
protected:
	Dictionary *dict_;
	VisitorProvider *prov_;
	Stemmer *stem_;

	void setUp()
	{
		dict_ = new Dictionary();
		addWordsIntoDictionary();
		prov_ = new VisitorProvider();
		stem_ = new Stemmer(dict_, prov_);
	}

	void tearDown()
	{
		delete stem_;
		delete prov_;
		delete dict_;
	}

	Dictionary *getDictionary()
	{
		return dict_;
	}

	VisitorProvider *getVisitorProvider()
	{
		return prov_;
	}

	Stemmer *getStemmer()
	{
		return stem_;
	}

private:
	void addWordsIntoDictionary()
	{
		for (unsigned i = 0; i < preservedDictionaryWords_.size(); i++)
			dict_->add(preservedDictionaryWords_.at(i));
	}
};

class ParameterizedStemmerTest : public ParameterizedStemmerFixture, public ::WithParamInterface<vector<string>>
{
public:
	static vector<vector<string>> twords_;

protected:
	vector<string> tword_;

	void SetUp() override {
		ParameterizedStemmerFixture::setUp();
		tword_ = GetParam();
	}

	void TearDown() override {
		ParameterizedStemmerFixture::tearDown();
	}
};

vector<vector<string>> ParameterizedStemmerTest::twords_{
	// don"t stem short words
	vector<string>{"mei", "mei"},
	vector<string>{"bui", "bui"},

	// lookup the dictionary, to prevent overstemming
	vector<string>{"nilai", "nilai"},

	// lah|tah|kah|pun
	vector<string>{"hancurlah", "hancur"},
	vector<string>{"benarkah", "benar"},
	vector<string>{"apatah", "apa"},
	vector<string>{"siapapun", "siapa"},

	// ku|mu|nya
	vector<string>{"jubahku", "jubah"},
	vector<string>{"bajumu", "baju"},
	vector<string>{"celananya", "celana"},

	// i|kan|an
	vector<string>{"hantui", "hantu"},
	vector<string>{"belikan", "beli"},
	vector<string>{"jualan", "jual"},

	// combination of suffixes
	vector<string>{"bukumukah", "buku"},
	vector<string>{"miliknyalah", "milik"},
	vector<string>{"kulitkupun", "kulit"},
	vector<string>{"berikanku", "beri"},
	vector<string>{"sakitimu", "sakit"},
	vector<string>{"beriannya", "beri"},
	vector<string>{"kasihilah", "kasih"},

	// plain prefix
	vector<string>{"dibuang", "buang"},
	vector<string>{"kesakitan", "sakit"},
	vector<string>{"sesuap", "suap"},

	// 1a
	vector<string>{"beradu", "adu"},

	// 1b
	vector<string>{"berambut", "rambut"},

	// 2
	vector<string>{"bersuara", "suara"},

	// 3
	vector<string>{"berdaerah", "daerah"},

	// 4
	vector<string>{"belajar", "ajar"},

	// 5
	vector<string>{"bekerja", "kerja"},
	vector<string>{"beternak", "ternak"},

	// 6a
	vector<string>{"terasing", "asing"},

	// 6b
	vector<string>{"teraup", "raup"},

	// 7
	vector<string>{"tergerak", "gerak"},

	// 8
	vector<string>{"terpuruk", "puruk"},

	// 9
	vector<string>{"teterbang", "terbang"},

	// 10
	vector<string>{"melipat", "lipat"},
	vector<string>{"meringkas", "ringkas"},
	vector<string>{"mewarnai", "warna"},
	vector<string>{"meyakinkan", "yakin"},

	// 11
	vector<string>{"membangun", "bangun"},
	vector<string>{"memfitnah", "fitnah"},
	vector<string>{"memvonis", "vonis"},

	// 12
	vector<string>{"memperbarui", "baru"},
	vector<string>{"mempelajari", "ajar"},

	// 13a
	vector<string>{"meminum", "minum"},

	// 13b
	vector<string>{"memukul", "pukul"},

	// 14
	vector<string>{"mencinta", "cinta"},
	vector<string>{"mendua", "dua"},
	vector<string>{"menjauh", "jauh"},
	vector<string>{"menziarah", "ziarah"},

	// 15a
	vector<string>{"menuklir", "nuklir"},

	// 15b
	vector<string>{"menangkap", "tangkap"},

	// 16
	vector<string>{"menggila", "gila"},
	vector<string>{"menghajar", "hajar"},
	vector<string>{"mengqasar", "qasar"},

	// 17a
	vector<string>{"mengudara", "udara"},

	// 17b
	vector<string>{"mengupas", "kupas"},

	// 18
	vector<string>{"menyuarakan", "suara"},

	// 19
	vector<string>{"mempopulerkan", "populer"},

	// 20
	vector<string>{"pewarna", "warna"},
	vector<string>{"peyoga", "yoga"},

	// 21a
	vector<string>{"peradilan", "adil"},

	// 21b
	vector<string>{"perumahan", "rumah"},

	// 23
	vector<string>{"permuka", "muka"},

	// 24
	vector<string>{"perdaerah", "daerah"},

	// 25
	vector<string>{"pembangun", "bangun"},
	vector<string>{"pemfitnah", "fitnah"},
	vector<string>{"pemvonis", "vonis"},

	// 26a
	vector<string>{"peminum", "minum"},

	// 26b
	vector<string>{"pemukul", "pukul"},

	// 27
	vector<string>{"pencinta", "cinta"},
	vector<string>{"pendahulu", "dahulu"},
	vector<string>{"penjarah", "jarah"},
	vector<string>{"penziarah", "ziarah"},

	// 28a
	vector<string>{"penasihat", "nasihat"},

	// 28b
	vector<string>{"penangkap", "tangkap"},

	// 29
	vector<string>{"penggila", "gila"},
	vector<string>{"penghajar", "hajar"},
	vector<string>{"pengqasar", "qasar"},

	// 30a
	vector<string>{"pengudara", "udara"},

	// 30b
	vector<string>{"pengupas", "kupas"},

	// 31
	vector<string>{"penyuara", "suara"},

	// 32
	vector<string>{"pelajar", "ajar"},
	vector<string>{"pelabuhan", "labuh"},

	// 34
	vector<string>{"petarung", "tarung"},

	// 35
	vector<string>{"terpercaya", "percaya"},

	// 36
	vector<string>{"pekerja", "kerja"},
	vector<string>{"peserta", "serta"},

	// modify rule 12
	vector<string>{"mempengaruhi", "pengaruh"},

	// modify rule 16
	vector<string>{"mengkritik", "kritik"},

	// adjusting rule precedence
	vector<string>{"bersekolah", "sekolah"},
	vector<string>{"bertahan", "tahan"},
	vector<string>{"mencapai", "capai"},
	vector<string>{"dimulai", "mulai"},
	vector<string>{"petani", "tani"},
	vector<string>{"terabai", "abai"},

	// ECS
	vector<string>{"mensyaratkan", "syarat"},
	vector<string>{"mensyukuri", "syukur"},
	vector<string>{"mengebom", "bom"},
	vector<string>{"mempromosikan", "promosi"},
	vector<string>{"memproteksi", "proteksi"},
	vector<string>{"memprediksi", "prediksi"},
	vector<string>{"pengkajian", "kaji"},
	vector<string>{"pengebom", "bom"},

	// ECS return all suffix
	vector<string>{"bersembunyi", "sembunyi"},
	vector<string>{"bersembunyilah", "sembunyi"},
	vector<string>{"pelanggan", "langgan"},
	vector<string>{"pelaku", "laku"},
	vector<string>{"pelangganmukah", "langgan"},
	vector<string>{"pelakunyalah", "laku"},
	vector<string>{"perbaikan", "baik"},
	vector<string>{"kebaikannya", "baik"},
	vector<string>{"bisikan", "bisik"},
	vector<string>{"menerangi", "terang"},
	vector<string>{"berimanlah", "iman"},
	vector<string>{"memuaskan", "puas"},
	vector<string>{"berpelanggan", "langgan"},
	vector<string>{"bermakanan", "makan"},

	// CC (modified ECS)
	vector<string>{"menyala", "nyala"},
	vector<string>{"menyanyikan", "nyanyi"},
	vector<string>{"menyatakannya", "nyata"},
	vector<string>{"penyanyi", "nyanyi"},
	vector<string>{"penyawaan", "nyawa"},

	// CC infix
	vector<string>{"rerata", "rata"},
	vector<string>{"lelembut", "lembut"},
	vector<string>{"lemigas", "ligas"},
	vector<string>{"kinerja", "kerja"},

	// plurals
	vector<string>{"buku-buku", "buku"},
	vector<string>{"berbalas-balasan", "balas"},
	vector<string>{"bolak-balik", "bolak-balik"},

	// combination of prefix + suffix
	vector<string>{"bertebaran", "tebar"},
	vector<string>{"terasingkan", "asing"},
	vector<string>{"membangunkan", "bangun"},
	vector<string>{"mencintai", "cinta"},
	vector<string>{"menduakan", "dua"},
	vector<string>{"menjauhi", "jauh"},
	vector<string>{"menggilai", "gila"},
	vector<string>{"pembangunan", "bangun"},

	// return the word if not found in the dictionary
	vector<string>{"marwan", "marwan"},
	vector<string>{"subarkah", "subarkah"},

	// recursively remove prefix
	vector<string>{"memberdayakan", "daya"},
	vector<string>{"persemakmuran", "makmur"},
	vector<string>{"keberuntunganmu", "untung"},
	vector<string>{"kesepersepuluhnya", "sepuluh"},

	// test stem sentence
	vector<string>{"siapakah memberdayakan pembangunan", "siapa daya bangun"},

	// issues
	vector<string>{"Perekonomian", "ekonomi"},
	vector<string>{"menahan", "tahan"},

	// test stem multiple sentences
	vector<string>{"Cinta telah bertebaran.Keduanya saling mencintai.", "cinta telah tebar dua saling cinta"},
	vector<string>{"(Cinta telah bertebaran)\n\n\n\nKeduanya saling mencintai.", "cinta telah tebar dua saling cinta"},

	// failed on other method / algorithm but we should succeed
	vector<string>{"peranan", "peran"},
	vector<string>{"memberikan", "beri"},
	vector<string>{"medannya", "medan"},

	// adopted foreign suffixes
	vector<string>{"idealis", "ideal"},
	vector<string>{"idealisme", "ideal"},
	vector<string>{"finalisasi", "final"},

	// sastrawi additional rules
	vector<string>{"penstabilan", "stabil"},
	vector<string>{"pentranskripsi", "transkripsi"},
	vector<string>{"mentaati", "taat"},
	vector<string>{"meniru-nirukan", "tiru"},
	vector<string>{"menyepak-nyepak", "sepak"},
	vector<string>{"melewati", "lewat"},
	vector<string>{"menganga", "nganga"},
	vector<string>{"kupukul", "pukul"},
	vector<string>{"kauhajar", "hajar"},
	vector<string>{"kuasa-Mu", "kuasa"},
	vector<string>{"malaikat-malaikat-Nya", "malaikat"},
	vector<string>{"nikmat-Ku", "nikmat"},
	vector<string>{"allah-lah", "allah"}
};

TEST_P(ParameterizedStemmerTest, Equality)
{
	ASSERT_EQ(tword_[1], getStemmer()->stem(tword_[0]));
}

INSTANTIATE_TEST_CASE_P(
	ParameterizedStemmerTestExecutor,
	ParameterizedStemmerTest,
	ValuesIn(ParameterizedStemmerTest::twords_)
);

int main(int argc, char **argv)
{
	::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}