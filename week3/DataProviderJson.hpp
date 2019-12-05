#ifndef _DATA_PROVIDER_HPP
#define _DATA_PROVIDER_HPP

#include<jsoncpp/json/json.h>

class DataProviderJson {
  private:
    std::string filePath;
    Json::Value data;
  public:
    DataProviderJson(const std::string & filePath);
    Json::Value readAndParseData();
    void writeData(Json::Value & data);
};

#endif
