namespace wsn_energy {
class LZWHelper {
public:
    template<typename Iterator>
    static Iterator compress(const std::string &uncompressed, Iterator result) {
        // Build the dictionary.
        std::map<std::string, int> dictionary;
        int dictSize = 128;
        for (int i = 0; i < 128; i++)
            dictionary[std::string(1, i)] = i;

//    int i = 0;
//    for (; i < 10; i++)
//        dictionary[std::string(1, i + '0')] = i;
//    dictionary[std::string(1, ',')] = i++;
//    dictionary[std::string(1, '/')] = i++;
//    dictionary[std::string(1, '|')] = i++;
//    int dictSize = i;

        std::string w;
        for (std::string::const_iterator it = uncompressed.begin();
                it != uncompressed.end(); ++it) {
            char c = *it;
            std::string wc = w + c;
            if (dictionary.count(wc))
                w = wc;
            else {
                *result++ = dictionary[w];
                // Add wc to the dictionary.
                dictionary[wc] = dictSize++;
                w = std::string(1, c);
            }
        }

        // Output the code for w.
        if (!w.empty())
            *result++ = dictionary[w];
        return result;
    }

// Decompress a list of output ks to a string.
// "begin" and "end" must form a valid range of ints
    template<typename Iterator>
    static std::string decompress(Iterator begin, Iterator end) {
        // Build the dictionary.
        std::cout << "Decompress" << std::endl;
        std::map<int, std::string> dictionary;
        int dictSize = 128;
        for (int i = 0; i < 128; i++)
            dictionary[i] = std::string(1, i);

//    int i = 0;
//    for (; i < 10; i++)
//        dictionary[i] = std::string(1, i + '0');
//    dictionary[i++] = std::string(1, ',');
//    dictionary[i++] = std::string(1, '/');
//    dictionary[i++] = std::string(1, '|');
//    int dictSize = i;

        std::string w(1, *begin++);
        std::string result = w;
        std::string entry;
        for (; begin != end; begin++) {
            int k = *begin;
            if (dictionary.count(k))
                entry = dictionary[k];
            else if (k == dictSize)
                entry = w + w[0];
            else
                throw "Bad compressed k";

            result += entry;

            // Add w+entry[0] to the dictionary.
            dictionary[dictSize++] = w + entry[0];

            w = entry;
        }
        return result;
    }

//#include <iostream>
//#include <iterator>
//#include <vector>
//#include <sstream>
//
//int main() {
////    std::vector<int> compressed;
//    std::vector<unsigned char> compressed;
//    compress("1/10000,4500|2/10000,4600|3/10000,4700|4/10000,75,5000",
//            std::back_inserter(compressed));
//
//    std::stringstream result;
//    copy(compressed.begin(), compressed.end(),
//            std::ostream_iterator<int>(result, ""));
//    copy(compressed.begin(), compressed.end(),
//            std::ostream_iterator<int>(std::cout, ", "));
////    std::cout << result.str();
////    result.str().begin();
//    std::vector<int> charVector;
//    for (int i = 0; i < result.str().size(); i++) {
//        charVector.push_back(result.str().at(i));
//    }
//    std::string decompressed = decompress(compressed.begin(), compressed.end());
//    std::cout << decompressed << std::endl;
//
//    return 0;
//}
};
}
