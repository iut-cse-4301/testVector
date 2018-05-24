#include<iostream>
#include<vector>
using namespace std;

class parent {
	int id;
public:
	parent(int id) {
		this->id = id;
	}
	virtual void printID() {
		cout << "I am Parent #" << id << endl;
	}

	int get_id() {
		return id;
	}
};
class child_A :public parent {
	int id;
public:
	child_A(int id, int idParent) :parent(idParent) {
		this->id = id;
	}
	void printID() {
		cout << "I am Child_A #" << id << ". Parent #" << get_id() << endl;
	}
};

class child_B :public parent {
	int id;
public:
	child_B(int id, int idParent) :parent(idParent) {
		this->id = id;
	}
	void printID() {
		cout << "I am Child_B #" << id << ". Parent #" << get_id() << endl;
	}
};

class collection_service {
	vector<parent*> parentCollection;
public:
	collection_service() {
		parent* p;
		p = new parent(1);
		this->parentCollection.push_back(p);
		p = new parent(2);
		this->parentCollection.push_back(p);

		p = new child_A(1,1);
		this->parentCollection.push_back(p);
		p = new child_A(2,1);
		this->parentCollection.push_back(p);
		p = new child_A(1, 2);
		this->parentCollection.push_back(p);
		p = new child_A(2, 2);
		this->parentCollection.push_back(p);

		p = new child_B(1, 1);
		this->parentCollection.push_back(p);
		p = new child_B(2, 1);
		this->parentCollection.push_back(p);
		p = new child_B(1, 2);
		this->parentCollection.push_back(p);
		p = new child_B(2, 2);
		this->parentCollection.push_back(p);
	}

	void printCollectionIDs() {
		for (int i = 0; i < this->parentCollection.size(); i++) {
			this->parentCollection[i]->printID();
		}
	}

	parent* getElementByIdx(int index) {
		if (index<0 || index>=this->parentCollection.size())
			return NULL;
		return this -> parentCollection[index];
	}

	bool removeElement(int index) {
		if (index<0 || index >= this->parentCollection.size())
			return false;
		vector<parent*>::iterator it = this->parentCollection.begin();
		it = it + index;
		cout << "ERASING: "; (*it)->printID();
		this->parentCollection.erase(it, it+1);
		return true;
	}

};


int main() {
	collection_service ob;
	ob.printCollectionIDs();
	int idx = 2;
	if (ob.getElementByIdx(idx) != NULL) {
		ob.getElementByIdx(idx)->printID();
	}
	ob.removeElement(idx + 1);
	
	cout << endl << endl << "AFTER ERASING:" << endl;
	ob.printCollectionIDs();
	getchar();
	return 0;
}