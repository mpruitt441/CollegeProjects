#include<iostream>
#include <string>
#include "Tree.cpp"
#include <filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;
// Mahendra Pruitt
// This will ONLY work to find depth of 2.
// The program starts from directory C:\Test

int main()
{
	Tree<string> dir;
	Tree<string>::Position p = dir.root();
	string dirt = "C:\\Test"; // starting directory
	dir.insert(dirt,p);
	p = dir.root();
	// iterate through directory and output the name
	// not very experienced with the for loop when it's set up this way. this was the only way 
	// i could iterate through the directory from what i found online
	for (auto & it : fs::directory_iterator(dirt)) {
		string fileName = it.path().string(); // string variable to hold path
		cout << fileName << endl; // output path
		dir.insert(fileName, p); // insert into the tree
		if (is_directory(it)) { // returns a bool to see if this is a folder or not
			string tempname = fileName; // temporary file name
			for (auto & iter : fs::directory_iterator(it.path())) { //recursive through the directory
				tempname = iter.path().string(); // assign new string name to tempname
					for (Tree<string>::PositionList::Iterator iterator = p.children().begin();
						iterator != p.children().end(); ++iterator) { // professor's iterator for loop
						Tree<string>::Position pos = *iterator; // new position thingy
						if (**iterator == fileName) {
							pos = *iterator; // assign the position to the iterator
							cout << *pos << "\t" << tempname << endl; // show child and parent directories
							dir.insert(tempname, pos); // insert the file name
						}
					}
			}
		}
		p = dir.root(); // set the position to the root of the tree
	}

	cout << "______TREE_____" << endl;

	Tree<string>::PositionList list = dir.Positions();
	for (Tree<string>::PositionList::Iterator i = list.begin(); i != list.end(); ++i)
		cout << **i << endl;
		
	system("PAUSE");
	// actually surprised if it works
	return 0;
}
