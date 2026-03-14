#include "Deck.h"
#include "Dragon.h"
#include "Enemies.h"
#include "Exceptions.h"
#include "Fighter.h"
#include "Ghost.h"
#include "Ranger.h"
#include "Sorcerer.h"
#include "Troll.h"
#include "Vector.h"
#include <iostream>
#include <string>
using namespace std;
using std::cin;
using std::cout;

// Calculates the sum of card values in a deck, applying suit-based multipliers.
int get_sum(const Deck &d, char neg) {
  int c_found = 0;
  int s_found = 0;
  int sum = 0;
  for (size_t i = 0; i < d.getmycards().size(); i++) {
    if (d.getmycards()[i].getsymbol() == 'C')
      c_found++;
    if (d.getmycards()[i].getsymbol() == 'S')
      s_found++;
    sum += d.getmycards()[i].getvalue();
  }
  if (s_found > 0 && c_found > 0 && neg != 'C')
    sum *= 2;
  return sum;
}

// Validates if the deck forms a legal set according to game rules.
bool isValidSetDeck(const Deck &d) {
  int n = d.get_total();
  if (n == 0)
    return false;

  int ace_index = -1;
  if (n > 1) {
    for (int i = 0; i < n; ++i) {
      if (d[i].getvalue() == 1) {
        ace_index = i;
        break;
      }
    }
  }

  int effective_n = (ace_index != -1) ? n - 1 : n;
  if (effective_n == 1)
    return true;

  int first_idx = 0;
  if (ace_index == 0)
    first_idx = 1;
  int first_val = d[first_idx].getvalue();
  if (first_val < 2 || first_val > 5)
    return false;

  int sum = 0;
  for (int i = 0, idx = 0; i < n && idx < effective_n; ++i) {
    if (i == ace_index)
      continue;
    if (d[i].getvalue() != first_val)
      return false;
    sum += d[i].getvalue();
    idx++;
  }
  return sum <= 10;
}

// Checks if a string represents a valid card.
bool is_valid_card(const std::string &s) {
  if (s.size() < 2)
    return false;
  const std::string ranks = "A23456789TJQK";
  const std::string suits = "CDHS";
  if (ranks.find(s[0]) == std::string::npos)
    return false;
  if (suits.find(s[1]) == std::string::npos)
    return false;
  return true;
}

// Main game loop: initializes deck, manages player/enemy turns, and processes
// card sets.

// Helper: Initialize the deck from user input
void initialize_deck(Deck &deck) {
  cout << "Initialize deck" << endl;
  string token;
  while (cin >> token && token != "00") {
    if (!is_valid_card(token))
      continue;
    try {
      deck += Card(token[0], token[1]);
    } catch (exception &e) {
      cout << e.what() << endl;
    }
  }
}

// Helper: Character selection and initialization
void select_characters(Characters *&player, Enemies *&enemy,
                       size_t &max_in_hand, char &neg) {
  cout << "Choose player character:\n(1) Fighter (2) Sorcerer (3) Ranger"
       << endl;
  int p_choice;
  cin >> p_choice;
  cout << "Choose enemy character:\n(1) Troll (2) Ghost (3) Dragon" << endl;
  int e_choice;
  cin >> e_choice;

  switch (p_choice) {
  case 1:
    player = new Fighter();
    max_in_hand = 6;
    break;
  case 2:
    player = new Sorcerer();
    max_in_hand = 8;
    break;
  case 3:
    player = new Ranger();
    max_in_hand = 7;
    break;
  }
  switch (e_choice) {
  case 1:
    enemy = new Troll();
    break;
  case 2:
    enemy = new Ghost();
    break;
  case 3:
    enemy = new Dragon();
    break;
  }

  if ((p_choice == 1 && e_choice == 1) || (p_choice == 2 && e_choice == 2) ||
      (p_choice == 3 && e_choice == 3))
    neg = 'H';
  if ((p_choice == 2 && e_choice == 1) || (p_choice == 1 && e_choice == 3) ||
      (p_choice == 3 && e_choice == 2))
    neg = 'D';
  if ((p_choice == 1 && e_choice == 2) || (p_choice == 2 && e_choice == 3) ||
      (p_choice == 3 && e_choice == 1))
    neg = 'C';
}

// Helper: Deal initial hand
void deal_initial_hand(Deck &deck, Deck &hand, size_t max_in_hand) {
  for (size_t i = 0; i < max_in_hand; ++i) {
    if (deck.get_total() == 0)
      break;
    hand += deck[deck.get_total() - 1];
    deck -= 1;
  }
}

