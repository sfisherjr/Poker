//
// Created by steve on 1/24/19.
//

#ifndef POKER_HANDEVALUATION_H
#define POKER_HANDEVALUATION_H

#include <memory>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include "Card.h"

class HandEvaluation
{
public:
    enum Result
    {
        five_of_kind,
        straight_flush,
        four_of_kind,
        full_house,
        flush,
        straight,
        three_of_kind,
        two_pair,
        one_pair,
        high_card
    };

    explicit HandEvaluation(const std::vector<Card*> &hand);

    ~HandEvaluation() = default;

    Result evaluate_hand();

    Card* get_high_card();

    std::string result_str(Result res);

private:
    std::vector<Card*> hand;

    std::map<int, int> hand_occurrences;

    static inline bool sort_func(const Card *i, const Card *j)
    { return i->value < j->value; }

    /**
     * Creates an std::map with the key being the card value
     * and the value being the number of occurrences of that card
     * value.
     * @return Map of occurrences
     */
    std::map<int, int> map_hand_occurrences();

    bool is_five_of_kind();

    bool is_straight_flush();

    bool is_four_of_kind();

    bool is_full_house();

    bool is_flush();

    bool is_straight();

    bool is_three_of_kind();

    bool is_two_pair();

    bool is_one_pair();
};


#endif //POKER_HANDEVALUATION_H
