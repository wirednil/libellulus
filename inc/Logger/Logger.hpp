#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

typedef enum{ DEBUG, INFO, WARNING, ERROR, FATAL} Level;

class Logger
{
public:

    Logger(std::ostream& outStream, Level minLevel) :
        outStream_(outStream),
        minLevel_(minLevel)
    {}

    void log(Level level, const std::string& message, const char* file, const char* function, int line);
    void setMinLevel(Level minLevel);

private:
    std::ostream& outStream_;
    Level minLevel_;
    std::string levelToString(Level level);
};