/*
 * Tesseract binaries need to be installed
 */

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

using namespace std;

std::string exec(const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}

std::string exec(std::string cmdString) {
	const char* cmd = cmdString.c_str();
	return exec(cmd);
}


/*int main() {
	cout << "Tesseract Command Line Test" << endl;

	exec("tesseract test.png test -l eng");

	system("pause");
	return 0;
}*/
