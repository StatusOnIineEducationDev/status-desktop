#pragma once
#include <iostream>
#include <string>

static bool is_base64(const char c);
std::string base64_encode(const char * bytes_to_encode, unsigned int in_len);
std::string base64_decode(std::string const & encoded_string);