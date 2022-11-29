//
// Created by Gabriel on 29/11/2022.
//

#include "../headers/fileNotFoundError.h++"

fileNotFoundError::fileNotFoundError(const std::string &whatArg, std::error_code ec) : filesystem_error(whatArg, ec) {}

const char *fileNotFoundError::what() const noexcept {
    return "File Not found.";
}