// Helper: Play a single turn, returns false if exit requested
bool play_turn(Characters *player, Enemies *enemy, Deck &deck, Deck &hand,
               size_t max_in_hand, char neg) {
  cout << "Player health: " << player->get_life_points() << "\n";
  cout << "Enemy health: " << enemy->get_life_points() << "\n";
  cout << "Player hand\n";
  for (int i = 0; i < hand.get_total(); ++i)
    cout << hand[i] << " ";
  cout << "\n";

  Deck table;
  // Input and validate card set to play
  while (true) {
    cout << "Insert card set to play" << endl;
    string line;
    if (!getline(cin >> ws, line) || line.empty()) {
      // If EOF or empty line, exit gracefully
      return false;
    }
    if (line == "exit")
      return false;

    table = Deck();
    int num_input = 0, num_true = 0;
    bool syntax_bad = false;
    for (size_t i = 0; i < line.size(); i += 3) {
      string tok = (i + 1 < line.size()) ? line.substr(i, 2) : string();
      ++num_input;
      if (!is_valid_card(tok)) {
        syntax_bad = true;
        continue;
      }
      if (hand.Islegal(tok, table)) {
        ++num_true;
        table += Card(tok[0], tok[1]);
      }
    }

    if (syntax_bad || num_input != num_true || !isValidSetDeck(table)) {
      cout << "Card set is not valid\n";
      continue;
    }

    break;
  }

  // Remove played cards from hand
  for (int i = 0; i < table.get_total(); ++i) {
    try {
      hand -= table[i];
    } catch (exception &e) {
      cout << e.what() << endl;
    }
  }

  int sum = get_sum(table, neg);
  cout << "Player dealt " << sum << " points of damage" << '\n';
  enemy->set_health(sum);
  if (enemy->get_life_points() == 0)
    return true;

  int counterH = 0, counterD = 0;
  for (int i = 0; i < table.get_total(); ++i) {
    if (table[i].getsymbol() == 'H')
      counterH = 1;
    if (table[i].getsymbol() == 'D')
      counterD = 1;
  }

  int damage = enemy->calc_damage(sum, counterD, neg);
  player->set_life_points(sum, damage, neg, counterH);
  cout << "Player took " << damage << " points of damage" << '\n';
  if (player->get_life_points() == 0)
    return true;

  // Draw cards from the deck if available
  if (deck.get_total() == 0) {
    // Deck is empty before drawing - check if hand is full
    if (hand.get_total() < (int)max_in_hand) {
      throw deck_out_ex();
    }
    return true;
  }
  if (hand.get_total() + 2 <= (int)max_in_hand) {
    hand += deck[deck.get_total() - 1];
    deck -= 1;
    if (deck.get_total() > 0) {
      hand += deck[deck.get_total() - 1];
      deck -= 1;
    }
  } else if (hand.get_total() + 1 <= (int)max_in_hand) {
    hand += deck[deck.get_total() - 1];
    deck -= 1;
  }

  // After drawing, check if deck ran out and hand is still not full
  if (deck.get_total() == 0 && hand.get_total() < (int)max_in_hand) {
    throw deck_out_ex();
  }

  return true;
}

int main() {
  Deck deck;
  initialize_deck(deck);

  Characters *player = nullptr;
  Enemies *enemy = nullptr;
  size_t max_in_hand = 0;
  char neg = 'C';
  select_characters(player, enemy, max_in_hand, neg);

  Deck hand;
  deal_initial_hand(deck, hand, max_in_hand);

  try {
    hand.IsRanOut((int)max_in_hand, hand.get_total());

    bool exitFlag = false;
    while (player->get_life_points() > 0 && enemy->get_life_points() > 0 &&
           !exitFlag) {
      bool turnResult = play_turn(player, enemy, deck, hand, max_in_hand, neg);
      if (!turnResult) {
        exitFlag = true;
        break;
      }
    }

    if (!exitFlag) {
      if (player->get_life_points() == 0)
        throw player_lose();
      else if (enemy->get_life_points() == 0)
        throw player_win();
      else if (deck.get_total() == 0) {
        hand.IsRanOut((int)max_in_hand, hand.get_total());
      }
    }
  } catch (Exceptions &e) {
    e.Handle();
  } catch (exception &e) {
    cout << e.what() << endl;
  }

  delete player;
  delete enemy;
  return 0;
}