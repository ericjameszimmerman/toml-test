#include <string>
#include <iostream>

#define TOML_EXCEPTIONS 0
#include "toml.hpp"

int main() {
    // Path to the TOML file
    std::string tomlFilePath = "config.toml";

    // Parse the TOML file
    auto result = toml::parse_file(tomlFilePath);

    // Check if parsing was successful
    if (!result) {
        std::cerr << "Failed to parse file: " << tomlFilePath << "\n";
        std::cerr << "Error: " << result.error() << "\n";
        return 1;
    }

    // Get the parsed TOML table
    const auto& data = result.table();

    // Access values
    std::string_view title = data["title"].value_or("Unknown Title");
    std::cout << "Title: " << title << "\n";

    // Access nested values
    auto owner = data["owner"];
    std::string_view name = owner["name"].value_or("Unknown");
    std::cout << "Owner Name: " << name << "\n";

    return 0;
}
