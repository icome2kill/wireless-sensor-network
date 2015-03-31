namespace wsn_energy {
class LZWHelper {
public:
    template<typename Iterator>
    static Iterator compress(const std::string &uncompressed, Iterator result);
    template<typename Iterator>
    static std::string decompress(Iterator begin, Iterator end);
};
}
