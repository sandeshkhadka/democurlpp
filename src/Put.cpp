#include "curlpp/Easy.hpp"
#include "curlpp/Exception.hpp"
#include "curlpp/Options.hpp"
#include "curlpp/cURLpp.hpp"
#include "json.hpp"
#include <iostream>
#include <sstream>
#include <string>
int main() {

  try {
    std::string url = "https://fakestoreapi.com/products/7";
    curlpp::Cleanup cleaner;
    curlpp::Easy handler;
    nlohmann::json update_data;
    std::list<std::string> headers = {"Content-Type: application/json"};
    std::stringstream response;

    update_data["title"] = "new title";
    update_data["price"] = 13.5;
    update_data["description"] = "New description";
    update_data["image"] = "https://i.pravatar.cc";
    update_data["category"] = "electronic";

    handler.setOpt(new curlpp::options::Url(url));
    handler.setOpt(new curlpp::options::HttpHeader(headers));
    handler.setOpt(new curlpp::options::CustomRequest("PUT"));
    handler.setOpt(new curlpp::options::Put(true));
    handler.setOpt(new curlpp::options::PostFields(update_data.dump()));
    handler.setOpt(
        new curlpp::options::PostFieldSize(update_data.dump().size()));
    handler.setOpt(new curlpp::options::WriteStream(&response));
    handler.perform();

    nlohmann::json responeJson = nlohmann::json::parse(response);
    std::cout << std::setw(2) << responeJson << std::endl;

  } catch (curlpp::RuntimeError &e) {

    std::cout << "Runtime Error: " << e.what();
  } catch (curlpp::LogicError &e) {
    std::cout << "Runtime Error: " << e.what();
  }
}
