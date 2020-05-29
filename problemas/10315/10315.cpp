/* 10315 - Poker Hands */

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define NCARDS 13
#define NCARDS_IN_HAND 5

#define HIGH_CARD 1
#define PAIR 2
#define TWO_PAIRS 3
#define THREE_OF_A_KIND 4
#define STRAIGHT 5
#define FLUSH 6
#define FULL_HOUSE 7
#define FOUR_OF_A_KIND 8
#define STRAIGHT_FLUSH 9

char values[] = "23456789TJQKA";

struct card
{
    char suit;
    int valueNum;
};

struct hand
{
    card cards[NCARDS_IN_HAND];
    int partialOrder = 0;
    int tieValues[NCARDS_IN_HAND];
};

int rankHandByHighCardRule(hand *black, hand *white)
{
    for (int i = NCARDS_IN_HAND - 1; i >= 0; i--)
        if (black->cards[i].valueNum != white->cards[i].valueNum)
            return black->cards[i].valueNum - white->cards[i].valueNum;

    return 0;
}

int rankHandWithTieValues(hand *black, hand *white, int maxIndex)
{
    for (int i = 0; i < maxIndex; i++)
        if (black->tieValues[i] != white->tieValues[i])
            return black->tieValues[i] - white->tieValues[i];

    return 0;
}

/* ######################### Pairs ######################### */

bool fillPairValues(hand *h, int valuePair, int value1, int value2, int value3)
{
    h->tieValues[0] = valuePair;
    h->tieValues[1] = value1;
    h->tieValues[2] = value2;
    h->tieValues[3] = value3;
    return true;
}

bool isPair(hand *h)
{
    if (h->cards[0].valueNum == h->cards[1].valueNum)
        if (h->cards[2].valueNum != h->cards[3].valueNum)
            if (h->cards[3].valueNum != h->cards[4].valueNum)
                return fillPairValues(h, h->cards[0].valueNum, h->cards[4].valueNum, h->cards[3].valueNum, h->cards[2].valueNum);

    if (h->cards[1].valueNum == h->cards[2].valueNum)
        if (h->cards[0].valueNum != h->cards[3].valueNum)
            if (h->cards[3].valueNum != h->cards[4].valueNum)
                return fillPairValues(h, h->cards[1].valueNum, h->cards[4].valueNum, h->cards[3].valueNum, h->cards[0].valueNum);

    if (h->cards[2].valueNum == h->cards[3].valueNum)
        if (h->cards[0].valueNum != h->cards[1].valueNum)
            if (h->cards[1].valueNum != h->cards[4].valueNum)
                return fillPairValues(h, h->cards[2].valueNum, h->cards[4].valueNum, h->cards[1].valueNum, h->cards[0].valueNum);

    if (h->cards[3].valueNum == h->cards[4].valueNum)
        if (h->cards[0].valueNum != h->cards[1].valueNum)
            if (h->cards[1].valueNum != h->cards[2].valueNum)
                return fillPairValues(h, h->cards[3].valueNum, h->cards[2].valueNum, h->cards[1].valueNum, h->cards[0].valueNum);

    return false;
}

/* ######################### Two Pairs ######################### */

bool fillTwoPairValues(hand *hand, int valueFirstPair, int valueSecondPair, int remainingValue)
{
    hand->tieValues[0] = max(valueFirstPair, valueSecondPair);
    hand->tieValues[1] = min(valueFirstPair, valueSecondPair);
    hand->tieValues[2] = remainingValue;
    return true;
}

bool isTwoPairs(hand *h)
{
    if (h->cards[0].valueNum == h->cards[1].valueNum)
        if (h->cards[2].valueNum == h->cards[3].valueNum)
            if (h->cards[0].valueNum != h->cards[2].valueNum)
                return fillTwoPairValues(h, h->cards[0].valueNum, h->cards[2].valueNum, h->cards[4].valueNum);

    if (h->cards[0].valueNum == h->cards[1].valueNum)
        if (h->cards[3].valueNum == h->cards[4].valueNum)
            if (h->cards[0].valueNum != h->cards[3].valueNum)
                return fillTwoPairValues(h, h->cards[0].valueNum, h->cards[3].valueNum, h->cards[2].valueNum);

    if (h->cards[1].valueNum == h->cards[2].valueNum)
        if (h->cards[3].valueNum == h->cards[4].valueNum)
            if (h->cards[1].valueNum != h->cards[3].valueNum)
                return fillTwoPairValues(h, h->cards[1].valueNum, h->cards[3].valueNum, h->cards[0].valueNum);

    return false;
}

/* ######################### Others ######################### */

