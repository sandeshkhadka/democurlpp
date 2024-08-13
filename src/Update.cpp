#include "curlpp/Easy.hpp"
#include "curlpp/Exception.hpp"
#include "curlpp/Options.hpp"
#include "curlpp/cURLpp.hpp"
#include "json.hpp"
#include <iostream>
#include <list>
#include <sstream>
#include <string>
int main() {
  try {
    curlpp::Cleanup clearner;
    curlpp::Easy handler;
    std::string url = "https://fakestoreapi.com/products/7";
    std::list<std::string> headers = {"Content-Type: application/json"};
    nlohmann::json data;
    data["title"] = "UPATED TITLE";
    data["price"] = 13.5;
    data["description"] = "UPATED DESC";
    data["image"] = "https//i.pravatar.cc";
    data["category"] = "electronic";

    std::stringstream response;
    handler.setOpt(new curlpp::options::Url(url));
    handler.setOpt(new curlpp::options::HttpHeader(headers));
    handler.setOpt(new curlpp::options::CustomRequest("PATCH"));
    handler.setOpt(new curlpp::options::PostFields(data.dump()));
    handler.setOpt(new curlpp::options::PostFieldSize(data.dump().size()));
    handler.setOpt(new curlpp::options::WriteStream(&response));

    handler.perform();
    nlohmann::json responeJson = nlohmann::json::parse(response);
    std::cout << std::setw(2) << responeJson << std::endl;
  } catch (curlpp::LogicError &e) {
    std::cout << "Logic Error: " << e.what();
  } catch (curlpp::RuntimeError &e) {
    std::cout << "Runtime Error: " << e.what();
  }
}
