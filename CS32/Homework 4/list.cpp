void listAll(string path, const File* f)  // two-parameter overload
{
	//Want to go as deep as possible, print everything out then go back out, print everything etc.
	//Nullptr means a plainfile.

	//Base case (have reached a plainfile)
	if (f->files() == nullptr) {
		path = path +  "/" + f->name();
		cout << path << endl;
		return;
	}

	//Recursive case have a directory 
	else {
		path = path + "/" + f->name();
		cout << path << endl;
		for (int i = 0; i < f->files()->size(); i++) {
			listAll(path, f->files()->at(i));
		}
	}

	//This is a void function don't have to worry about returning anything.

}