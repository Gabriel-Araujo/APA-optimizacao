//
// Created by Gabriel on 29/11/2022.
//

#ifndef APA_FILENOTFOUNDERROR_H
#define APA_FILENOTFOUNDERROR_H

#include <filesystem>

class fileNotFoundError: public std::filesystem::filesystem_error {
public:
    fileNotFoundError(const std::string &whatArg, std::error_code ec);
    const char * what() const noexcept override;
};


#endif //APA_FILENOTFOUNDERROR_H
