//
// Created by steve on 1/24/19.
//

#include "HandEvaluation.h"

HandEvaluation::HandEvaluation(const std::vector<Card*> &hand)
    : hand(hand)
{
    // Sort the hand lowest to highest value
    std::sort(this->hand.begin(), this->hand.end(), sort_func);
}

HandEvaluation::Result HandEvaluation::evaluate_hand()
{
    if (is_five_of_kind()) return Result::five_of_kind;
    if (is_straight_flush()) return Result::straight_flush;
    if (is_flush()) return Result::flush;
    if (is_straight()) return Result::straight;

    return Result::high_card;
}

Card* HandEvaluation::get_high_card()
{
    return hand.back();
}

bool HandEvaluation::is_five_of_kind()
{
    int first_card_value = hand.front()->value;

    for (auto card : hand)
    {
        if (card->value != first_card_value)
            return false;
    }

    return true;
}

bool HandEvaluation::is_straight_flush()
{
    return is_flush() && is_straight();
}

bool HandEvaluation::is_four_of_kind()
{
    // TODO: Implement
    return false;
}

bool HandEvaluation::is_full_house()
{
    // TODO: Implement
    return false;
}

bool HandEvaluation::is_flush()
{
    Card::Suit first_card_suit = hand.front()->suit;

    for (auto card : hand)
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
    // TODO: Implement
    return false;
}

bool HandEvaluation::is_two_pair()
{
    // TODO: Implement
    return false;
}

bool HandEvaluation::is_one_pair()
{
    // TODO: Implement
    return false;
}