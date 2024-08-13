## Demo of curlpp(wrapper for curl)

## Installing library
Since curlpp is wrapper around it is required to have curl installed first. 
Also nlohmann/json is used for parsing json

### Installing curl library
1. Download the source file from curl's [download page](https://curl.se/download.html).
2. Extract the source file
3. use the `configure` script provided within the curl source files to configure with the path you want within
   your project to install the library: 
    ```sh
    ./configure --with-openssl --prefix=<CURL_INSATALLATION_PATH_INSIDE_PROJECT>
    ```
4. install with: 
   ```bash
   make
   make install
   ``` 

### Installing curlpp
1. Download the library from [releases](https://github.com/jpbarrette/curlpp/releases/tag/v0.8.1)
2. Extract the source
3. prepare for install with: 
    ```bash
    cmake -D CMAKE_INSTALL_PREFIX=<CURLPP_INSTALLAITION_DIR_INSIDE_PROJECT> -D CURL_LIBRARY=<CURL_INSATALLATION_PATH_INSIDE_PROJECT>/lib/libcurl.a -D CURL_INCLUDE_DIR=<CURL_INSATALLATION_PATH_INSIDE_PROJECT>/include
    ```
4. `make install`

### Installing nlohmann/json
1. Installing nlohmann/json is simple just copy [json.hpp](https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp) somewhere and include it.

