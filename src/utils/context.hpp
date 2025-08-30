#pragma once
#include <string>
#include <unordered_map>

#include "../entity/local_user.hpp"

class Context {
private:
    std::unordered_map<std::string, std::string> m_table;
    LocalUser m_local_user;

public:
    void set(const std::string& key, const std::string& value) { m_table[key] = value; }
    std::string get(const std::string& key) const { return m_table.at(key); }

    LocalUser& local_user() { return m_local_user; }
    const LocalUser& local_user() const { return m_local_user; }
};