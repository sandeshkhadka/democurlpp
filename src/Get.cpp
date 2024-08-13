#include "curlpp/Exception.hpp"
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <json.hpp>
#include <sstream>
using json = nlohmann::json;

int main(int argc, char **argv) {
  std::string url = "https://fakestoreapi.com/products";
  // if (argc == 2) {
  //   url = argv[1];
  // } else {
  //   url = "https://fakestoreapi.com/products";
  // }
  try {
    std::stringstream response;
    curlpp::Cleanup cleaner;
    curlpp::Easy handler;
    handler.setOpt(new curlpp::options::Url(url));
    handler.setOpt(new curlpp::options::WriteStream(&response));

    handler.perform();
    auto parsed = json::parse(response);

    std::cout << std::setw(2) << parsed << std::endl;
  } catch (curlpp::RuntimeError &e) {

  } catch (curlpp::LogicError &e) {
  }
}