bool isAnyOfAKind(hand *hand, int number)
{
    int count = 1;

    for (int i = 0; i < NCARDS_IN_HAND - 1; i++)
    {
        if (hand->cards[i].valueNum == hand->cards[i + 1].valueNum)
            count++;
        else
            count = 1;

        if (count == number)
        {
            hand->tieValues[0] = hand->cards[i].valueNum;
            return true;
        }
    }

    return false;
}

bool isThreeOfAKind(hand *hand)
{
    return isAnyOfAKind(hand, 3);
}

bool isStraight(hand *hand)
{
    for (int i = 0; i < NCARDS_IN_HAND - 1; i++)
        if (hand->cards[i].valueNum + 1 != hand->cards[i + 1].valueNum)
            return false;
    
    hand->tieValues[0] = hand->cards[4].valueNum;
    return true;
}

bool isFlush(hand *hand)
{
    for (int i = 0; i < NCARDS_IN_HAND - 1; i++)
        if (hand->cards[i].suit != hand->cards[i + 1].suit)
            return false;
    
    return true;
}

bool isFullHouse(hand *hand)
{
    if (hand->cards[0].valueNum == hand->cards[1].valueNum && hand->cards[1].valueNum == hand->cards[2].valueNum)
        if (hand->cards[3].valueNum == hand->cards[4].valueNum)
        {
            hand->tieValues[0] = hand->cards[0].valueNum;
            return true;
        }

    if (hand->cards[2].valueNum == hand->cards[3].valueNum && hand->cards[3].valueNum == hand->cards[4].valueNum)
        if (hand->cards[0].valueNum == hand->cards[1].valueNum)
        {
            hand->tieValues[0] = hand->cards[2].valueNum;
            return true;
        }

    return false;
}

bool isFourOfAKind(hand *hand)
{
    return isAnyOfAKind(hand, 4);
}

bool isStraightFlush(hand *hand)
{
    if (!isStraight(hand) || !isFlush(hand))
        return false;

    hand->tieValues[0] = hand->cards[4].valueNum;
    return true;
}

int handlePartialOrder(hand *black, hand *white, int partialOrder)
{
    if (partialOrder == FLUSH || partialOrder == HIGH_CARD)
        return rankHandByHighCardRule(black, white);

    if (partialOrder == TWO_PAIRS)
        return rankHandWithTieValues(black, white, 3);

    if (partialOrder == PAIR)
        return rankHandWithTieValues(black, white, 4);

    return rankHandWithTieValues(black, white, 1);
}

void compareHands(hand *black, hand *white)
{
    int result = handlePartialOrder(black, white, black->partialOrder);

    if (result > 0)
        printf("Black wins.\n");
    else if (result < 0)
        printf("White wins.\n");
    else
        printf("Tie.\n");
}

int cardCompare(const void *a, const void *b)
{
    return ((card *)a)->valueNum - ((card *)b)->valueNum;
}

void computePartialOrder(hand *hand)
{
    qsort(hand->cards, NCARDS_IN_HAND, sizeof(card), cardCompare);

    if (isStraightFlush(hand))
        hand->partialOrder = STRAIGHT_FLUSH;
    else if (isFourOfAKind(hand))
        hand->partialOrder = FOUR_OF_A_KIND;
    else if (isFullHouse(hand))
        hand->partialOrder = FULL_HOUSE;
    else if (isFlush(hand))
        hand->partialOrder = FLUSH;
    else if (isStraight(hand))
        hand->partialOrder = STRAIGHT;
    else if (isThreeOfAKind(hand))
        hand->partialOrder = THREE_OF_A_KIND;
    else if (isTwoPairs(hand))
        hand->partialOrder = TWO_PAIRS;
    else if (isPair(hand))
        hand->partialOrder = PAIR;
    else
        hand->partialOrder = HIGH_CARD;
}

int toIntFromValueCard(char value)
{
    for (int i = 0; i < NCARDS; i++)
        if (values[i] == value)
            return i + 2;

    return -1;
}

bool readInput(hand *black, hand *white)
{
    char input[3];

    for (int i = 0; i < 5; i++)
    {
        if (scanf("%s", input) == EOF)
            return false;

        black->cards[i].valueNum = toIntFromValueCard(input[0]);
        black->cards[i].suit = input[1];
    }

    for (int i = 0; i < 5; i++)
    {
        scanf("%s", input);
        white->cards[i].valueNum = toIntFromValueCard(input[0]);
        white->cards[i].suit = input[1];
    }

    return true;
}

int main()
{
    while (true)
    {
        hand black, white;

        if (!readInput(&black, &white))
            return 0;

        computePartialOrder(&black);
        computePartialOrder(&white);

        if (black.partialOrder > white.partialOrder)
            printf("Black wins.\n");
        else if (black.partialOrder < white.partialOrder)
            printf("White wins.\n");
        else
            compareHands(&black, &white);
    }

    return 0;
}
