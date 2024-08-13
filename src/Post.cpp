#include "curlpp/Easy.hpp"
#include "curlpp/Exception.hpp"
#include "curlpp/Options.hpp"
#include "json.hpp"
#include <sstream>
#include <string>
int main() {
  try {
    curlpp::Easy handler;
    std::string url = "https://fakestoreapi.com/products";

    nlohmann::json post_data;
    post_data["title"] = "test product";
    post_data["price"] = 13.5;
    post_data["description"] = "lorem ipsum set";
    post_data["image"] = "https://i.pravatar.cc";
    post_data["category"] = "electronic";

    std::list<std::string> headers = {"Content-Type: application/json"};
    std::stringstream response;

    handler.setOpt(new curlpp::options::Url(url));
    handler.setOpt((new curlpp::options::Post(true)));
    handler.setOpt(new curlpp::options::HttpHeader(headers));
    handler.setOpt(new curlpp::options::PostFields(post_data.dump()));
    handler.setOpt(new curlpp::options::PostFieldSize(post_data.dump().size()));
    handler.setOpt(new curlpp::options::WriteStream(&response));

    handler.perform();

    nlohmann::json responeJson = nlohmann::json::parse(response);
    std::cout << std::setw(2) << responeJson << std::endl;

  } catch (curlpp::RuntimeError &e) {

  } catch (curlpp::LogicError &e) {
  }
}
