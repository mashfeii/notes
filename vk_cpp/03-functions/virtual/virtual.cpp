#include <cstring>
#include <iostream>
#include <string>

class BaseLog {
 public:
  virtual void log() { std::cout << "BaseLog::log" << std::endl; }
  static std::string name() { return std::string{"base_logger"}; }
};

class ConsoleLog : public BaseLog {
 public:
  void log() override { std::cout << "ConsoleLog::log" << std::endl; }
};

class PrinterLog : public BaseLog {
 public:
  void log() override { std::cout << "PrinterLog::log" << std::endl; }
};

void write_to_log(BaseLog* log) {
  log->log();
}

int main(int argc, char* argv[]) {
  BaseLog* log = nullptr;

  if (strcmp(argv[1], "console") == 0) {
    log = new ConsoleLog();
  } else if (strcmp(argv[1], "printer") == 0) {
    log = new PrinterLog();
  }

  write_to_log(log);

  delete log;
}
