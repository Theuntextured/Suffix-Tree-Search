#include <iostream>
#include "SearchTree.h"


int main()
{
    std::vector<std::string> words = { "death", "rode", "high-pitched", "rabbits", "impartial", "hissing", "lowly", "highfalutin", "spot", "cats", "attraction", "groan", "profit", "spicy", "selective", "taboo", "knotty", "nondescript", "replace", "fierce", "knee", "oven", "ants", "puzzling", "drop", "nebulous", "precious", "maniacal", "toes", "tested", "sock", "metal", "scene", "parsimonious", "teaching", "inform", "flash", "blood", "acceptable", "needy", "cynical", "pause", "edge", "mountain", "coat", "head", "tumble", "faint", "icicle", "orange", "shade", "offend", "tour", "quizzical", "fog", "coach", "lewd", "great", "strange", "diligent", "odd", "zany", "fruit", "apparatus", "green", "nappy", "exotic", "bad", "wiry", "round", "pest", "stroke", "step", "silent", "medical", "vessel", "wacky", "wild", "oceanic", "righteous", "grandfather", "balance", "wonderful", "lunch", "discover", "spring", "bustling", "old", "lamp", "wandering", "sweltering", "abnormal", "admire", "wreck", "exciting", "children", "creature", "fertile", "crown", "statement" };
    SearchTree s;
    s.generateTree(words, {' ', '-'});
    std::string toSearch;

    printf("Suffix tree has been built.");

    while (true) {
        std::cout << "\n\nEnter the substring to search for: ";
        std::getline(std::cin, toSearch);
        auto out = s.Search(toSearch);
        for (auto o : out) std::cout << o << std::endl;
    }

}
