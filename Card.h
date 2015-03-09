#pragma once
class Card
{
public:
	enum Suit { Spades, Clubs, Diamonds, Hearts };
	enum Rank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

	Suit suit;
	Rank rank;

	Card();
	Card(Suit suit, Rank rank);
	static const char * suitToStr(int index);
	static const char * rankToStr(int index);
	~Card();

private:
	static const char * suitStr[4];
	static const char * rankStr[13];
};

