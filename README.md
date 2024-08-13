## Demo of curlpp(wrapper for curl)
curlpp template setup

## Installing library
Since curlpp is wrapper around curl, it is required to have curl installed first. 
Also nlohmann/json is used for parsing json

#### Library installation structure
expected library installation strucutre in this project
---democurlpp
    |__ src
    |__ libs
        |__ curl
            |__ include
            |__ lib
        |__ curlpp
            |__ include
            |__ lib64
        |__ nlohmann
            |__ json.hpp

### Installing curl library
1. Download the source file from curl's [download page](https://curl.se/download.html).
2. use the `configure` script provided within the curl source files to configure with the path you want within
   your project to install the library: 
    ```sh
    ./configure --with-openssl --prefix=<CURL_INSATALLATION_PATH_INSIDE_PROJECT>
    ```
3. install with: 
   ```bash
   make
   make install
   ``` 

### Installing curlpp
1. Download the library from [releases](https://github.com/jpbarrette/curlpp/releases/tag/v0.8.1)
2. prepare for install with: 
    ```bash
    cmake -D CMAKE_INSTALL_PREFIX=<CURLPP_INSTALLAITION_DIR_INSIDE_PROJECT> -D CURL_LIBRARY=<CURL_INSATALLATION_PATH_INSIDE_PROJECT>/lib/libcurl.a -D CURL_INCLUDE_DIR=<CURL_INSATALLATION_PATH_INSIDE_PROJECT>/include
    ```
3. `make install`

### Installing nlohmann/json
1. Installing nlohmann/json is simple just copy [json.hpp](https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp) somewhere and include it.

