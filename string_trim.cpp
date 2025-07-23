std::string trim(const std::string& s)
{
    auto first = s.find_first_not_of(" \f\n\r\t\v");
    auto last = s.find_last_not_of(" \f\n\r\t\v");
    return (first == s.npos) ? "" : s.substr(first, last + 1);
}