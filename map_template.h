
#include <iostream>
using namespace std;

class Memoryfault {};

template <typename ID, class E> class map_template {
  public:
	ID* key;
	E* value;
	int size;

  public:
	map_template() : key(), value() { size = 0; }
	map_template(const map_template<ID, E>& l) {

		size = l.size;
		try {
			key = new ID[size];
			value = new E[size];
		} catch (...) {
			throw Memoryfault();
		}
		for (int i = 0; i < size; i++) {
			key[i] = l.key[i];
			value[i] = l.value[i];
		}
	}

	map_template& operator=(const map_template<ID, E>& l) {

		if (&l == this)
			return *this;
		size = l.size;
		ID* k;
		E* v;
		try {

			k = new ID[size];
			v = new E[size];
		} catch (...) {
			throw Memoryfault();
		}

		for (int i = 0; i < size; i++) {
			k[i] = l.key[i];
			v[i] = l.value[i];
		}
		delete[] key;
		key = k;
		delete[] value;
		value = v;

		return *this;
	}
	~map_template() {
		delete[] key;
		delete[] value;
	}

	friend ostream& operator<<(ostream& o, const map_template& v) {
		for (int i = 0; i < v.size; i++) {
			o << v.key[i] << " ";
			o << v.value[i];
		}
		return o;
	}

	E* Find(const ID v1) {
		for (int i = 0; i < size; i++) {
			if (key[i] == v1)
				return (value + i);
		}
		return NULL;
	}

	void Add(const ID& v1, const E& v2) {
		size++;
		ID* k;
		E* v;
		try {
			k = new ID[size];
			v = new E[size];
		} catch (...) {
			throw Memoryfault();
		}
		int i;
		for (i = 0; i < size - 1; i++) {
			k[i] = key[i];
			v[i] = value[i];
		}

		k[i] = v1;
		v[i] = v2;
		delete[] key;
		key = k;
		delete[] value;
		value = v;
	}
};
