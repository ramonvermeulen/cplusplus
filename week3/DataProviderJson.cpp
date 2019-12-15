#include "DataProviderJson.hpp"

#include "jsoncpp/json/json.h"
#include "fstream"
#include "iostream"


DataProviderJson::DataProviderJson(const std::string & filePath):
  filePath{filePath},
  data{new Json::Value}
{ }

Json::Value DataProviderJson::readAndParseData() {
  try {
    std::ifstream stream(filePath);
    Json::Reader reader;
    reader.parse(stream, data);
    return data;
  } catch (Json::LogicError & e) {
    throw e;
  } catch (Json::RuntimeError & e) {
    throw e;
  } catch (std::ifstream::failure & e) {
    std::cout << "An Exception throwed during reading your json file" << std::endl;
    throw e;
  } catch (std::exception & e) {
    /* Implement error handling for different specific type of errors */
    std::cout << "Some other kind of Exception throwed in the DataProviderJson::read_and_parse_data() method" << std::endl;
    throw e;
  }
};
