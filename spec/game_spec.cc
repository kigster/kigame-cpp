
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-interfaces-global-init"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <iostream>

#include <ccspec/core.h>
#include <ccspec/expectation.h>
#include <ccspec/matchers.h>

#include "../src/Game.h"

using std::cout;
using std::ostringstream;
using ccspec::core::Reporter;
using ccspec::core::after;
using ccspec::core::before;
using ccspec::core::describe;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::core::formatters::ProgressFormatter;
using ccspec::core::it;
using ccspec::matchers::be;
using ccspec::matchers::be_falsey;
using ccspec::matchers::be_truthy;
using ccspec::matchers::eq;
using ccspec::expect;

#include <vector>

Game *game;

auto game_spec = describe("Game", [] {
  describe("#new", [] {
    it("returns back the instance", [] {
      Board board;
      Player player1, player2;
      std::vector<Player *> players;
      players.resize(2);
      players[0] = &player1;
      players[1] = &player2;
      Game game1 = Game(board, players);
      Game game2 = Game(board, players);
      expect(&game1.getBoard()).notTo(eq(&game2.getBoard()));
    });
  });
});

int main() {
  ProgressFormatter formatter(cout);
  Reporter reporter(&formatter);
  bool succeeded = game_spec->run(reporter);
  delete game_spec;
  return !succeeded;
}

#pragma clang diagnostic pop
