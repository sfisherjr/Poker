//
// Created by steve on 1/24/19.
//

#include "HandEvaluation.h"

HandEvaluation::HandEvaluation(const std::vector<Card*> &hand)
    : hand(hand)
{
    // Sort the hand lowest to highest value
    std::sort(this->hand.begin(), this->hand.end(), sort_func);

    hand_occurrences = map_hand_occurrences();
}

HandEvaluation::Result HandEvaluation::evaluate_hand()
{
    if (is_five_of_kind()) return Result::five_of_kind;
    if (is_straight_flush()) return Result::straight_flush;
    if (is_four_of_kind()) return Result::four_of_kind;
    if (is_full_house()) return Result::full_house;
    if (is_flush()) return Result::flush;
    if (is_straight()) return Result::straight;
    if (is_three_of_kind()) return Result::three_of_kind;
    if (is_two_pair()) return Result::two_pair;
    if (is_one_pair()) return Result::one_pair;

    return Result::high_card;
}

Card* HandEvaluation::get_high_card()
{
    return hand.back();
}

std::string HandEvaluation::result_str(HandEvaluation::Result res)
{
    switch (res)
    {
        case Result::five_of_kind: return "Five of a Kind";
        case Result::straight_flush: return "Straight Flush";
        case Result::four_of_kind: return "Four of a Kind";
        case Result::full_house: return "Full House";
        case Result::flush: return "Flush";
        case Result::straight: return "Straight";
        case Result::three_of_kind: return "Three of a Kind";
        case Result::two_pair: return "Two Pair";
        case Result::one_pair: return "One Pair";
        default: return "High Card";
    }
}

std::map<int, int> HandEvaluation::map_hand_occurrences()
{
    // key = cardValue, value = number of occurrences
    std::map<int, int> values;

    for (auto const& card : hand)
    {
        auto search = values.find(card->value);
        if (search != values.end())
            ++values[search->first];
        else
            values[card->value] = 1;
    }

    for (auto const& x : values)
    {
        std::cout << x.first
                  << ':'
                  << x.second
                  << std::endl;
    }

    return values;
}

bool HandEvaluation::is_five_of_kind()
{
    for (auto const& card_value : hand_occurrences)
    {
        if (card_value.second == 5)
            return true;
    }

    return false;
}

bool HandEvaluation::is_straight_flush()
{
    return is_flush() && is_straight();
}

bool HandEvaluation::is_four_of_kind()
{
    for (auto const& card_value : hand_occurrences)
    {
        if (card_value.second == 4)
            return true;
    }

    return false;
}

bool HandEvaluation::is_full_house()
{
    bool found_two = false;
    bool found_three = false;

    for (auto const& card_value : hand_occurrences)
    {
        if (!found_two && card_value.second == 2)
            found_two = true;

        if (!found_three && card_value.second == 3)
            found_three = true;
    }

    return found_two && found_three;
}

bool HandEvaluation::is_flush()
{
    Card::Suit first_card_suit = hand.front()->suit;

    for (auto const& card : hand)
    {
        if (card->suit != first_card_suit)
            return false;
    }

    return true;
}

bool HandEvaluation::is_straight()
{
    int req_next_val = hand.front()->value + 1;

    for (int i = 1; i < hand.size() - 1; ++i)
    {
        if (hand[i]->value != req_next_val)
            return false;

        hand.front()->value += 1;
    }

    return true;
}

bool HandEvaluation::is_three_of_kind()
{
    for (auto const& card_value : hand_occurrences)
    {
        if (card_value.second == 3)
            return true;
    }

    return false;
}

bool HandEvaluation::is_two_pair()
{
    int count = 0;

    for (auto const& card_value : hand_occurrences)
    {
        if (card_value.second == 2)
            ++count;

        if (count == 2) return true;
    }

    return false;
}

bool HandEvaluation::is_one_pair()
{
    for (auto const& card_value : hand_occurrences)
    {
        if (card_value.second == 2)
            return true;
    }

    return false;
}