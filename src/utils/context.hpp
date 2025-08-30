#pragma once
#include <unordered_map>
#include <string>


class Context {
private:
    std::unordered_map<std::string, std::string> m_table;
public:
    void set(const std::string& key, const std::string& value) {
        m_table[key] = value;
    }
    std::string get(const std::string& key) const {
        return m_table.at(key);
    }
};