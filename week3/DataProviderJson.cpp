#include "DataProviderJson.hpp"

#include "jsoncpp/json/json.h"
#include <fstream>
#include <iostream>
#include <exception>

DataProviderJson::DataProviderJson(const std::string & filePath):
  filePath{filePath},
  data{new Json::Value}
{ }

struct FileNotFound : public std::exception {
  const char * what() const throw() {
    return "File not found exception";
  }
};


Json::Value DataProviderJson::readAndParseData() {
  try {
    std::ifstream stream(filePath);
    if(stream.fail()) {
      throw FileNotFound();
    }
    Json::Reader reader;
    reader.parse(stream, data);
    return data;
  } catch (FileNotFound & e) {
    std::cout << e.what() << std::endl;
    throw;
  } catch (Json::LogicError & e) {
    std::cout << e.what() << std::endl;
    throw;
  } catch (Json::RuntimeError & e) {
    std::cout << e.what() << std::endl;
    throw;
  } catch (std::ifstream::failure & e) {
    std::cout << e.what() << std::endl;
    throw;
  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
    throw;
  }
}

void DataProviderJson::writeData(Json::Value & data) {
  std::ofstream file;
  file.open(filePath);
  Json::StyledWriter writer;
  file << writer.write(data);
  file.close();
}
