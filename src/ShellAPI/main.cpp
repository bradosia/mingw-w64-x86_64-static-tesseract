/*
 * Tesseract binaries need to be installed
 */

#include <array>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using namespace std;

std::string exec(const char *cmd) {
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
  const char *cmd = cmdString.c_str();
  return exec(cmd);
}

int main() {
  std::chrono::duration<double, std::milli> processDuration;
  cout << "Tesseract Command Line Test" << endl;

  exec("export TESSDATA_PREFIX=share/tessdata/");
  auto processStart = std::chrono::steady_clock::now();
  exec("tesseract share/test.jpg test -l eng");
  auto processEnd = std::chrono::steady_clock::now();
  processDuration = processEnd - processStart;
  processDuration = std::chrono::duration<double, std::milli>(
      std::round(processDuration.count()));
  std::cout << "tesseract 4 processing time: " << (int)processDuration.count()
            << " milliseconds\n";

  system("pause");
  return 0;
}
