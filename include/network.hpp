#pragma once
#include <map>

#include <jansson.h>

#include <common.hpp>


namespace rack {


/** Networking functions for HTTP requests, URLs, and downloads
*/
namespace network {


typedef std::map<std::string, std::string> CookieMap;

enum Method {
	METHOD_GET,
	METHOD_POST,
	METHOD_PUT,
	METHOD_DELETE,
};

void init();
/** Requests a JSON API URL over HTTP(S), using the data as the query (GET) or the body (POST, etc)
Caller must json_decref().
*/
json_t* requestJson(Method method, const std::string& url, json_t* dataJ, const CookieMap& cookies = {});
/** Returns true if downloaded successfully */
bool requestDownload(const std::string& url, const std::string& filename, float* progress, const CookieMap& cookies = {});
/** URL-encodes `s` */
std::string encodeUrl(const std::string& s);
/** Gets the path portion of the URL. */
std::string urlPath(const std::string& url);


} // namespace network
} // namespace rack
